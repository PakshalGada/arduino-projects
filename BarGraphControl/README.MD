# 📊 Bar Graph Control with Arduino 📊

Hello everyone! 👋 Today, we’ll make a bar graph control project using Arduino. This project uses a potentiometer to control a bar graph made of 10 LEDs, lighting up more LEDs as you turn the knob. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Potentiometer** (To control the bar graph 🎛️)
- **10 LEDs** (Any color, I used red ones ❤️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each LED ⚡)

---

## 💡 How It Works

This project uses a potentiometer to control a bar graph display made of 10 LEDs. As you turn the potentiometer knob, the Arduino reads its value and lights up a number of LEDs proportional to the value, creating a bar graph effect. It’s a great way to learn about analog inputs and LED control! 📘

### 🔧 How the Potentiometer Works

The main component in this project is the potentiometer. A potentiometer is a variable resistor with three pins: two outer pins connect to 5V and GND, and the middle pin (connected to A0) outputs a voltage between 0V and 5V depending on the knob’s position. The Arduino reads this voltage as an analog value (0 to 1023) using `analogRead()`. The code then maps this value to a range of 0 to 10 to determine how many LEDs to light up. 🔄


---

## 💻 The Code

Here’s the code for the bar graph control. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
const int BARGRAPHSIZE = 10;
const int POTINPUT = A0;

int barPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

int potValue = 0;

void setup() {
  for(int barSegment = 0; barSegment < BARGRAPHSIZE; barSegment++) {
    pinMode(barPins[barSegment], OUTPUT);
    digitalWrite(barPins[barSegment], LOW);
  }
}

void loop() {
  potValue = analogRead(POTINPUT);
  int barLevel = map(potValue, 0, 1023, 0, BARGRAPHSIZE);

  for(int barSegment = 0; barSegment < BARGRAPHSIZE; barSegment++) {
    if (barSegment < barLevel) {
      digitalWrite(barPins[barSegment], HIGH);
    }
    else {
      digitalWrite(barPins[barSegment], LOW);
    }
  }
}

```

What does this code do? 🤔

- It sets up an array of pins (2 to 11) for the 10 LEDs and pin A0 for the potentiometer.
- The `setup()` function sets all LED pins as outputs and turns them off.
- The `loop()` function reads the potentiometer value, maps it to a range of 0 to 10, and lights up the corresponding number of LEDs.
- LEDs turn on sequentially to create a bar graph effect. 💡

---

## 🔧 Set It Up

1. Connect the 10 LEDs to pins 2 through 11 on the Arduino. Use a 220-ohm resistor for each LED and connect the other side to GND.
2. Connect the potentiometer: one outer pin to 5V, the other to GND, and the middle pin to A0.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then turn the potentiometer knob to see the bar graph change! ✨


---

## 🎥 See It in Action

I made a video to show the bar graph control working. Turn the potentiometer, and the number of lit LEDs will change to form a bar graph! Check it out below:

https://youtube.com/shorts/jH9700pNOSY?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about potentiometers and analog inputs. 📚
- You can see how Arduino maps values to control multiple LEDs. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more LEDs to make a longer bar graph. Or, try using the bar graph to display other sensor values, like temperature or light levels.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
