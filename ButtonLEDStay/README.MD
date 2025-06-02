# 🔘 Button-Controlled LED with Arduino (v2) 🔘

Hello everyone! 👋 Today, we’ll make a button-controlled LED project using Arduino. In this version (v2), the LED toggles on or off each time you press the button, and it stays in that state until you press the button again. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **Push Button** (To control the LED 🔘)
- **LED** (Any color, I used a red one ❤️ -❤️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistor** (220 ohms for the LED ⚡)
- **Computer** (To see button states in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses a button to toggle an LED on or off. Each time you press the button, the LED switches its state (on to off, or off to on) and stays that way until the button is pressed again. It’s a great way to learn about buttons and toggling states! 📘

### 🔧 How the Button Works

The main component in this project is the push button. A button is a simple switch that connects or breaks a circuit. When you press it, it connects two pins, allowing current to flow. In this project, the button is connected to pin 2 with an internal pull-up resistor (using `INPUT_PULLUP`). This means the pin reads `HIGH` when the button is not pressed and `LOW` when it is pressed. The Arduino detects this change and toggles the LED state each time the button is pressed. 🔄

---

## 💻 The Code

Here’s the code for the button-controlled LED (v2). Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
const int buttonPin = 2;  // Button connected to pin 2
const int ledPin = 13;    // LED connected to pin 13
int buttonValue;
int ledState = LOW;       // Tracks the LED state (on or off)
int lastButtonState = HIGH; // Tracks the previous button state for debouncing
int dt = 100;             // Delay time for debouncing

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
  digitalWrite(ledPin, ledState);   // Set initial LED state
  Serial.begin(9600);
}

void loop() {
  buttonValue = digitalRead(buttonPin); // Read the button state
  Serial.print("Your button is: ");
  Serial.println(buttonValue);

  // Check for a button press (transition from HIGH to LOW)
  if (buttonValue == LOW && lastButtonState == HIGH) {
    // Toggle the LED state
    ledState = !ledState;
    digitalWrite(ledPin, ledState); // Update the LED
  }

  lastButtonState = buttonValue; // Update the last button state
  delay(dt); // Small delay for debouncing
}

```

What does this code do? 🤔

- It sets pin 2 for the button and pin 13 for the LED.
- The `setup()` function sets the button pin as an input with a pull-up resistor, the LED pin as an output, and starts Serial communication.
- The `loop()` function reads the button state, prints it, and toggles the LED state when the button is pressed.
- `delay(100)` helps with debouncing to avoid false readings. ⏳

---

## 🔧 Set It Up

1. Connect the LED to pin 13 on the Arduino. Use a 220-ohm resistor and connect the other side to GND.
2. Connect the button to pin 2. One side of the button goes to pin 2 , and the other side goes to GND.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) to see the button state.
5. Press the button to toggle the LED on or off! ✨

---

## 🎥 See It in Action

I made a video to show the button-controlled LED (v2) working. Press the button, and the LED toggles on or off, staying in that state until the next press! Check it out below:

https://youtube.com/shorts/aih4M_JEQJY?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about buttons and toggling states. 📚
- You can see how Arduino handles button presses to control an LED. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more LEDs to toggle with the same button. Or, try adding a second button to control the LED in a different way.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
