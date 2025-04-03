import pygame
import random
import sys
import math
from pygame import mixer
from pygame.locals import *

# Initialize pygame
pygame.init()
mixer.init()

# Screen dimensions
WIDTH, HEIGHT = 1024, 768
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Cyber Ransomware Defense")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 50, 50)
GREEN = (50, 255, 50)
BLUE = (50, 50, 255)
YELLOW = (255, 255, 50)
CYAN = (50, 255, 255)
PURPLE = (180, 50, 255)
ORANGE = (255, 150, 50)
PINK = (255, 50, 180)

# Game states
MENU = 0
PLAYING = 1
GAME_OVER = 2
INFO_SCREEN = 3
game_state = MENU

# Load assets
def load_image(name, scale=1):
    try:
        image = pygame.image.load(f"assets/{name}.png").convert_alpha()
        return pygame.transform.scale(image, (int(image.get_width() * scale), int(image.get_height() * scale)))
    except:
        # Create placeholder if image not found
        surf = pygame.Surface((50, 50), pygame.SRCALPHA)
        pygame.draw.rect(surf, (random.randint(50, 200), random.randint(50, 200), random.randint(50, 200)), (0, 0, 50, 50))
        pygame.draw.line(surf, BLACK, (0, 0), (50, 50), 2)
        pygame.draw.line(surf, BLACK, (50, 0), (0, 50), 2)
        return surf

# Try to load images, use placeholders if not found
player_img = load_image("player", 0.8)
bullet_img = load_image("bullet", 0.5)
background_img = load_image("background", 1.5)
explosion_imgs = [load_image(f"explosion_{i}", 0.7) for i in range(1, 6)]

# Player
player_size = 60
player_x = WIDTH // 2 - player_size // 2
player_y = HEIGHT - player_size - 50
player_speed = 8
player_health = 100

# Bullets
bullets = []
bullet_speed = 12
bullet_size = 20

# Enemies (Ransomware)
enemies = []
enemy_speed = 2.5
enemy_spawn_rate = 45  # frames
enemy_size = 100

# Particles
particles = []

# Game variables
score = 0
high_score = 0
level = 1
clock = pygame.time.Clock()
font_small = pygame.font.Font(None, 28)
font_medium = pygame.font.Font(None, 36)
font_large = pygame.font.Font(None, 72)
font_title = pygame.font.Font(None, 96)

