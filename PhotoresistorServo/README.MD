# 🌞 Photoresistor Servo Controller with Arduino 🌞

Hello everyone! 👋 Today, we’ll make a photoresistor servo controller using Arduino. This project uses light to control the position of a servo motor. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Photoresistor** (To sense light 🌞)
- **Servo Motor** (To move based on light 🤖)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistor** (10k ohm for the photoresistor ⚡)
- **Computer** (To see light values in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses a photoresistor to detect light levels. The Arduino reads the light level and moves a servo motor to an angle based on the light. The brighter the light, the more the servo moves! It’s a great way to learn about sensors and motors! 📘

### 🔧 How the Photoresistor and Servo Motor Work

- **Photoresistor**: This is a light sensor. It changes its resistance based on the amount of light it detects. In bright light, its resistance is low, and in darkness, its resistance is high. The Arduino reads this as a value (0 to 1023) using `analogRead()` on pin A4. 🌅
- **Servo Motor**: This is a small motor that can rotate to a specific angle (0 to 180 degrees). It’s controlled by the Arduino using the `Servo` library. The code calculates an angle based on the light value and moves the servo to that angle using `servo.write()`. In this project, the angle is calculated with the formula `angle = (-16./63.) * lightVal + 16.*780./63.`, which maps the light value to an angle between 0 and 180 degrees. 🤖

## 💻 The Code

Here’s the code for the photoresistor servo controller. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
#include <Servo.h>
int servoPin = 10;
int lightVal;
int lightPin = A4;
int dt = 250;
int angle;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);
  angle = (-16./63.) * lightVal + 16.*780./63.;
  servo.write(angle);
}

```

What does this code do? 🤔

- It includes the `Servo` library to control the servo motor.
- It sets pin A4 for the photoresistor and pin 10 for the servo.
- The `setup()` function starts Serial communication and attaches the servo to pin 10.
- The `loop()` function reads the light value, prints it, calculates the angle, and moves the servo to that angle.
- `delay(250)` waits 250 milliseconds between readings. ⏳

---

## 🔧 Set It Up

1. Connect the photoresistor to pin A4 on the Arduino. Use a 10k ohm resistor between one leg of the photoresistor and GND, and connect the other leg to 5V.
2. Connect the servo motor to the Arduino: the signal wire to pin 10, the power wire to 5V, and the ground wire to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE to see the light values.
5. Shine a light on the photoresistor or cover it to see the servo move! ✨

- --

## 🎥 See It in Action

I made a video to show the photoresistor servo controller working. Shine a light on the photoresistor, and the servo moves to a new angle. Cover it, and it moves back! Check it out below:

https://youtube.com/shorts/Hb0FMcXCgGU?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about photoresistors and servo motors. 📚
- You can see how Arduino uses sensor data to control movement. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can change the angle formula to adjust how the servo moves with light. Or, try using the servo to move something, like a small flag, based on the light level.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
