#include <LiquidCrystal.h>

#define PIN_BUTTON 2
#define PIN_AUTOPLAY 1
#define PIN_READWRITE 10
#define PIN_CONTRAST 12
#define PIN_BUZZER 8

#define SPRITE_RUN1 1
#define SPRITE_RUN2 2
#define SPRITE_JUMP 3
#define SPRITE_JUMP_UPPER '.' 
#define SPRITE_JUMP_LOWER 4
#define SPRITE_TERRAIN_EMPTY ' '
#define SPRITE_TERRAIN_SOLID 5
#define SPRITE_TERRAIN_SOLID_RIGHT 6
#define SPRITE_TERRAIN_SOLID_LEFT 7
#define SPRITE_HEART 8

#define HERO_HORIZONTAL_POSITION 1
#define TERRAIN_WIDTH 16
#define TERRAIN_EMPTY 0
#define TERRAIN_LOWER_BLOCK 1

#define HERO_POSITION_OFF 0
#define HERO_POSITION_RUN_LOWER_1 1
#define HERO_POSITION_RUN_LOWER_2 2
#define HERO_POSITION_JUMP_1 3
#define HERO_POSITION_JUMP_2 4
#define HERO_POSITION_JUMP_3 5
#define HERO_POSITION_JUMP_4 6
#define HERO_POSITION_JUMP_5 7
#define HERO_POSITION_JUMP_6 8
#define HERO_POSITION_JUMP_7 9
#define HERO_POSITION_JUMP_8 10
#define HERO_POSITION_RUN_UPPER_1 11
#define HERO_POSITION_RUN_UPPER_2 12

LiquidCrystal lcd(11, 9, 6, 5, 4, 3);
static char terrainUpper[TERRAIN_WIDTH + 1];
static char terrainLower[TERRAIN_WIDTH + 1];
static bool buttonPushed = false;

void initializeGraphics() {
  static byte graphics[] = {
    // Run position 1
    B01100, B01100, B00000, B01110, B11100, B01100, B11010, B10011,
    // Run position 2
    B01100, B01100, B00000, B01100, B01100, B01100, B01100, B01110,
    // Jump
    B01100, B01100, B00000, B11110, B01101, B11111, B10000, B00000,
    // Jump lower
    B11110, B01101, B11111, B10000, B00000, B00000, B00000, B00000,
    // Ground (spike)
    B00100, B00100, B01110, B01110, B11111, B11111, B01110, B00100,
    // Ground right (tapered spike)
    B00000, B00000, B00100, B01110, B01111, B00111, B00010, B00000,
    // Ground left (tapered spike)
    B00000, B00000, B00100, B01110, B11110, B11100, B01000, B00000,
    // Heart
    B00000, B01010, B11111, B11111, B01110, B00100, B00000, B00000
  };
  
  for (int i = 0; i < 8; ++i) {
    lcd.createChar(i + 1, &graphics[i * 8]);
  }
  
  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    terrainUpper[i] = SPRITE_TERRAIN_EMPTY;
    terrainLower[i] = SPRITE_TERRAIN_EMPTY;
  }
}

void advanceTerrain(char* terrain, byte newTerrain) {
  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    char current = terrain[i];
    char next = (i == TERRAIN_WIDTH-1) ? newTerrain : terrain[i+1];
    switch (current) {
      case SPRITE_TERRAIN_EMPTY:
        terrain[i] = (next == SPRITE_TERRAIN_SOLID) ? SPRITE_TERRAIN_SOLID_RIGHT : SPRITE_TERRAIN_EMPTY;
        break;
      case SPRITE_TERRAIN_SOLID:
        terrain[i] = (next == SPRITE_TERRAIN_EMPTY) ? SPRITE_TERRAIN_SOLID_LEFT : SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_RIGHT:
        terrain[i] = SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_LEFT:
        terrain[i] = SPRITE_TERRAIN_EMPTY;
        break;
    }
  }
}