# Ransomware database - 50+ types
ransomware_db = [
    {"name": "WannaCry", "color": RED, "year": 2017,
     "description": "WannaCry ransomware attack was a worldwide cyberattack that targeted Windows systems by encrypting data and demanding Bitcoin payments."},
     
    {"name": "NotPetya", "color": PURPLE, "year": 2017,
     "description": "Initially thought to be ransomware, NotPetya was actually a wiper malware disguised as ransomware, causing over $10 billion in damages."},
     
    {"name": "Ryuk", "color": YELLOW, "year": 2018,
     "description": "Targeted ransomware often used against large organizations, known for demanding high ransom payments (often in millions)."},
     
    {"name": "REvil", "color": GREEN, "year": 2019,
     "description": "Ransomware-as-a-service that uses double extortion - encrypting files and threatening to leak stolen data."},
     
    {"name": "LockBit", "color": BLUE, "year": 2020,
     "description": "Known for its fast encryption speed and ability to target both Windows and Linux systems."},
     
    {"name": "Conti", "color": CYAN, "year": 2020,
     "description": "Sophisticated ransomware operation that functioned like a business with HR departments."},
     
    {"name": "Maze", "color": ORANGE, "year": 2019,
     "description": "Pioneered the double extortion tactic of stealing data before encrypting files."},
     
    {"name": "DarkSide", "color": (100, 100, 100), "year": 2020,
     "description": "Gained notoriety for attacking Colonial Pipeline, causing fuel shortages in the US."},
     
    {"name": "CryptoLocker", "color": PINK, "year": 2013,
     "description": "One of the first modern ransomware strains that popularized Bitcoin payments for ransoms."},
     
    {"name": "TeslaCrypt", "color": (200, 50, 50), "year": 2015,
     "description": "Targeted primarily gamers by encrypting game save files and demanding ransom."},
     
    {"name": "BadRabbit", "color": (150, 75, 0), "year": 2017,
     "description": "Disguised as a Flash update, this ransomware spread through fake update mechanisms."},
     
    {"name": "SamSam", "color": (50, 150, 50), "year": 2015,
     "description": "Targeted healthcare and government systems, earning attackers over $6 million."},
     
    {"name": "GandCrab", "color": (180, 50, 180), "year": 2018,
     "description": "One of the first ransomware families to demand payment in DASH cryptocurrency."},
     
    {"name": "Crysis", "color": (50, 180, 180), "year": 2016,
     "description": "Spread through phishing emails and exploited weak RDP passwords."},
     
    {"name": "Cerber", "color": (180, 180, 50), "year": 2016,
     "description": "Operated as ransomware-as-a-service with a 40% cut going to developers."},
     
    {"name": "Petya", "color": PURPLE, "year": 2016,
     "description": "Encrypted entire hard drives by overwriting the master boot record."},
     
    {"name": "GoldenEye", "color": YELLOW, "year": 2016,
     "description": "Variant of Petya that spread through malicious email attachments."},
     
    {"name": "Jigsaw", "color": RED, "year": 2016,
     "description": "Deleted files incrementally until ransom was paid, with threats to delete more."},
     
    {"name": "Locky", "color": BLUE, "year": 2016,
     "description": "Spread through malicious Word documents with macros enabled."},
     
    {"name": "Spora", "color": GREEN, "year": 2017,
     "description": "Featured a professional-looking payment portal with different service tiers."},
     
    {"name": "WannaPeace", "color": RED, "year": 2017,
     "description": "WannaCry copycat that demanded payment in Bitcoin Cash instead of Bitcoin."},
     
    {"name": "GlobeImposter", "color": (70, 70, 220), "year": 2017,
     "description": "Targeted healthcare organizations by encrypting files and appending .GLOBEMAKER extension."},
     
    {"name": "CryptoWall", "color": PINK, "year": 2014,
     "description": "Early ransomware that evolved through multiple versions with improved encryption."},
     
    {"name": "TorrentLocker", "color": (50, 50, 50), "year": 2014,
     "description": "Spread through spam emails and encrypted files while deleting shadow copies."},
     
    {"name": "CTB-Locker", "color": CYAN, "year": 2015,
     "description": "Used the Tor network to hide its command and control servers."},
     
    {"name": "KeRanger", "color": (200, 100, 50), "year": 2016,
     "description": "First ransomware to target Apple macOS systems."},
     
    {"name": "LeChiffre", "color": (100, 200, 100), "year": 2016,
     "description": "Named after a James Bond villain, targeted financial documents."},
     
    {"name": "ZCryptor", "color": (150, 150, 150), "year": 2016,
     "description": "Combined ransomware with worm-like capabilities to spread across networks."},
     
    {"name": "Stampado", "color": YELLOW, "year": 2016,
     "description": "Low-cost ransomware sold on dark web forums for just $39."},
     
    {"name": "Chimera", "color": PURPLE, "year": 2015,
     "description": "Threatened to publish stolen files if ransom wasn't paid."},
     
    {"name": "Troldesh", "color": (50, 200, 200), "year": 2015,
     "description": "Early ransomware that communicated with victims via email."},
     
    {"name": "Ransom32", "color": BLUE, "year": 2016,
     "description": "First ransomware written in JavaScript and packaged as a NW.js app."},
     
    {"name": "EDA2", "color": RED, "year": 2016,
     "description": "Created by the same group behind the infamous TeslaCrypt."},
     
    {"name": "Nemucod", "color": GREEN, "year": 2016,
     "description": "JavaScript ransomware often distributed via malicious email attachments."},
     
    {"name": "CryptXXX", "color": PINK, "year": 2016,
     "description": "Evolved through multiple versions with improved encryption methods."},
     
    {"name": "Sage", "color": (200, 50, 100), "year": 2016,
     "description": "Spread through spam campaigns with ZIP attachments containing JavaScript files."},
     
    {"name": "Radamant", "color": (100, 50, 200), "year": 2017,
     "description": "Ransomware-as-a-service offering with a 25% cut to developers."},
     
    {"name": "Spider", "color": (50, 100, 50), "year": 2017,
     "description": "Featured a complex payment system with multiple cryptocurrency options."},
     
    {"name": "CryptoMix", "color": (200, 200, 50), "year": 2017,
     "description": "Often rebranded and sold under different names on hacker forums."},
     
    {"name": "Scatter", "color": CYAN, "year": 2017,
     "description": "Modified system settings to maintain persistence after reboot."},
     
    {"name": "PayCrypt", "color": PURPLE, "year": 2017,
     "description": "JavaScript ransomware that encrypted files and demanded payment."},
     
    {"name": "Goliath", "color": RED, "year": 2017,
     "description": "Named for its large ransom demands and aggressive tactics."},
     
    {"name": "XData", "color": BLUE, "year": 2018,
     "description": "Targeted Russian-speaking users with localized ransom notes."},
     
    {"name": "GandCrabV2", "color": (180, 50, 180), "year": 2018,
     "description": "Second version of the GandCrab ransomware with improved encryption."},
     
    {"name": "Anatova", "color": (50, 180, 50), "year": 2019,
     "description": "Modular ransomware that could download additional malicious components."},
     
    {"name": "Sodinokibi", "color": GREEN, "year": 2019,
     "description": "Alternative name for the REvil ransomware, known for targeting MSPs."},
     
    {"name": "MegaCortex", "color": (200, 100, 200), "year": 2019,
     "description": "Targeted enterprise networks with manual deployment by attackers."},
     
    {"name": "Snatch", "color": ORANGE, "year": 2019,
     "description": "Forced systems to reboot into Safe Mode to bypass security software."},
     
    {"name": "Eking", "color": (100, 200, 200), "year": 2019,
     "description": "Targeted database files and demanded ransom from businesses."},
     
    {"name": "Maze", "color": RED, "year": 2019,
     "description": "Pioneered the double extortion tactic before shutting down in 2020."},
     
    {"name": "DoppelPaymer", "color": (50, 50, 150), "year": 2019,
     "description": "Used sophisticated encryption and targeted large organizations."},
     
    {"name": "NetWalker", "color": (150, 50, 50), "year": 2020,
     "description": "Affiliate-based ransomware that targeted healthcare during COVID-19."},
     
    {"name": "Ragnarok", "color": (200, 150, 50), "year": 2020,
     "description": "Targeted vulnerabilities in VPN appliances to gain network access."},
     
    {"name": "Egregor", "color": PURPLE, "year": 2020,
     "description": "Operated as a ransomware-as-a-service with multiple affiliates."},
     
    {"name": "Avaddon", "color": (50, 150, 150), "year": 2020,
     "description": "Used aggressive tactics including DDoS attacks to pressure victims."},
     
    {"name": "DarkSide", "color": (100, 100, 100), "year": 2020,
     "description": "Professional operation with 'customer support' for victims."},
     
    {"name": "HelloKitty", "color": PINK, "year": 2020,
     "description": "Targeted gaming companies and threatened to leak source code."},
     
    {"name": "Hades", "color": (150, 50, 150), "year": 2021,
     "description": "Targeted large corporations with ransom demands over $10 million."},
     
    {"name": "BlackMatter", "color": BLACK, "year": 2021,
     "description": "Successor to DarkSide that targeted critical infrastructure."},
     
    {"name": "LockBit 2.0", "color": BLUE, "year": 2021,
     "description": "Second version with improved speed and self-spreading capabilities."},
     
    {"name": "BlackCat", "color": (50, 50, 50), "year": 2021,
     "description": "First professional ransomware written in Rust programming language."},
     
    {"name": "Conti v2", "color": CYAN, "year": 2021,
     "description": "Updated version of Conti with improved evasion techniques."}
]

