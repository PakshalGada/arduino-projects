# 🔘 Button-Controlled LED with Arduino (v1) 🔘

Hello everyone! 👋 Today, we’ll make a simple button-controlled LED project using Arduino. In this version, the LED stays on only while the button is pressed. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Push Button** (To control the LED 🔘)
- **LED** (Any color, I used a red one ❤️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistor** (220 ohms for the LED ⚡)

---

## 💡 How It Works

This project uses a button to control an LED. When you press the button, the LED turns on. When you release the button, the LED turns off. It’s a great way to learn about buttons and digital inputs! 📘

### 🔧 How the Button Works

The main component in this project is the push button. A button is a simple switch that connects or breaks a circuit. When you press it, it connects two pins, allowing current to flow. In this project, the button is connected to pin 2 with an internal pull-up resistor (using `INPUT_PULLUP`). This means the pin reads `HIGH` when the button is not pressed and `LOW` when it is pressed. The Arduino checks this state and turns the LED on or off accordingly. 🔄


---

## 💻 The Code

Here’s the code for the button-controlled LED. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
const int buttonPin = 2; // Button connected to pin 2
const int ledPin = 13;  // LED connected to pin 13

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the button state

  if (buttonState == LOW) { // Button is pressed (LOW because of INPUT_PULLUP)
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }
}

```

What does this code do? 🤔

- It sets pin 2 for the button and pin 13 for the LED.
- The `setup()` function sets the button pin as an input with a pull-up resistor and the LED pin as an output.
- The `loop()` function reads the button state and turns the LED on when the button is pressed (`LOW`) and off when it’s released (`HIGH`). 💡

---

## 🔧 Set It Up

1. Connect the LED to pin 13 on the Arduino. Use a 220-ohm resistor and connect the other side to GND.
2. Connect the button to pin 2. One side of the button goes to pin 2, and the other side goes to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then press the button to see the LED light up! ✨

---

## 🎥 See It in Action

I made a video to show the button-controlled LED working. Press the button, and the LED turns on. Release it, and the LED turns off! Check it out below:

https://youtube.com/shorts/tJtCR7U3Dnw?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about buttons and digital inputs. 📚
- You can see how Arduino reads a button to control an LED. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more LEDs to control with the same button. Or, try making the LED toggle on and off with each button press (a future version!).

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
