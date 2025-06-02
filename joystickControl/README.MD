# 🕹️ Joystick Controller with Arduino 🕹️

Hello everyone! 👋 Today, we’ll make a joystick controller project using Arduino. This project reads the position of a joystick and its button state, then displays the values in the Serial Monitor. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Joystick Module** (With X, Y, and switch outputs 🕹️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Computer** (To see joystick values in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses a joystick module to read three values: the X-axis position, the Y-axis position, and the state of the built-in button (switch). The Arduino reads these values and prints them to the Serial Monitor, so you can see how the joystick moves and if the button is pressed. It’s a great way to learn about analog and digital inputs! 📘

### 🔧 How the Joystick Module Works

The main component in this project is the joystick module. It has three outputs:

- **X-axis (A0)**: This is connected to a potentiometer that measures horizontal movement. It gives an analog value (0 to 1023) using `analogRead()`. When the joystick is centered, the value is around 512.
- **Y-axis (A1)**: This is another potentiometer for vertical movement, also giving a value from 0 to 1023.
- **Switch (Pin 2)**: This is a push button built into the joystick. When you press the joystick down, it acts like a button. It’s set up with a pull-up resistor (using `INPUT_PULLUP`), so it reads `HIGH` when not pressed and `LOW` when pressed. The Arduino reads this with `digitalRead()`. 🔄

---

## 💻 The Code

Here’s the code for the joystick controller. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
int xpin = A0;
int ypin = A1;
int spin = 2;
int xval;
int yval;
int sval;
int dt = 200;

void setup() {
  Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(spin, INPUT);
  digitalWrite(spin, HIGH);
}

void loop() {
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  sval = digitalRead(spin);
  delay(dt);

  Serial.print("X Value= ");
  Serial.print(xval);
  Serial.print(" Y Value= ");
  Serial.print(yval);
  Serial.print(" Switch State = ");
  Serial.println(sval);
}

```

What does this code do? 🤔

- It sets pins A0 for the X-axis, A1 for the Y-axis, and pin 2 for the switch.
- The `setup()` function starts Serial communication and sets the pin modes. The switch pin uses a pull-up resistor.
- The `loop()` function reads the X and Y values (0 to 1023) and the switch state (`HIGH` or `LOW`), then prints them to the Serial Monitor.
- `delay(200)` waits 200 milliseconds between readings. ⏳

---

## 🔧 Set It Up

1. Connect the joystick module to the Arduino: X-axis to pin A0, Y-axis to pin A1, and the switch to pin 2.
2. Connect the VCC pin of the joystick module to 5V and the GND pin to GND on the Arduino.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE to see the joystick values.
5. Move the joystick and press it to see the values change! ✨

---

## 🎥 See It in Action

I made a video to show the joystick controller working. Move the joystick and press it, and the values will show up in the Serial Monitor! Check it out below:

https://youtube.com/shorts/NpX8QHpw6is?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about joysticks and analog inputs. 📚
- You can see how Arduino reads both analog and digital signals. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can use the joystick values to control something, like a servo motor or an LED’s brightness. Or, try adding more features, like turning on an LED when the joystick button is pressed.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
