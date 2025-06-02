# 🏃‍♂️ Arduino Runner Game 🏃‍♂️

Hello everyone! 👋 Today, we’ll build an exciting Runner Game using Arduino—one of my bigger projects! This game uses an LCD to display a running character, a button to make the character jump over obstacles, and a buzzer for sound effects. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:2 in last 28 days

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **16x2 LCD Display** (To show the game 📟)
- **Push Button** (To make the character jump 🔘)
- **Buzzer** (For sound effects 🔊)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections 🌈)

---

## 💡 How It Works

This project is a simple endless runner game displayed on a 16x2 LCD. You control a character that runs and jumps over obstacles (spikes). Press the button to jump, and the game keeps track of your time (score) and lives (shown as hearts). If you hit an obstacle, you lose a life, and the buzzer plays a sound. The game speeds up over time, making it more challenging. When you lose all lives, the game ends, showing your final time. It’s a fun way to learn about game programming with Arduino! 📘

### 🔧 How the LCD, Button, and Buzzer Work

- **LCD Display**: The 16x2 LCD shows 16 characters across 2 lines. It’s connected to the Arduino using pins (11, 9, 6, 5, 4, 3). The `LiquidCrystal` library handles the display, showing the character, obstacles, lives (hearts), and time. Custom sprites (like the running character and spikes) are created using `lcd.createChar()`. 📟
- **Button**: The button is connected to pin 2 and uses an interrupt to detect presses. When pressed, it triggers the `buttonPush()` function, making the character jump. This allows precise control without delaying the game loop. 🔘
- **Buzzer**: The buzzer, connected to pin 8, plays sound effects using the `tone()` function. It makes a high-pitched sound when jumping, a descending tone for game over, and a short tone when losing a life, adding an audio element to the game. 🔊


## 💻 The Code

Here’s the code for the Arduino Runner Game. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
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
    B01100, B01100, B00000, B01110, B11100, B01100, B11010, B10011,
    B01100, B01100, B00000, B01100, B01100, B01100, B01100, B01110,
    B01100, B01100, B00000, B11110, B01101, B11111, B10000, B00000,
    B11110, B01101, B11111, B10000, B00000, B00000, B00000, B00000,
    B00100, B00100, B01110, B01110, B11111, B11111, B01110, B00100,
    B00000, B00000, B00100, B01110, B01111, B00111, B00010, B00000,
    B00000, B00000, B00100, B01110, B11110, B11100, B01000, B00000,
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

  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    if (i != HERO_HORIZONTAL_POSITION) {
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
    case 1:
      tone(PIN_BUZZER, 1000, 50);
      break;
    case 2:
      tone(PIN_BUZZER, 300, 300);
      delay(300);
      tone(PIN_BUZZER, 200, 300);
      delay(300);
      tone(PIN_BUZZER, 100, 300);
      break;
    case 3:
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
  static int gameDelay = 60;
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
      gameDelay = 60;
      lastSpeedIncrease = 0;
    }
    return;
  }

  seconds = (millis() - startTime) / 1000;

  if (seconds >= lastSpeedIncrease + 100 && gameDelay > 30) {
    gameDelay -= 5;
    lastSpeedIncrease = seconds;
  }

  advanceTerrain(terrainLower, newTerrainType == TERRAIN_LOWER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);

  if (--newTerrainDuration == 0) {
    if (newTerrainType == TERRAIN_EMPTY) {
      newTerrainType = TERRAIN_LOWER_BLOCK;
      newTerrainDuration = random(2) + 1;
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
      heroPos = HERO_POSITION_RUN_LOWER_1;
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

  delay(gameDelay);
}

```

What does this code do? 🤔

- It includes the `LiquidCrystal` library to control the LCD and defines pins for the button, buzzer, and LCD.
- It creates custom sprites for the character (running, jumping), terrain (spikes), and hearts (lives) using `initializeGraphics()`.
- The `loop()` function manages the game state: it starts with a “Welcome” screen, begins the game when the button is pressed, updates the terrain, handles jumping, checks for collisions, and adjusts the game speed over time.
- The `drawHero()` function updates the LCD with the character’s position, obstacles, lives, and time, while `playSoundEffect()` adds audio feedback. 💡

---

## 🔧 Set It Up

1. Connect the 16x2 LCD to the Arduino: RS to pin 11, EN to pin 9, D4 to pin 6, D5 to pin 5, D6 to pin 4, D7 to pin 3, VCC to 5V, and GND to GND. Also, connect RW to pin 10 and contrast (via a potentiometer) to pin 12.
2. Connect the button to pin 2: one side to pin 2, the other to GND.
3. Connect the buzzer to pin 8: one side to pin 8, the other to GND.
4. Plug your Arduino into your computer with a USB cable. ⚡
5. Upload the code, then press the button to start the game. Press the button again to jump over obstacles and keep running as long as you can! ✨


## 🎥 See It in Action

I made a video to show the Arduino Runner Game in action. Press the button to jump over spikes, and try to survive as long as possible while the game gets faster! Check it out below:

https://youtu.be/2piSWefmyrA

---

## 🌟 Why This Project Is Great

- It’s a fun way to learn about game development with Arduino, using sprites and dynamic gameplay. 📚
- You can see how to combine inputs (button), outputs (LCD, buzzer), and logic to create an interactive game. 💡
- It’s a bigger project that challenges your skills—a perfect step up for enthusiasts. 🌱

---

## 🚀 What’s Next?

You can add more obstacle types or power-ups (like extra lives). Or, try saving the high score to EEPROM so it persists after the game ends.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
