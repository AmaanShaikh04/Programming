#include <stdio.h>

#define MAX 10

int processes[MAX];
int status[MAX];
int num_processes;

void initiate_election(int initiator) {
    printf("\nProcess %d initiated an election.\n", initiator);
    int highest = initiator;
    int response = 0;

    for (int i = initiator + 1; i < num_processes; i++) {
        if (status[i] == 1) {
            printf("Process %d sends election message to Process %d.\n", initiator, i);
            response = 1;
            highest = i;
        }
    }
    
    if (response == 0) {
        printf("Process %d becomes the coordinator.\n", initiator);
    } else {
        initiate_election(highest);
    }
}

void initialize_processes() {
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    
    for (int i = 0; i < num_processes; i++) {
        processes[i] = i;
        status[i] = 1; 
    }
}

void set_failed_processes() {
    int failed;
    printf("Enter number of failed processes: ");
    scanf("%d", &failed);
    
    for (int i = 0; i < failed; i++) {
        int fail_id;
        printf("Enter failed process ID: ");
        scanf("%d", &fail_id);
        if (fail_id >= 0 && fail_id < num_processes) {
            status[fail_id] = 0;
        } else {
            printf("Invalid process ID.\n");
        }
    }
}

void start_election() {
    int initiator;
    printf("Enter initiator process ID: ");
    scanf("%d", &initiator);
    
    if (initiator >= 0 && initiator < num_processes) {
        if (status[initiator] == 0) {
            printf("Initiator process is inactive. Choose an active process.\n");
        } else {
            initiate_election(initiator);
        }
    } else {
        printf("Invalid process ID.\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\nBully Election Algorithm Menu\n");
        printf("1. Initialize Processes\n");
        printf("2. Set Failed Processes\n");
        printf("3. Start Election\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                initialize_processes();
                break;
            case 2:
                set_failed_processes();
                break;
            case 3:
                start_election();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

