# 🔢 7-Segment Counter with Arduino 🔢

Hello everyone! 👋 Today, we’ll make a 7-segment counter using Arduino. It will count from 0 to 9 on a 7-segment display. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **7-Segment Display** (Common cathode type 📟)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each segment ⚡)

---

## 💡 How It Works

This project uses a 7-segment display to show numbers from 0 to 9. Each segment of the display is connected to an Arduino pin. The Arduino turns the segments on and off to show each number. It counts up every second. It’s a great way to learn about 7-segment displays! 📘

The 7 segments are labeled 2 to 8:

- 2: Top horizontal segment
- 3: Top-right vertical segment
- 4: Bottom-right vertical segment
- 5: Bottom horizontal segment
- 6: Bottom-left vertical segment
- 7: Top-left vertical segment
- 8: Middle horizontal segment

Here’s how they’re arranged:

   1
6    2
   7
5    3
   4

Here’s the circuit diagram to help you connect everything:


---

## 💻 The Code

Here’s the code for the 7-segment counter. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // Number 0
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  // Number 1
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);

  // Number 2
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 3
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 4
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 5
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 6
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 7
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);

  // Number 8
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

  // Number 9
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

```

What does this code do? 🤔

- It sets pins 2 to 8 as outputs for the 7-segment display segments.
- The `loop()` function turns the segments on and off to show numbers 0 to 9.
- `delay(1000)` makes each number stay on for 1 second. ⏳

---

## 🔧 Set It Up

1. Connect the 7-segment display to pins 2 to 8 on the Arduino. Use a 220-ohm resistor for each segment.
2. If you’re using a common cathode display, connect the common pin to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, and watch the display count from 0 to 9! ✨

---

## 🎥 See It in Action

I made a video to show the 7-segment counter working. The display will show numbers 0 to 9 one by one. Check it out below:

https://youtube.com/shorts/AggaK7euHAE?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about 7-segment displays. 📚
- You can see how Arduino controls multiple pins. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add a button to control the counting. Or, try adding a second 7-segment display to count higher numbers.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
