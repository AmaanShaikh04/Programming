import subprocess
import os
import logging
from datetime import datetime

# ------------------- CONFIGURATION -------------------
PRIMARY_SOURCE = "C:/Users/amaan/documents"
PRIMARY_BACKUP_REPO = "I:/PrimaryBackupRepo"
SECONDARY_BACKUP_REPO = "I:/SecondaryBackupRepo"
RESTIC_PASSWORD = "123abc"
LOG_DIR_PRIMARY = "I:/backup_logs/primary"
LOG_DIR_SECONDARY = "I:/backup_logs/secondary"
RESTORE_TEMP_DIR_PRIMARY = "I:/PrimaryRestoreTemp"
RESTORE_TEMP_DIR_SECONDARY = "I:/SecondaryRestoreTemp"

# ------------------- SETUP LOGGING -------------------
os.makedirs(LOG_DIR_PRIMARY, exist_ok=True)
os.makedirs(LOG_DIR_SECONDARY, exist_ok=True)
os.makedirs(RESTORE_TEMP_DIR_PRIMARY, exist_ok=True)
os.makedirs(RESTORE_TEMP_DIR_SECONDARY, exist_ok=True)

def get_log_file_path(log_dir):
    timestamp = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
    return os.path.join(log_dir, f"backup_log_{timestamp}.txt")

PRIMARY_LOG_FILE = get_log_file_path(LOG_DIR_PRIMARY)
SECONDARY_LOG_FILE = get_log_file_path(LOG_DIR_SECONDARY)

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
primary_logger = logging.getLogger('PrimaryBackup')
secondary_logger = logging.getLogger('SecondaryBackup')
primary_handler = logging.FileHandler(PRIMARY_LOG_FILE)
secondary_handler = logging.FileHandler(SECONDARY_LOG_FILE)
primary_logger.addHandler(primary_handler)
secondary_logger.addHandler(secondary_handler)

# ------------------- RESTIC COMMAND RUNNER -------------------
def run_restic_command(command, repo, logger):
    env = os.environ.copy()
    env['RESTIC_REPOSITORY'] = repo
    env['RESTIC_PASSWORD'] = RESTIC_PASSWORD
    try:
        result = subprocess.run(["restic"] + command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, env=env)
        logger.info(f"Command succeeded: {' '.join(command)}\n{result.stdout}")
        return result.stdout
    except subprocess.CalledProcessError as e:
        logger.error(f"Command failed: {' '.join(command)}\n{e.stderr}")
        return None

# ------------------- BACKUP FUNCTIONS -------------------
def initialize_repos():
    for repo, logger in [(PRIMARY_BACKUP_REPO, primary_logger), (SECONDARY_BACKUP_REPO, secondary_logger)]:
        if not os.path.exists(repo):
            logger.info(f"Initializing repository at {repo}...\n{'-'*50}")
            os.makedirs(repo, exist_ok=True)
            run_restic_command(["init"], repo, logger)
            logger.info(f"Repository initialized at {repo}.\n{'-'*50}")
        else:
            logger.info(f"Repository already exists at {repo}.\n{'-'*50}")

def backup_source():
    primary_logger.info("Starting primary backup...\n" + "-"*50)
    run_restic_command(["backup", PRIMARY_SOURCE], PRIMARY_BACKUP_REPO, primary_logger)
    run_restic_command(["snapshots"], PRIMARY_BACKUP_REPO, primary_logger)
    primary_logger.info("Primary backup and snapshot completed.\n" + "-"*50)

def backup_primary_to_secondary():
    secondary_logger.info("Starting secondary backup...\n" + "-"*50)
    run_restic_command(["backup", PRIMARY_SOURCE], SECONDARY_BACKUP_REPO, secondary_logger)
    run_restic_command(["snapshots"], SECONDARY_BACKUP_REPO, secondary_logger)
    secondary_logger.info("Secondary backup and snapshot completed.\n" + "-"*50)

# ------------------- FILE COMPARISON AND RECOVERY -------------------
def list_files_in_backup(repo, logger):
    output = run_restic_command(["ls", "latest"], repo, logger)
    files = set()
    if output:
        for line in output.splitlines():
            if line.startswith("/C/Users/amaan/documents") and not line.endswith("/"):
                files.add(line.strip())
    return files

def compare_backup_logs():
    print("\n" + "="*60)
    print("Comparing Backup Logs and Identifying Missing Files")
    print("="*60)
    
    primary_files = list_files_in_backup(PRIMARY_BACKUP_REPO, primary_logger)
    secondary_files = list_files_in_backup(SECONDARY_BACKUP_REPO, secondary_logger)

    diff_primary = primary_files - secondary_files
    diff_secondary = secondary_files - primary_files

    if diff_primary:
        print("\nFiles present in Primary but not in Secondary:")
        print("-"*50)
        for file in diff_primary:
            print(file)
        recover = input("\nDo you want to restore these files to the Secondary backup? (y/n): ")
        if recover.lower() == 'y':
            run_restic_command(["restore", "latest", "--target", RESTORE_TEMP_DIR_SECONDARY], PRIMARY_BACKUP_REPO, primary_logger)
            print("Files restored to Secondary backup.\n" + "-"*50)

    if diff_secondary:
        print("\nFiles present in Secondary but not in Primary:")
        print("-"*50)
        for file in diff_secondary:
            print(file)
        recover = input("\nDo you want to restore these files to the Primary backup? (y/n): ")
        if recover.lower() == 'y':
            run_restic_command(["restore", "latest", "--target", RESTORE_TEMP_DIR_PRIMARY], SECONDARY_BACKUP_REPO, secondary_logger)
            print("Files restored to Primary backup.\n" + "-"*50)

    if not diff_primary and not diff_secondary:
        print("Both backups are synchronized.\n" + "="*60)

# ------------------- MENU-DRIVEN MAIN -------------------
def main():
    initialize_repos()
    while True:
        print("\n" + "="*60)
        print("---- Backup Management Menu ----")
        print("="*60)
        print("1. Perform Primary Backup")
        print("2. Perform Secondary Backup")
        print("3. Compare Backup Logs and Restore")
        print("4. Exit")
        print("="*60)
        choice = input("Select an option (1-4): ")

        if choice == '1':
            backup_source()
        elif choice == '2':
            backup_primary_to_secondary()
        elif choice == '3':
            compare_backup_logs()
        elif choice == '4':
            print("Exiting\n" + "="*60)
            break
        else:
            print("Invalid option. Please try again.\n" + "-"*50)

if __name__ == "__main__":
    main()
