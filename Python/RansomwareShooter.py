import pygame
import random
import sys
import math
import webbrowser
from pygame import mixer
from pygame.locals import *

# Initialize pygame
pygame.init()
mixer.init()

# Screen dimensions
WIDTH, HEIGHT = 1024, 768
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Cyber Threat Defense")

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
DARK_BLUE = (10, 20, 40)
LIGHT_BLUE = (100, 180, 255)
GRAY = (100, 100, 100)

# Game states
MENU = 0
PLAYING = 1
GAME_OVER = 2
INFO_SCREEN = 3
WAVE_COMPLETE = 4
game_state = MENU

# Load fonts
try:
    title_font = pygame.font.Font(None, 96)
    large_font = pygame.font.Font(None, 72)
    medium_font = pygame.font.Font(None, 36)
    small_font = pygame.font.Font(None, 28)
except:
    # Fallback fonts if custom fonts not found
    title_font = pygame.font.Font(None, 96)
    large_font = pygame.font.Font(None, 72)
    medium_font = pygame.font.Font(None, 36)
    small_font = pygame.font.Font(None, 28)

# Create a clean cyberpunk-style background
def create_background():
    bg = pygame.Surface((WIDTH, HEIGHT))
    bg.fill(DARK_BLUE)
    
    # Add grid lines
    for x in range(0, WIDTH, 40):
        pygame.draw.line(bg, (20, 40, 80), (x, 0), (x, HEIGHT), 1)
    for y in range(0, HEIGHT, 40):
        pygame.draw.line(bg, (20, 40, 80), (0, y), (WIDTH, y), 1)
    
    # Add some random "nodes"
    for _ in range(50):
        x = random.randint(0, WIDTH)
        y = random.randint(0, HEIGHT)
        pygame.draw.circle(bg, (50, 100, 200), (x, y), random.randint(1, 3))
    
    return bg

background_img = create_background()

# Player (Circular Core)
player_radius = 30
player_x = WIDTH // 2
player_y = HEIGHT // 2
player_speed = 5
player_health = 100
player_shield = 50  # Additional protection
max_shield = 50

# Bullets
bullets = []
bullet_speed = 12
bullet_radius = 8

# Enemies
enemies = []
enemy_types = ["Spyware", "Phishing", "Malware", "Adware", "Ransomware", "Trojan", "Worm"]
enemy_colors = {
    "Spyware": RED,
    "Phishing": BLUE,
    "Malware": PURPLE,
    "Adware": YELLOW,
    "Ransomware": GREEN,
    "Trojan": ORANGE,
    "Worm": PINK
}

# Waves system
current_wave = 0
wave_enemies = 0
enemies_defeated = 0
wave_complete = False
wave_cooldown = 180  # 3 seconds at 60 FPS
enemy_spawn_timer = 0
ENEMY_SPAWN_INTERVAL = 120  # 2 seconds at 60 FPS

# Particles
particles = []

# Game variables
score = 0
high_score = 0
level = 1
clock = pygame.time.Clock()

