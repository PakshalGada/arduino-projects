# 🌞 Photoresistor LED Controller with Arduino 🌞

Hello everyone! 👋 Today, we’ll make a photoresistor LED controller using Arduino. This project uses light to control two LEDs—one red and one green. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Photoresistor** (To sense light 🌞)
- **2 LEDs** (One red, one green 🌟)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each LED, 10k ohm for the photoresistor ⚡)
- **Computer** (To see light values in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses a photoresistor to detect light levels. The Arduino reads the light level and turns on either the green LED (if it’s bright) or the red LED (if it’s dark). It’s a great way to learn about sensors! 📘

### 🔧 How the Photoresistor Works

The main component in this project is the photoresistor. A photoresistor is a sensor that changes its resistance based on the amount of light it detects. When it’s bright, its resistance decreases, and when it’s dark, its resistance increases. In this project, the photoresistor is connected to analog pin A0. The Arduino reads the light value (from 0 to 1023) using `analogRead()`. If the value is above 350 (bright), the green LED turns on. If it’s 350 or below (dark), the red LED turns on. 🌅

- --

## 💻 The Code

Here’s the code for the photoresistor LED controller. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
int lightPen = A0;
int lightVal;
int dv = 250;
int redPin = 9;
int greenPin = 8;

void setup() {
  pinMode(lightPen, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv);
  if (lightVal > 350) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  if (lightVal <= 350) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
}

```

What does this code do? 🤔

- It sets pin A0 for the photoresistor, pin 9 for the red LED, and pin 8 for the green LED.
- The `setup()` function starts Serial communication to show light values.
- The `loop()` function reads the light value, prints it, and decides which LED to turn on based on the light level.
- `delay(250)` waits 250 milliseconds between readings. ⏳

---

## 🔧 Set It Up

1. Connect the photoresistor to pin A0 on the Arduino. Use a 10k ohm resistor between one leg of the photoresistor and GND, and connect the other leg to 5V.
2. Connect the red LED to pin 9 and the green LED to pin 8. Use a 220-ohm resistor for each LED, and connect the other side to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE to see the light values.
5. Shine a light on the photoresistor or cover it to see the LEDs change! ✨

## 🎥 See It in Action

I made a video to show the photoresistor LED controller working. Shine a light on the photoresistor, and the green LED turns on. Cover it, and the red LED turns on! Check it out below:

https://youtu.be/Jvw4l-x8ayQ

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about photoresistors and light sensing. 📚
- You can see how Arduino reads sensor data and controls LEDs. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can change the threshold value (350) to make the LEDs switch at different light levels. Or, try adding more LEDs for different light ranges.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
