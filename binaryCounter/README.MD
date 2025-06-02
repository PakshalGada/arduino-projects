# 🔢 Binary Counter with Arduino 🔢

Hello everyone! 👋 Today, we’ll make a binary counter using Arduino. It will count from 0 to 15 in binary using four LEDs. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **4 LEDs** (Any color, I used red ones ❤️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each LED ⚡)

---

## 💡 How It Works

This project uses four LEDs to show numbers in binary. Each LED represents a bit (0 or 1). We’ll count from 0 (all LEDs off) to 15 (all LEDs on). The Arduino turns the LEDs on and off in the right order to show the binary numbers. It’s a great way to learn about binary! 📘


## 💻 The Code

Here’s the code for the binary counter. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
int pin2 = 5;
int pin3 = 4;
int pin4 = 3;
int pin5 = 2;
int del = 750;

void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pin4(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void loop() {
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  delay(del);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  delay(del);
}
[Insert YouTube Video Here]
```

What does this code do? 🤔

- It sets pins 2, 3, 4, and 5 as outputs for the LEDs.
- The `loop()` function turns the LEDs on and off to count from 0 to 15 in binary.
- `delay(750)` makes each number stay on for 750 milliseconds so you can see it. ⏳

---

## 🔧 Set It Up

1. Connect the LEDs to pins 2, 3, 4, and 5 on the Arduino. Use a 220-ohm resistor for each LED.
2. Connect the other side of each LED to GND on the breadboard.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, and watch the LEDs count in binary! ✨

## 🎥 See It in Action

I made a video to show the binary counter working. The LEDs will light up to show the numbers 0 to 15 in binary. Check it out below:

https://youtube.com/shorts/Q0H4jQZGqkw?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about binary numbers. 📚
- You can see how Arduino controls LEDs. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more LEDs to count higher numbers. Or, try changing the delay time to make the counter faster or slower.

Happy building !🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