bool drawHero(byte position, char* terrainUpper, char* terrainLower, unsigned int seconds, byte lives) {
  bool collide = false;
  char upperSave = terrainUpper[HERO_HORIZONTAL_POSITION];
  char lowerSave = terrainLower[HERO_HORIZONTAL_POSITION];
  byte upper, lower;
  
  switch (position) {
    case HERO_POSITION_OFF:
      upper = lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_LOWER_1:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN1;
      break;
    case HERO_POSITION_RUN_LOWER_2:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN2;
      break;
    case HERO_POSITION_JUMP_1:
    case HERO_POSITION_JUMP_8:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_JUMP;
      break;
    case HERO_POSITION_JUMP_2:
    case HERO_POSITION_JUMP_7:
      upper = SPRITE_JUMP_UPPER;
      lower = SPRITE_JUMP_LOWER;
      break;
    case HERO_POSITION_JUMP_3:
    case HERO_POSITION_JUMP_4:
    case HERO_POSITION_JUMP_5:
    case HERO_POSITION_JUMP_6:
      upper = SPRITE_JUMP;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_1:
      upper = SPRITE_RUN1;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_2:
      upper = SPRITE_RUN2;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
  }
  
  if (upper != ' ') {
    terrainUpper[HERO_HORIZONTAL_POSITION] = upper;
    collide = (upperSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }
  if (lower != ' ') {
    terrainLower[HERO_HORIZONTAL_POSITION] = lower;
    collide |= (lowerSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }
  
  // Draw hearts on the right side of top row, leaving one space from the right
  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    if (i != HERO_HORIZONTAL_POSITION) { // Preserve hero's sprite
      terrainUpper[i] = (i >= 12 && i < 12 + lives) ? SPRITE_HEART : SPRITE_TERRAIN_EMPTY;
    }
  }
  
  byte digits = (seconds > 9999) ? 5 : (seconds > 999) ? 4 : (seconds > 99) ? 3 : (seconds > 9) ? 2 : 1;
  
  terrainUpper[TERRAIN_WIDTH] = '\0';
  terrainLower[TERRAIN_WIDTH] = '\0';
  char temp = terrainUpper[16-digits];
  terrainUpper[16-digits] = '\0';
  lcd.setCursor(0,0);
  lcd.print(terrainUpper);
  terrainUpper[16-digits] = temp;  
  lcd.setCursor(0,1);
  lcd.print(terrainLower);
  
  lcd.setCursor(16 - digits,0);
  lcd.print(seconds);

  terrainUpper[HERO_HORIZONTAL_POSITION] = upperSave;
  terrainLower[HERO_HORIZONTAL_POSITION] = lowerSave;
  return collide;
}

void buttonPush() {
  buttonPushed = true;
}

void playSoundEffect(byte type) {
  switch(type) {
    case 1: // Jump
      tone(PIN_BUZZER, 1000, 50);
      break;
    case 2: // Game Over
      tone(PIN_BUZZER, 300, 300);
      delay(300);
      tone(PIN_BUZZER, 200, 300);
      delay(300);
      tone(PIN_BUZZER, 100, 300);
      break;
    case 3: // Lose Life
      tone(PIN_BUZZER, 500, 200);
      delay(200);
      tone(PIN_BUZZER, 400, 200);
      break;
  }
}

void showGameOver(unsigned int seconds) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Game Over!");
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(seconds);
  lcd.print("s");
  playSoundEffect(2);
  delay(3000);
}

void setup() {
  pinMode(PIN_READWRITE, OUTPUT);
  digitalWrite(PIN_READWRITE, LOW);
  pinMode(PIN_CONTRAST, OUTPUT);
  digitalWrite(PIN_CONTRAST, LOW);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH);
  pinMode(PIN_AUTOPLAY, OUTPUT);
  digitalWrite(PIN_AUTOPLAY, HIGH);
  pinMode(PIN_BUZZER, OUTPUT);
  
  attachInterrupt(0, buttonPush, FALLING);
  
  initializeGraphics();
  lcd.begin(16, 2);
}

