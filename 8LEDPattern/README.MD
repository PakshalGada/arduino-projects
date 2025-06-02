# 💡 8 LED Pattern and Binary Counter with Arduino 💡

Hello everyone! 👋 Today, we’ll explore two projects using Arduino and a shift register to control 8 LEDs: a simple LED pattern and a binary counter. Both projects use the same hardware setup but have different codes to create unique effects. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for both projects:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **74HC595 Shift Register** (To control 8 LEDs with fewer pins 📡)
- **8 LEDs** (Any color, I used red ones ❤️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each LED ⚡)
- **Computer** (To see the counter values in the Serial Monitor for the binary counter project 💻)

---

## 💡 How It Works

Both projects use a 74HC595 shift register to control 8 LEDs with just 3 pins on the Arduino. The first project creates a simple pattern by lighting up one LED at a time in a sequence. The second project works as a binary counter, counting from 0 to 255 in binary and displaying the numbers on the LEDs. These projects are great for learning about shift registers and binary numbers! 📘

### 🔧 How the Shift Register Works

The main component in both projects is the 74HC595 shift register. A shift register lets you control many outputs (like LEDs) using fewer pins on the Arduino. It works by receiving data serially (one bit at a time) and then outputting it to 8 pins at once. Here’s how the pins work:

- **Data Pin (12)** sends the binary data to the shift register.
- **Clock Pin (9)** tells the shift register when to read each bit.
- **Latch Pin (11)** updates the outputs to show the new pattern or number. In the pattern project, the code sends a byte (like `0b10000000`) to light one LED at a time. In the binary counter project, it sends a byte that increments by 1 each time (from `0b00000000` to `0b11111111`), showing the count on the LEDs. 🔄


## 💻 The Code

### Code 1: Simple LED Pattern

This code lights up one LED at a time in a sequence, moving from the first LED to the last.

```cpp
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 100;
byte LEDs1 = 0b10000000;
byte LEDs2 = 0b01000000;
byte LEDs3 = 0b00100000;
byte LEDs4 = 0b00010000;
byte LEDs5 = 0b00001000;
byte LEDs6 = 0b00000100;
byte LEDs7 = 0b00000010;
byte LEDs8 = 0b00000001;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs1);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs2);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs3);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs4);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs5);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs6);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs7);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs8);
  digitalWrite(latchPin, HIGH);
  delay(dt);
}

```

What does this code do? 🤔

- It sets pins 11 (latch), 9 (clock), and 12 (data) for the shift register.
- It defines 8 binary patterns, each lighting one LED (e.g., `0b10000000` for the first LED).
- The `loop()` function sends each pattern to the shift register using `shiftOut()`, lighting one LED at a time.
- `delay(100)` waits 100 milliseconds between each step. ⏳

### Code 2: Binary Counter

This code counts from 0 to 255 in binary, showing the numbers on the 8 LEDs.

```cpp
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 1000;
byte LEDs1 = 0b00000000;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  Serial.println(LEDs1, BIN);
  LEDs1 = LEDs1 + 1;
}

```

What does this code do? 🤔

- It sets pins 11 (latch), 9 (clock), and 12 (data) for the shift register.
- It starts with a binary value of `0b00000000` (all LEDs off).
- The `loop()` function sends the current value to the shift register, prints it to the Serial Monitor, and increments the value by 1.
- `delay(1000)` waits 1 second between each count. ⏳

---

## 🔧 Set It Up

The setup is the same for both projects:

1. Connect the 74HC595 shift register to the Arduino: latch pin to 11, clock pin to 9, and data pin to 12.
2. Connect the 8 output pins of the shift register (Q0 to Q7) to the 8 LEDs through 220-ohm resistors, then to GND.
3. Power the shift register with 5V and GND from the Arduino.
4. Plug your Arduino into your computer with a USB cable. ⚡
5. Upload the code for the project you want to try:
    - For the LED pattern, upload the first code and watch the LEDs light up one by one.
    - For the binary counter, upload the second code, open the Serial Monitor (Tools > Serial Monitor), and watch the LEDs count in binary! ✨

## 🎥 See It in Action

I made a video to show 8 LED Pattern ! Check it out below:

https://youtube.com/shorts/_537naSRKf0?feature=share

---

## **🌟 Why These Projects Are Great**

- They’re a simple way to learn about shift registers and binary numbers. 📚
- You can control many LEDs with just a few pins. 💡
- They’re good projects for beginners to try. 🌱

---

## 🚀 What’s Next?

You can combine both ideas to create a pattern that counts in binary. Or, try adding a button to control the speed of the pattern or counter.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