# Threat database
threat_db = [
    {"name": "Spyware", "type": "Spyware", "color": RED, "year": 2000,
     "description": "Software that secretly monitors user activity and collects sensitive information.",
     "impact": "Steals passwords, credit card numbers, and other personal data without consent.",
     "behavior": "Slow movement but high health, appears in early waves"},
     
    {"name": "Phishing", "type": "Phishing", "color": BLUE, "year": 1995,
     "description": "Fraudulent attempt to obtain sensitive information by disguising as trustworthy.",
     "impact": "Responsible for over 90% of data breaches, tricks users into revealing info.",
     "behavior": "Fast movement but low health, appears in groups"},
     
    {"name": "Malware", "type": "Malware", "color": PURPLE, "year": 1990,
     "description": "Malicious software designed to harm or exploit any device or network.",
     "impact": "Can delete files, slow systems, or create backdoors for hackers.",
     "behavior": "Medium speed and health, most common threat"},
     
    {"name": "Adware", "type": "Adware", "color": YELLOW, "year": 2005,
     "description": "Unwanted software that displays advertising on your device.",
     "impact": "Slows down systems and creates annoying pop-up advertisements.",
     "behavior": "Creates pop-up distractions when hit"},
     
    {"name": "WannaCry", "type": "Ransomware", "color": GREEN, "year": 2017,
     "description": "Ransomware that encrypts files and demands payment for decryption.",
     "impact": "Affected 200,000+ computers across 150 countries, causing billions in damage.",
     "behavior": "High health, appears in later waves"},
     
    {"name": "Zeus", "type": "Trojan", "color": ORANGE, "year": 2007,
     "description": "Banking Trojan that steals financial data through keylogging.",
     "impact": "Responsible for over $100 million in bank fraud.",
     "behavior": "Medium speed, drops additional threats when destroyed"},
     
    {"name": "ILOVEYOU", "type": "Worm", "color": PINK, "year": 2000,
     "description": "One of the most damaging worms that spread via email attachments.",
     "impact": "Caused $5.5-8.7 billion in damages worldwide.",
     "behavior": "Fast replication, appears in large numbers"}
]

# Add more threats to reach 50+
for i in range(len(threat_db), 50):
    threat_type = random.choice(["Spyware", "Phishing", "Malware", "Adware", "Ransomware", "Trojan", "Worm"])
    name = f"{threat_type}-{i+1}"
    color = enemy_colors[threat_type]
    year = random.randint(1990, 2023)
    desc = f"Sample {threat_type} threat detected in {year}. This is a placeholder description."
    impact = f"Sample impact data showing typical {threat_type.lower()} infection patterns."
    behavior = "Varies based on threat type and level"
    threat_db.append({"name": name, "type": threat_type, "color": color, "year": year, 
                     "description": desc, "impact": impact, "behavior": behavior})

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
    def __init__(self, x, y, target_x, target_y):
        self.x = x
        self.y = y
        self.speed = bullet_speed
        self.radius = bullet_radius
        self.color = LIGHT_BLUE
        
        # Calculate direction vector
        dx = target_x - x
        dy = target_y - y
        dist = math.sqrt(dx * dx + dy * dy)
        self.vx = (dx / dist) * bullet_speed if dist > 0 else 0
        self.vy = (dy / dist) * bullet_speed if dist > 0 else 0
    
    def update(self):
        self.x += self.vx
        self.y += self.vy
    
    def draw(self):
        # Glow effect
        glow = pygame.Surface((self.radius*4, self.radius*4), pygame.SRCALPHA)
        pygame.draw.circle(glow, (*self.color, 100), (self.radius*2, self.radius*2), self.radius*2)
        screen.blit(glow, (self.x - self.radius*2, self.y - self.radius*2))
        
        # Bullet core
        pygame.draw.circle(screen, self.color, (int(self.x), int(self.y)), self.radius)
    
    def is_off_screen(self):
        return (self.x < -self.radius*2 or self.x > WIDTH + self.radius*2 or 
                self.y < -self.radius*2 or self.y > HEIGHT + self.radius*2)

