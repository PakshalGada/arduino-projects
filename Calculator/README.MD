# 🧮 Arduino Keypad Calculator 🧮

Hello everyone! 👋 Today, we’ll build a keypad calculator using Arduino—one of my bigger projects! This calculator uses a keypad for input, performs basic arithmetic operations, and displays the results on an LCD screen. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **4x4 Keypad** (For entering numbers and operations ⌨️)
- **16x2 LCD Display** (To show the calculations 📟)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections)
- **Computer** (To upload the code and monitor Serial output 💻)

---

## 💡 How It Works

This project turns your Arduino into a basic calculator. You use a 4x4 keypad to enter numbers and operations (like addition or subtraction), and the results are shown on a 16x2 LCD display. The Arduino processes the inputs, performs the calculation, and updates the LCD with the equation and result. It’s a great way to learn about keypads, LCDs, and basic programming logic! 📘

### 🔧 How the Keypad and LCD Work

- **Keypad**: The 4x4 keypad has 16 keys arranged in rows and columns. Each key press connects a row and column, which the Arduino detects using the `Keypad` library. In this project, numbers (0-9) are used to build multi-digit numbers, and letters (A, B, C, D) select operations (addition, subtraction, multiplication, division). The  key resets the calculator, and `#` calculates the result. ⌨️
- **LCD Display**: The 16x2 LCD display shows 16 characters across 2 lines. It’s connected to the Arduino using pins for data and control (RS, EN, D4-D7). The `LiquidCrystal` library handles communication, displaying the equation on the first line (e.g., “5+3”) and the current number or result on the second line (e.g., “8”). 📟

---

## 💻 The Code

Here’s the code for the Arduino keypad calculator. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '7', '8', '9', 'B' },
  { '4', '5', '6', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 0, 1, 2, 3 };
byte colPins[COLS] = { 4, 5, 6, 7 };

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("DIY Calculator");
  lcd.setCursor(0, 1);
  lcd.print("-Pakshal Gada");

  delay(2000);
  lcd.clear();
}

void loop() {
  key = kpd.getKey();

  if (key != NO_KEY)
    DetectButtons();

  if (result == true)
    CalculateResult();

  DisplayResult();
}

void DetectButtons() {
  lcd.clear();
  if (key == '*') {
    Serial.println("Button Cancel");
    Number = Num1 = Num2 = 0;
    result = false;
  }

  if (key == '1') {
    Serial.println("Button 1");
    if (Number == 0)
      Number = 1;
    else
      Number = (Number * 10) + 1;
  }

  if (key == '4') {
    Serial.println("Button 4");
    if (Number == 0)
      Number = 4;
    else
      Number = (Number * 10) + 4;
  }

  if (key == '7') {
    Serial.println("Button 7");
    if (Number == 0)
      Number = 7;
    else
      Number = (Number * 10) + 7;
  }

  if (key == '0') {
    Serial.println("Button 0");
    if (Number == 0)
      Number = 0;
    else
      Number = (Number * 10) + 0;
  }

  if (key == '2') {
    Serial.println("Button 2");
    if (Number == 0)
      Number = 2;
    else
      Number = (Number * 10) + 2;
  }

  if (key == '5') {
    Serial.println("Button 5");
    if (Number == 0)
      Number = 5;
    else
      Number = (Number * 10) + 5;
  }

  if (key == '8') {
    Serial.println("Button 8");
    if (Number == 0)
      Number = 8;
    else
      Number = (Number * 10) + 8;
  }

  if (key == '#') {
    Serial.println("Button Equal");
    Num2 = Number;
    result = true;
  }

  if (key == '3') {
    Serial.println("Button 3");
    if (Number == 0)
      Number = 3;
    else
      Number = (Number * 10) + 3;
  }

  if (key == '6') {
    Serial.println("Button 6");
    if (Number == 0)
      Number = 6;
    else
      Number = (Number * 10) + 6;
  }

  if (key == '9') {
    Serial.println("Button 9");
    if (Number == 0)
      Number = 9;
    else
      Number = (Number * 10) + 9;
  }

  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
    Num1 = Number;
    Number = 0;
    if (key == 'A') {
      Serial.println("Addition");
      action = '+';
    }
    if (key == 'B') {
      Serial.println("Subtraction");
      action = '-';
    }
    if (key == 'C') {
      Serial.println("Multiplication");
      action = '*';
    }
    if (key == 'D') {
      Serial.println("Devesion");
      action = '/';
    }
    delay(100);
  }
}

void CalculateResult() {
  if (action == '+')
    Number = Num1 + Num2;

  if (action == '-')
    Number = Num1 - Num2;

  if (action == '*')
    Number = Num1 * Num2;

  if (action == '/')
    Number = Num1 / Num2;
}

void DisplayResult() {
  lcd.setCursor(0, 0);
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if (result == true) {
    lcd.print(" =");
    lcd.print(Number);
  }
  lcd.setCursor(0, 1);
  lcd.print(Number);
}

```

What does this code do? 🤔

- It includes the `LiquidCrystal` and `Keypad` libraries to control the LCD and keypad.
- It sets up the keypad pins (0-7) and LCD pins (8-13), defining the key layout for numbers and operations.
- The `setup()` function initializes the LCD and displays an intro message for 2 seconds.
- The `loop()` function reads key presses, processes them to build numbers and select operations, performs calculations, and updates the LCD with the equation and result. 💡

---

## 🔧 Set It Up

1. Connect the 4x4 keypad to the Arduino: row pins to 0, 1, 2, 3, and column pins to 4, 5, 6, 7.
2. Connect the 16x2 LCD: RS to pin 8, EN to pin 9, D4 to pin 10, D5 to pin 11, D6 to pin 12, D7 to pin 13, VCC to 5V, and GND to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then use the keypad to enter numbers and operations (e.g., press 5, A, 3, # to calculate 5 + 3).
5. Watch the LCD display the equation and result! ✨


---

## 🎥 See It in Action

I made a video to show the Arduino keypad calculator working. Enter numbers and operations on the keypad, and the LCD will display the equation and result! Check it out below:

https://youtu.be/BF5rA4sB3LY

---

## 🌟 Why This Project Is Great

- It’s a practical way to learn about keypads, LCDs, and Arduino programming. 📚
- You can perform real calculations with a custom-built device. 💡
- It’s a bigger project that combines multiple components—perfect for advancing your skills. 🌱

---

## 🚀 What’s Next?

You can add more operations, like square roots or percentages. Or, try adding a buzzer to play a sound when a calculation is complete.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