void loop() {
  static byte heroPos = HERO_POSITION_RUN_LOWER_1;
  static byte newTerrainType = TERRAIN_EMPTY;
  static byte newTerrainDuration = 1;
  static bool playing = false;
  static bool blink = false;
  static unsigned long startTime = 0;
  static unsigned int seconds = 0;
  static byte lives = 3;
  static int gameDelay = 60; // Initial delay (slower)
  static unsigned int lastSpeedIncrease = 0;
  
  if (!playing) {
    drawHero((blink) ? HERO_POSITION_OFF : heroPos, terrainUpper, terrainLower, seconds, lives);
    if (blink) {
      lcd.setCursor(0,0);
      lcd.print("Welcome");
    }
    delay(250);
    blink = !blink;
    if (buttonPushed) {
      initializeGraphics();
      heroPos = HERO_POSITION_RUN_LOWER_1;
      playing = true;
      buttonPushed = false;
      startTime = millis();
      seconds = 0;
      lives = 3;
      gameDelay = 60; // Reset delay
      lastSpeedIncrease = 0;
    }
    return;
  }

  seconds = (millis() - startTime) / 1000;

  // Increase speed every 100 seconds
  if (seconds >= lastSpeedIncrease + 100 && gameDelay > 30) {
    gameDelay -= 5; // Decrease delay by 5ms
    lastSpeedIncrease = seconds;
  }

  advanceTerrain(terrainLower, newTerrainType == TERRAIN_LOWER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);
  
  if (--newTerrainDuration == 0) {
    if (newTerrainType == TERRAIN_EMPTY) {
      newTerrainType = TERRAIN_LOWER_BLOCK;
      newTerrainDuration = random(2) + 1; // 1 or 2 spikes
    } else {
      newTerrainType = TERRAIN_EMPTY;
      newTerrainDuration = 10 + random(10);
    }
  }
    
  if (buttonPushed) {
    if (heroPos <= HERO_POSITION_RUN_LOWER_2) {
      heroPos = HERO_POSITION_JUMP_1;
      playSoundEffect(1);
    }
    buttonPushed = false;
  }

  if (drawHero(heroPos, terrainUpper, terrainLower, seconds, lives)) {
    lives--;
    playSoundEffect(3);
    if (lives == 0) {
      showGameOver(seconds);
      playing = false;
    } else {
      // Reset hero position after losing a life
      heroPos = HERO_POSITION_RUN_LOWER_1;
      // Clear terrain to give player a chance to recover
      for (int i = 0; i < TERRAIN_WIDTH; ++i) {
        terrainLower[i] = SPRITE_TERRAIN_EMPTY;
      }
      delay(500);
    }
  } else {
    if (heroPos == HERO_POSITION_RUN_LOWER_2 || heroPos == HERO_POSITION_JUMP_8) {
      heroPos = HERO_POSITION_RUN_LOWER_1;
    } else if ((heroPos >= HERO_POSITION_JUMP_3 && heroPos <= HERO_POSITION_JUMP_5) && 
               terrainLower[HERO_HORIZONTAL_POSITION] != SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else if (heroPos >= HERO_POSITION_RUN_UPPER_1 && 
               terrainLower[HERO_HORIZONTAL_POSITION] == SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_JUMP_5;
    } else if (heroPos == HERO_POSITION_RUN_UPPER_2) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else {
      ++heroPos;
    }
    
    digitalWrite(PIN_AUTOPLAY, terrainLower[HERO_HORIZONTAL_POSITION + 2] == SPRITE_TERRAIN_EMPTY ? HIGH : LOW);
  }
  
  delay(gameDelay); // Dynamic delay for speed adjustment
}