class Enemy:
    def __init__(self, threat_type=None):
        if threat_type:
            # Create specific threat type
            threats = [t for t in threat_db if t["type"] == threat_type]
            if not threats:
                threats = threat_db
            threat = random.choice(threats)
        else:
            # Random threat based on wave
            threat = random.choice(threat_db)
            
        self.name = threat["name"]
        self.type = threat["type"]
        self.color = threat["color"]
        self.description = threat["description"]
        self.impact = threat["impact"]
        self.behavior = threat["behavior"]
        self.year = threat["year"]
        
        # Spawn from random edge of screen
        side = random.randint(0, 3)
        if side == 0:  # Top
            self.x = random.randint(0, WIDTH)
            self.y = -50
        elif side == 1:  # Right
            self.x = WIDTH + 50
            self.y = random.randint(0, HEIGHT)
        elif side == 2:  # Bottom
            self.x = random.randint(0, WIDTH)
            self.y = HEIGHT + 50
        else:  # Left
            self.x = -50
            self.y = random.randint(0, HEIGHT)
            
        # Set properties based on type
        if self.type == "Spyware":
            self.radius = 35
            self.speed = random.uniform(1.0, 1.5)
            self.health = 5
        elif self.type == "Phishing":
            self.radius = 25
            self.speed = random.uniform(3.0, 4.0)
            self.health = 1
        elif self.type == "Malware":
            self.radius = 30
            self.speed = random.uniform(2.0, 2.5)
            self.health = 3
        elif self.type == "Adware":
            self.radius = 40
            self.speed = random.uniform(1.5, 2.0)
            self.health = 2
        elif self.type == "Ransomware":
            self.radius = 45
            self.speed = random.uniform(1.0, 1.8)
            self.health = 8
        elif self.type == "Trojan":
            self.radius = 32
            self.speed = random.uniform(2.0, 2.8)
            self.health = 4
        elif self.type == "Worm":
            self.radius = 28
            self.speed = random.uniform(2.5, 3.5)
            self.health = 2
        
        # Scale with level
        self.speed *= (1 + level * 0.1)
        self.health = int(self.health * (1 + level * 0.2))
        
        self.popups = []  # For adware popups
        self.last_popup_time = 0
    
    def update(self):
        # Move towards player
        dx = player_x - self.x
        dy = player_y - self.y
        dist = math.sqrt(dx * dx + dy * dy)
        
        if dist > 0:
            self.x += (dx / dist) * self.speed
            self.y += (dy / dist) * self.speed
        
        # Adware behavior - create popups
        if self.type == "Adware" and pygame.time.get_ticks() - self.last_popup_time > 2000:
            self.popups.append({"x": self.x, "y": self.y, "life": 60})
            self.last_popup_time = pygame.time.get_ticks()
        
        # Update popups
        for popup in self.popups[:]:
            popup["life"] -= 1
            if popup["life"] <= 0:
                self.popups.remove(popup)
    
    def draw(self):
        # Draw enemy
        pygame.draw.circle(screen, self.color, (int(self.x), int(self.y)), self.radius)
        
        # Draw name
        name_text = small_font.render(self.name[:6], True, WHITE)
        name_rect = name_text.get_rect(center=(self.x, self.y))
        screen.blit(name_text, name_rect)
        
        # Draw health bar
        health_width = 40
        health_height = 5
        pygame.draw.rect(screen, GRAY, (self.x - health_width//2, self.y - self.radius - 10, 
                                       health_width, health_height))
        pygame.draw.rect(screen, GREEN, (self.x - health_width//2, self.y - self.radius - 10, 
                                       health_width * (self.health / self.get_max_health()), health_height))
        
        # Draw adware popups
        if self.type == "Adware":
            for popup in self.popups:
                alpha = min(255, popup["life"] * 4)
                s = pygame.Surface((100, 50), pygame.SRCALPHA)
                pygame.draw.rect(s, (*YELLOW, alpha), (0, 0, 100, 50), border_radius=5)
                pygame.draw.rect(s, (255, 255, 255, alpha), (0, 0, 100, 50), 2, border_radius=5)
                popup_text = small_font.render("CLICK ME!", True, (0, 0, 0, alpha))
                s.blit(popup_text, (50 - popup_text.get_width()//2, 25 - popup_text.get_height()//2))
                screen.blit(s, (popup["x"] - 50, popup["y"] - 25))
    
    def get_max_health(self):
        # Base health based on type
        if self.type == "Spyware": return 5 * (1 + level * 0.2)
        elif self.type == "Phishing": return 1 * (1 + level * 0.2)
        elif self.type == "Malware": return 3 * (1 + level * 0.2)
        elif self.type == "Adware": return 2 * (1 + level * 0.2)
        elif self.type == "Ransomware": return 8 * (1 + level * 0.2)
        elif self.type == "Trojan": return 4 * (1 + level * 0.2)
        elif self.type == "Worm": return 2 * (1 + level * 0.2)
        return 3 * (1 + level * 0.2)
    
    def is_off_screen(self):
        return (self.x < -self.radius*2 or self.x > WIDTH + self.radius*2 or 
                self.y < -self.radius*2 or self.y > HEIGHT + self.radius*2)
    
    def hit(self):
        self.health -= 1
        if self.health <= 0:
            self.create_explosion()
            
            # Trojan drops additional threats
            if self.type == "Trojan":
                for _ in range(2):
                    if len(enemies) < 50:  # Limit spawned enemies
                        new_enemy = Enemy("Phishing")
                        new_enemy.x = self.x
                        new_enemy.y = self.y
                        enemies.append(new_enemy)
            
            return True
        return False
    
    def create_explosion(self):
        for _ in range(20):
            particles.append(Particle(self.x, self.y, self.color))
        for _ in range(5):
            particles.append(Particle(self.x, self.y, WHITE))

def start_wave(wave_num):
    global wave_enemies, enemies_defeated, wave_complete, current_wave
    
    current_wave = wave_num
    enemies_defeated = 0
    wave_complete = False
    
    # Calculate number of enemies based on wave number
    wave_enemies = 5 + wave_num * 3
    wave_enemies = min(wave_enemies, 30)  # Cap at 30 enemies per wave
    
    # Clear existing enemies
    enemies.clear()
    
    # Spawn initial enemies
    for _ in range(min(5, wave_enemies)):
        threat_type = None
        if wave_num < 3:  # Early waves
            threat_type = random.choice(["Spyware", "Phishing", "Malware"])
        elif wave_num < 6:  # Mid waves
            threat_type = random.choice(["Malware", "Adware", "Trojan"])
        else:  # Late waves
            threat_type = random.choice(["Ransomware", "Trojan", "Worm"])
        
        enemies.append(Enemy(threat_type))

def show_threat_info(enemy):
    global game_state
    game_state = INFO_SCREEN
    
    # Create info screen surface with cyberpunk style
    info_screen = pygame.Surface((700, 650), pygame.SRCALPHA)
    info_screen.fill((10, 20, 40, 220))
    
    # Border with glow effect
    pygame.draw.rect(info_screen, (*enemy.color, 100), (5, 5, 690, 640), border_radius=15)
    pygame.draw.rect(info_screen, (30, 40, 80, 240), (10, 10, 680, 630), border_radius=10)
    
    # Title with year
    title = large_font.render(f"{enemy.name}", True, enemy.color)
    info_screen.blit(title, (350 - title.get_width() // 2, 30))
    
    type_text = medium_font.render(f"Type: {enemy.type} | First seen: {enemy.year}", True, WHITE)
    info_screen.blit(type_text, (350 - type_text.get_width() // 2, 90))
    
    # Description
    desc_lines = []
    current_line = ""
    for word in enemy.description.split(' '):
        test_line = current_line + word + " "
        if medium_font.size(test_line)[0] < 650:
            current_line = test_line
        else:
            desc_lines.append(current_line)
            current_line = word + " "
    if current_line:
        desc_lines.append(current_line)
    
    # Impact
    impact_lines = []
    current_line = "Impact: "
    for word in enemy.impact.split(' '):
        test_line = current_line + word + " "
        if medium_font.size(test_line)[0] < 650:
            current_line = test_line
        else:
            impact_lines.append(current_line)
            current_line = word + " "
    if current_line:
        impact_lines.append(current_line)
    
    # Behavior
    behavior_lines = []
    current_line = "Behavior: "
    for word in enemy.behavior.split(' '):
        test_line = current_line + word + " "
        if medium_font.size(test_line)[0] < 650:
            current_line = test_line
        else:
            behavior_lines.append(current_line)
            current_line = word + " "
    if current_line:
        behavior_lines.append(current_line)
    
    # Draw all text
    y_offset = 150
    for line in desc_lines:
        text = medium_font.render(line, True, WHITE)
        info_screen.blit(text, (50, y_offset))
        y_offset += 30
    
    y_offset += 20  # Add space between sections
    
    for line in impact_lines:
        text = medium_font.render(line, True, YELLOW)
        info_screen.blit(text, (50, y_offset))
        y_offset += 30
    
    y_offset += 20  # Add space between sections
    
    for line in behavior_lines:
        text = medium_font.render(line, True, CYAN)
        info_screen.blit(text, (50, y_offset))
        y_offset += 30
    
    # "See More" button
    see_more_rect = pygame.Rect(250, y_offset + 30, 200, 40)
    pygame.draw.rect(info_screen, (0, 100, 200, 200), see_more_rect, border_radius=5)
    pygame.draw.rect(info_screen, CYAN, see_more_rect, 2, border_radius=5)
    see_more_text = medium_font.render("See More Online", True, WHITE)
    info_screen.blit(see_more_text, (350 - see_more_text.get_width()//2, y_offset + 40))
    
    # Continue prompt
    continue_text = medium_font.render("Press SPACE to continue defense", True, GREEN)
    info_screen.blit(continue_text, (350 - continue_text.get_width() // 2, y_offset + 100))
    
    # Draw to screen with fade effect
    fade = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    fade.fill((0, 0, 0, 150))
    screen.blit(fade, (0, 0))
    screen.blit(info_screen, (WIDTH // 2 - 350, HEIGHT // 2 - 325))  # Adjusted position
    
    pygame.display.flip()
    
    # Wait for user input
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
            if event.type == MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                # Adjust mouse position relative to info screen
                adj_x = mouse_pos[0] - (WIDTH // 2 - 350)
                adj_y = mouse_pos[1] - (HEIGHT // 2 - 325)
                
                if see_more_rect.collidepoint(adj_x, adj_y):
                    # Open Google search for this threat
                    search_query = f"{enemy.name} {enemy.type} {enemy.year} site:www.cisa.gov OR site:www.kaspersky.com OR site:www.malwarebytes.com"
                    search_url = f"https://www.google.com/search?q={search_query.replace(' ', '+')}"
                    webbrowser.open(search_url)

def draw_wave_complete():
    # Dark overlay
    overlay = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 150))
    screen.blit(overlay, (0, 0))
    
    # Wave complete text
    wave_text = title_font.render(f"WAVE {current_wave} COMPLETE!", True, GREEN)
    screen.blit(wave_text, (WIDTH//2 - wave_text.get_width()//2, 250))
    
    # Next wave info
    next_text = large_font.render(f"Next wave: {current_wave + 1}", True, WHITE)
    screen.blit(next_text, (WIDTH//2 - next_text.get_width()//2, 350))
    
    # Continue prompt
    continue_text = medium_font.render("Press SPACE to continue", True, CYAN)
    screen.blit(continue_text, (WIDTH//2 - continue_text.get_width()//2, 450))

def draw_game():
    # Draw background
    screen.blit(background_img, (0, 0))
    
    # Draw particles
    for particle in particles[:]:
        particle.draw()
        particle.update()
        if particle.life <= 0:
            particles.remove(particle)
    
    # Draw bullets
    for bullet in bullets:
        bullet.draw()
    
    # Draw enemies
    for enemy in enemies:
        enemy.draw()
    
    # Draw player (circular core with shield)
    # Shield outer ring
    shield_alpha = min(255, player_shield * 5)
    shield_surface = pygame.Surface((player_radius*4, player_radius*4), pygame.SRCALPHA)
    pygame.draw.circle(shield_surface, (*CYAN, shield_alpha//3), 
                      (player_radius*2, player_radius*2), player_radius*2)
    screen.blit(shield_surface, (player_x - player_radius*2, player_y - player_radius*2))
    
    # Player core
    pygame.draw.circle(screen, LIGHT_BLUE, (int(player_x), int(player_y)), player_radius)
    
    # Inner core
    pygame.draw.circle(screen, BLUE, (int(player_x), int(player_y)), player_radius//2)
    
    # Draw UI panel with cyberpunk style
    ui_panel = pygame.Surface((WIDTH, 90), pygame.SRCALPHA)
    ui_panel.fill((0, 0, 30, 180))
    
    # Add tech-looking details to UI
    for x in range(0, WIDTH, 20):
        pygame.draw.line(ui_panel, (0, 100, 200, 50), (x, 0), (x, 5))
    
    screen.blit(ui_panel, (0, 0))
    
    # Score
    score_text = medium_font.render(f"SCORE: {score}", True, WHITE)
    screen.blit(score_text, (20, 20))
    
    # Level and Wave
    level_text = medium_font.render(f"LEVEL: {level} | WAVE: {current_wave}", True, CYAN)
    screen.blit(level_text, (200, 20))
    
    # Enemies remaining
    enemies_text = medium_font.render(f"THREATS: {wave_enemies - enemies_defeated}/{wave_enemies}", True, WHITE)
    screen.blit(enemies_text, (500, 20))
    
    # Debug info
    debug_text = small_font.render(f"Enemies: {len(enemies)}", True, RED)
    screen.blit(debug_text, (20, 60))
    
    # Health bar
    health_width = 200
    health_height = 20
    pygame.draw.rect(screen, (50, 50, 50, 200), (WIDTH - 220, 20, health_width, health_height))
    pygame.draw.rect(screen, RED, (WIDTH - 220, 20, health_width * (player_health / 100), health_height))
    health_text = medium_font.render(f"INTEGRITY: {player_health}%", True, WHITE)
    screen.blit(health_text, (WIDTH - 220 + health_width//2 - health_text.get_width()//2, 20))
    
    # Shield bar
    shield_width = 200
    shield_height = 10
    pygame.draw.rect(screen, (50, 50, 50, 200), (WIDTH - 220, 45, shield_width, shield_height))
    pygame.draw.rect(screen, CYAN, (WIDTH - 220, 45, shield_width * (player_shield / max_shield), shield_height))
    shield_text = small_font.render(f"SHIELD: {player_shield}/{max_shield}", True, WHITE)
    screen.blit(shield_text, (WIDTH - 220 + shield_width//2 - shield_text.get_width()//2, 45))

def draw_menu():
    # Draw animated background
    screen.blit(background_img, (0, 0))
    
    # Add moving scan lines
    scan_line_y = pygame.time.get_ticks() // 20 % HEIGHT
    scan_line = pygame.Surface((WIDTH, 2), pygame.SRCALPHA)
    scan_line.fill((0, 255, 255, 30))
    screen.blit(scan_line, (0, scan_line_y))
    
    # Title with glow effect
    title = title_font.render("CYBER DEFENSE", True, LIGHT_BLUE)
    title_shadow = title_font.render("CYBER DEFENSE", True, (0, 150, 255, 100))
    
    for i in range(5):
        offset = i + 1
        screen.blit(title_shadow, (WIDTH//2 - title.get_width()//2 + offset, 150 + offset))
    
    screen.blit(title, (WIDTH//2 - title.get_width()//2, 150))
    
    subtitle = large_font.render("THREAT NEUTRALIZATION SYSTEM", True, CYAN)
    screen.blit(subtitle, (WIDTH//2 - subtitle.get_width()//2, 250))
    
    # Start button with hover effect
    mouse_pos = pygame.mouse.get_pos()
    start_rect = pygame.Rect(WIDTH//2 - 150, 400, 300, 60)
    hover = start_rect.collidepoint(mouse_pos)
    
    pygame.draw.rect(screen, (0, 100, 200, 200 if hover else 150), start_rect, border_radius=10)
    pygame.draw.rect(screen, CYAN, start_rect, 2, border_radius=10)
    
    start_text = large_font.render("START", True, WHITE)
    screen.blit(start_text, (WIDTH//2 - start_text.get_width()//2, 410))
    
    # High score
    high_text = medium_font.render(f"HIGH SCORE: {high_score}", True, YELLOW)
    screen.blit(high_text, (WIDTH//2 - high_text.get_width()//2, 500))
    
    # Info text
    info_text = small_font.render("Defend against waves of cyber threats. Learn as you play!", True, WHITE)
    screen.blit(info_text, (WIDTH//2 - info_text.get_width()//2, 580))
    
    # Controls
    controls_text = small_font.render("WASD: Move | SPACE: Shoot | Mouse: Aim", True, (150, 150, 255))
    screen.blit(controls_text, (WIDTH//2 - controls_text.get_width()//2, HEIGHT - 50))

def draw_game_over():
    # Dark overlay
    overlay = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 200))
    screen.blit(overlay, (0, 0))
    
    # Game over text with effect
    game_over_text = title_font.render("SYSTEM BREACHED!", True, RED)
    text_shadow = title_font.render("SYSTEM BREACHED!", True, (150, 0, 0, 100))
    
    for i in range(5):
        offset = i + 1
        screen.blit(text_shadow, (WIDTH//2 - game_over_text.get_width()//2 + offset, 250 + offset))
    
    screen.blit(game_over_text, (WIDTH//2 - game_over_text.get_width()//2, 250))
    
    # Score and Wave
    score_text = large_font.render(f"FINAL SCORE: {score}", True, WHITE)
    screen.blit(score_text, (WIDTH//2 - score_text.get_width()//2, 350))
    
    wave_text = large_font.render(f"WAVES COMPLETED: {current_wave}", True, CYAN)
    screen.blit(wave_text, (WIDTH//2 - wave_text.get_width()//2, 400))
    
    # Buttons
    restart_rect = pygame.Rect(WIDTH//2 - 320, 470, 300, 60)
    menu_rect = pygame.Rect(WIDTH//2 + 20, 470, 300, 60)
    mouse_pos = pygame.mouse.get_pos()
    
    # Restart button
    pygame.draw.rect(screen, (0, 150, 0, 200) if restart_rect.collidepoint(mouse_pos) else (0, 100, 0, 200), 
                    restart_rect, border_radius=10)
    pygame.draw.rect(screen, GREEN, restart_rect, 2, border_radius=10)
    restart_text = medium_font.render("RESTART", True, WHITE)
    screen.blit(restart_text, (restart_rect.centerx - restart_text.get_width()//2, restart_rect.centery - restart_text.get_height()//2))
    
    # Menu button
    pygame.draw.rect(screen, (150, 0, 0, 200) if menu_rect.collidepoint(mouse_pos) else (100, 0, 0, 200), 
                     menu_rect, border_radius=10)
    pygame.draw.rect(screen, RED, menu_rect, 2, border_radius=10)
    menu_text = medium_font.render("MAIN MENU", True, WHITE)
    screen.blit(menu_text, (menu_rect.centerx - menu_text.get_width()//2, menu_rect.centery - menu_text.get_height()//2))

def reset_game():
    global player_x, player_y, bullets, enemies, particles, score, level, player_health, player_shield
    global current_wave, wave_enemies, enemies_defeated, wave_complete, wave_cooldown, game_state
    global enemy_spawn_timer

    player_x = WIDTH // 2
    player_y = HEIGHT // 2
    bullets = []
    enemies = []
    particles = []
    score = 0
    print(f"{score=}") # ADDED
    level = 1
    player_health = 100
    player_shield = max_shield
    current_wave = 0
    wave_enemies = 0
    enemies_defeated = 0
    wave_complete = False
    wave_cooldown = 180
    enemy_spawn_timer = 0
    game_state = PLAYING
    start_wave(1)  # Start with wave 1

def start_wave(wave_num):
    global wave_enemies, enemies_defeated, wave_complete, current_wave
    
    current_wave = wave_num
    enemies_defeated = 0
    wave_complete = False
    
    # Calculate number of enemies based on wave number
    wave_enemies = 5 + wave_num * 3
    wave_enemies = min(wave_enemies, 30)  # Cap at 30 enemies per wave
    
    # Clear existing enemies
    enemies.clear()

    print(f"{wave_num=}, {wave_enemies=}")  # ADDED
    
    # Spawn initial enemies
    for _ in range(min(5, wave_enemies)):
        threat_type = None
        if wave_num < 3:  # Early waves
            threat_type = random.choice(["Spyware", "Phishing", "Malware"])
        elif wave_num < 6:  # Mid waves
            threat_type = random.choice(["Malware", "Adware", "Trojan"])
        else:  # Late waves
            threat_type = random.choice(["Ransomware", "Trojan", "Worm"])
        
        enemies.append(Enemy(threat_type))

# Main game loop
running = True
while running:
    clock.tick(60)
    
    # Handle events
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        
        if event.type == KEYDOWN:
            if game_state == MENU and event.key == K_SPACE:
                reset_game()
            elif game_state == PLAYING and event.key == K_SPACE:
                # Shoot bullet towards cursor
                mouse_x, mouse_y = pygame.mouse.get_pos()
                bullets.append(Bullet(player_x, player_y, mouse_x, mouse_y))
            elif game_state == WAVE_COMPLETE and event.key == K_SPACE:
                start_wave(current_wave + 1)
                game_state = PLAYING
        
    # Player movement
    keys = pygame.key.get_pressed()
    if keys[K_w] or keys[K_UP]:
        player_y -= player_speed
    if keys[K_s] or keys[K_DOWN]:
        player_y += player_speed
    if keys[K_a] or keys[K_LEFT]:
        player_x -= player_speed
    if keys[K_d] or keys[K_RIGHT]:
        player_x += player_speed

    # Keep player within screen bounds
    player_x = max(player_radius, min(WIDTH - player_radius, player_x))
    player_y = max(player_radius, min(HEIGHT - player_radius, player_y))

    # Update game state based on current game state
    if game_state == PLAYING:
        # Update bullets
        for bullet in bullets[:]:
            bullet.update()
            if bullet.is_off_screen():
                bullets.remove(bullet)

        # Update enemies
        for enemy in enemies[:]:
            enemy.update()
            if enemy.is_off_screen():
                enemies.remove(enemy)
            if enemy.hit():
                enemies_defeated += 1
                print("Enemy Hit!")  # ADDED
                score += 10  # Increase score for defeating an enemy
                enemies.remove(enemy)

        # Check for wave completion
        if enemies_defeated >= wave_enemies:
            wave_complete = True

        # Spawn new enemies if wave is complete
        if wave_complete:
            draw_wave_complete()

        # **Add these lines:**
        print(f"{enemy_spawn_timer=}, {ENEMY_SPAWN_INTERVAL=}, {len(enemies)=}, {wave_enemies=}")  # ADDED

        if enemy_spawn_timer >= ENEMY_SPAWN_INTERVAL and len(enemies) < wave_enemies: #and len(enemies) < 50:  # Limit spawned enemies
            print("Spawning a new enemy!") # ADDED
            threat_type = None
            if current_wave < 3:  # Early waves
                threat_type = random.choice(["Spyware", "Phishing", "Malware"])
            elif current_wave < 6:  # Mid waves
                threat_type = random.choice(["Malware", "Adware", "Trojan"])
            else:  # Late waves
                threat_type = random.choice(["Ransomware", "Trojan", "Worm"])

            enemies.append(Enemy(threat_type))
            enemy_spawn_timer = 0  # Reset the timer after spawning

        enemy_spawn_timer += 1 # Increment the timer

    elif game_state == GAME_OVER:
        draw_game_over()
    elif game_state == INFO_SCREEN:
        # Handle info screen logic
        pass

    # Draw the game
    if game_state == PLAYING:
        draw_game()
    elif game_state == MENU:
        draw_menu()

    pygame.display.flip()

pygame.quit()