# Add more ransomware types to reach 50+
for i in range(len(ransomware_db), 50):
    name = f"RansomX-{i+1}"
    color = (random.randint(50, 200), random.randint(50, 200), random.randint(50, 200))
    year = random.randint(2010, 2023)
    desc = f"Sample description for {name} ransomware detected in {year}. This is a placeholder description."
    ransomware_db.append({"name": name, "color": color, "year": year, "description": desc})

class Particle:
    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color
        self.size = random.randint(2, 6)
        self.life = random.randint(20, 40)
        self.speed = random.uniform(0.5, 3)
        self.angle = random.uniform(0, math.pi * 2)
        
    def update(self):
        self.x += math.cos(self.angle) * self.speed
        self.y += math.sin(self.angle) * self.speed
        self.life -= 1
        self.size = max(0, self.size - 0.1)
        
    def draw(self):
        alpha = min(255, self.life * 6)
        s = pygame.Surface((self.size * 2, self.size * 2), pygame.SRCALPHA)
        pygame.draw.circle(s, (*self.color, alpha), (self.size, self.size), self.size)
        screen.blit(s, (self.x - self.size, self.y - self.size))

class Bullet:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.speed = bullet_speed
        self.size = bullet_size
    
    def update(self):
        self.y -= self.speed
    
    def draw(self):
        screen.blit(bullet_img, (self.x - self.size//2, self.y - self.size//2))
    
    def is_off_screen(self):
        return self.y < -self.size

class Enemy:
    def __init__(self):
        ransomware = random.choice(ransomware_db)
        self.name = ransomware["name"]
        self.color = ransomware["color"]
        self.description = ransomware["description"]
        self.year = ransomware["year"]
        self.x = random.randint(0, WIDTH - enemy_size)
        self.y = -enemy_size
        self.speed = random.uniform(enemy_speed * 0.7, enemy_speed * 1.3)
        self.size = enemy_size
        self.health = 3
        self.img = self.generate_enemy_image()
    
    def generate_enemy_image(self):
        surf = pygame.Surface((self.size, self.size), pygame.SRCALPHA)
        # Draw main body
        pygame.draw.rect(surf, self.color, (5, 5, self.size-10, self.size-10), border_radius=5)
        # Draw circuit-like pattern
        pygame.draw.line(surf, (0, 0, 0, 100), (10, 10), (self.size-10, 10), 2)
        pygame.draw.line(surf, (0, 0, 0, 100), (10, self.size//2), (self.size-10, self.size//2), 2)
        pygame.draw.line(surf, (0, 0, 0, 100), (10, self.size-10), (self.size-10, self.size-10), 2)
        # Add name text
        name_text = font_small.render(self.name[:4], True, BLACK)
        text_rect = name_text.get_rect(center=(self.size//2, self.size//2))
        surf.blit(name_text, text_rect)
        return surf
    
    def update(self):
        self.y += self.speed
    
    def draw(self):
        screen.blit(self.img, (self.x, self.y))
    
    def is_off_screen(self):
        return self.y > HEIGHT + self.size
    
    def hit(self):
        self.health -= 1
        if self.health <= 0:
            self.create_explosion()
            return True
        return False
    
    def create_explosion(self):
        for _ in range(20):
            particles.append(Particle(self.x + self.size//2, self.y + self.size//2, self.color))
        for i in range(5):
            particles.append(Particle(self.x + self.size//2, self.y + self.size//2, WHITE))

def show_ransomware_info(enemy):
    global game_state
    game_state = INFO_SCREEN
    
    info_screen = pygame.Surface((700, 500))
    info_screen.fill((30, 30, 50))
    pygame.draw.rect(info_screen, (50, 50, 80), (10, 10, 680, 480), border_radius=10)
    
    title = font_large.render(f"{enemy.name} ({enemy.year})", True, enemy.color)
    info_screen.blit(title, (350 - title.get_width() // 2, 30))
    
    # Split description into multiple lines
    words = enemy.description.split(' ')
    lines = []
    current_line = ""
    
    for word in words:
        test_line = current_line + word + " "
        if font_medium.size(test_line)[0] < 650:
            current_line = test_line
        else:
            lines.append(current_line)
            current_line = word + " "
    
    if current_line:
        lines.append(current_line)
    
    for i, line in enumerate(lines):
        text = font_medium.render(line, True, WHITE)
        info_screen.blit(text, (50, 120 + i * 30))
    
    continue_text = font_medium.render("Press SPACE to continue", True, GREEN)
    info_screen.blit(continue_text, (350 - continue_text.get_width() // 2, 430))
    
    screen.blit(info_screen, (WIDTH // 2 - 350, HEIGHT // 2 - 250))
    pygame.display.flip()
    
    waiting = True
    while waiting:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            if event.type == KEYDOWN:
                if event.key == K_SPACE:
                    waiting = False
                    game_state = PLAYING

def draw_game():
    # Draw background
    screen.blit(background_img, (0, 0))
    
    # Draw particles
    for particle in particles[:]:
        particle.draw()
        particle.update()
        if particle.life <= 0:
            particles.remove(particle)
    
    # Draw player
    screen.blit(player_img, (player_x - player_size//2, player_y - player_size//2))
    
    # Draw bullets
    for bullet in bullets:
        bullet.draw()
    
    # Draw enemies
    for enemy in enemies:
        enemy.draw()
    
    # Draw UI
    pygame.draw.rect(screen, (0, 0, 0, 150), (0, 0, WIDTH, 60))
    
    # Score
    score_text = font_medium.render(f"Score: {score}", True, WHITE)
    screen.blit(score_text, (20, 20))
    
    # Level
    level_text = font_medium.render(f"Level: {level}", True, WHITE)
    screen.blit(level_text, (200, 20))
    
    # Health bar
    pygame.draw.rect(screen, (50, 50, 50), (WIDTH - 220, 20, 200, 20))
    pygame.draw.rect(screen, RED, (WIDTH - 220, 20, player_health * 2, 20))
    health_text = font_medium.render(f"Firewall: {player_health}%", True, WHITE)
    screen.blit(health_text, (WIDTH - 220 + 100 - health_text.get_width()//2, 20))

def draw_menu():
    screen.blit(background_img, (0, 0))
    
    title = font_title.render("CYBER DEFENSE", True, (50, 200, 255))
    screen.blit(title, (WIDTH//2 - title.get_width()//2, 150))
    
    subtitle = font_large.render("Ransomware Shooter", True, WHITE)
    screen.blit(subtitle, (WIDTH//2 - subtitle.get_width()//2, 250))
    
    start_text = font_medium.render("Press SPACE to Start", True, GREEN)
    screen.blit(start_text, (WIDTH//2 - start_text.get_width()//2, 400))
    
    high_text = font_medium.render(f"High Score: {high_score}", True, YELLOW)
    screen.blit(high_text, (WIDTH//2 - high_text.get_width()//2, 480))
    
    info_text = font_small.render("Defend against 50+ ransomware types. Learn as you play!", True, WHITE)
    screen.blit(info_text, (WIDTH//2 - info_text.get_width()//2, 550))

def draw_game_over():
    overlay = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 200))
    screen.blit(overlay, (0, 0))
    
    game_over_text = font_large.render("FIREWALL BREACHED!", True, RED)
    screen.blit(game_over_text, (WIDTH//2 - game_over_text.get_width()//2, 250))
    
    score_text = font_medium.render(f"Final Score: {score}", True, WHITE)
    screen.blit(score_text, (WIDTH//2 - score_text.get_width()//2, 350))
    
    restart_text = font_medium.render("Press R to Restart", True, GREEN)
    screen.blit(restart_text, (WIDTH//2 - restart_text.get_width()//2, 420))
    
    menu_text = font_medium.render("Press M for Menu", True, YELLOW)
    screen.blit(menu_text, (WIDTH//2 - menu_text.get_width()//2, 470))

def reset_game():
    global player_x, player_y, bullets, enemies, score, level, player_health, game_state
    player_x = WIDTH // 2 - player_size // 2
    player_y = HEIGHT - player_size - 50
    bullets = []
    enemies = []
    particles = []
    score = 0
    level = 1
    player_health = 100
    game_state = PLAYING

# Main game loop
frame_count = 0
running = True
while running:
    clock.tick(60)
    frame_count += 1
    
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        
        if event.type == KEYDOWN:
            if game_state == MENU and event.key == K_SPACE:
                reset_game()
            elif game_state == PLAYING and event.key == K_SPACE:
                # Shoot bullet
                bullets.append(Bullet(player_x + player_size // 2, player_y))
            elif game_state == GAME_OVER:
                if event.key == K_r:
                    reset_game()
                elif event.key == K_m:
                    game_state = MENU
    
    if game_state == PLAYING:
        # Player movement
        keys = pygame.key.get_pressed()
        if keys[K_LEFT] and player_x > player_size // 2:
            player_x -= player_speed
        if keys[K_RIGHT] and player_x < WIDTH - player_size // 2:
            player_x += player_speed
        
        # Update bullets
        for bullet in bullets[:]:
            bullet.update()
            if bullet.is_off_screen():
                bullets.remove(bullet)
        
        # Spawn enemies
        if frame_count % enemy_spawn_rate == 0:
            enemies.append(Enemy())
            # Increase difficulty every 10 points
            if score > 0 and score % 10 == 0:
                enemy_spawn_rate = max(20, enemy_spawn_rate - 2)
                level = score // 10 + 1
        
        # Update enemies and check collisions
        for enemy in enemies[:]:
            enemy.update()
            
            # Check if enemy hit player
            if (player_x - player_size//2 < enemy.x + enemy.size and
                player_x + player_size//2 > enemy.x and
                player_y - player_size//2 < enemy.y + enemy.size and
                player_y + player_size//2 > enemy.y):
                player_health -= random.randint(5, 15)
                enemy.create_explosion()
                enemies.remove(enemy)
                
                if player_health <= 0:
                    player_health = 0
                    game_state = GAME_OVER
                    if score > high_score:
                        high_score = score
                else:
                    show_ransomware_info(enemy)
            
            # Check if enemy is off screen
            if enemy.is_off_screen():
                enemies.remove(enemy)
            
            # Check bullet collisions
            for bullet in bullets[:]:
                if (bullet.x - bullet.size//2 < enemy.x + enemy.size and
                    bullet.x + bullet.size//2 > enemy.x and
                    bullet.y - bullet.size//2 < enemy.y + enemy.size and
                    bullet.y + bullet.size//2 > enemy.y):
                    if enemy.hit():
                        enemies.remove(enemy)
                        score += 1
                    bullets.remove(bullet)
                    break
    
    # Draw appropriate screen based on game state
    if game_state == MENU:
        draw_menu()
    elif game_state == PLAYING:
        draw_game()
    elif game_state == GAME_OVER:
        draw_game()
        draw_game_over()
    
    pygame.display.flip()

pygame.quit()
sys.exit()