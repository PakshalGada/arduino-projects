# 4 Pin LED Color Chooser with Arduino

Hello everyone! 👋 Today, we’ll make an RGB LED color chooser using Arduino. You can pick a color like red, green, blue, or even cyan, and the RGB LED will change to that color. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **RGB LED** (Common cathode or common anode type 🌟)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each RGB pin ⚡)
- **Computer** (To type commands into the Serial Monitor 💻)

---

## 💡 How It Works

This project uses an RGB LED to create different colors. You type a color into the Serial Monitor, and the Arduino sets the RGB LED to that color by mixing red, green, and blue light. It’s a great way to learn about RGB LEDs and Serial communication! 📘

### 🔧 How the RGB LED Works

The main component in this project is the RGB LED. It’s a special LED with three colors—red, green, and blue—in one package. It has four pins: one for each color (red, green, blue) and one common pin (either cathode or anode). By controlling how much power goes to each color using `analogWrite()`, you can mix the colors to make new ones. For example:

- Red (255, 0, 0) makes pure red.
- Red + Green (255, 255, 0) makes yellow.
- All on (255, 255, 255) makes white.The values from 0 to 255 control the brightness of each color, allowing you to create many colors like cyan or magenta! 🌟

---

## 💻 The Code

Here’s the code for the RGB LED color chooser. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

String userInput;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(0, 0, 0);

  Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, white, or off):");
}

void loop() {
  if (Serial.available() > 0) {
    userInput = Serial.readStringUntil('\n');
    userInput.trim();
    userInput.toLowerCase();

    if (userInput == "red") {
      setColor(255, 0, 0);
      Serial.println("LED set to RED");
    } else if (userInput == "green") {
      setColor(0, 255, 0);
      Serial.println("LED set to GREEN");
    } else if (userInput == "blue") {
      setColor(0, 0, 255);
      Serial.println("LED set to BLUE");
    } else if (userInput == "cyan") {
      setColor(0, 255, 255);
      Serial.println("LED set to CYAN");
    } else if (userInput == "magenta") {
      setColor(255, 0, 255);
      Serial.println("LED set to MAGENTA");
    } else if (userInput == "yellow") {
      setColor(255, 255, 0);
      Serial.println("LED set to YELLOW");
    } else if (userInput == "white") {
      setColor(255, 255, 255);
      Serial.println("LED set to WHITE");
    } else if (userInput == "off") {
      setColor(0, 0, 0);
      Serial.println("LED turned OFF");
    } else {
      Serial.println("Invalid input! Please enter red, green, blue, cyan, magenta, yellow, white, or off:");
    }

    Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, white, or off):");
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

```

What does this code do? 🤔

- It sets pins 9, 10, and 11 for the red, green, and blue parts of the RGB LED.
- The `setup()` function starts Serial communication and turns the LED off at the start.
- The `loop()` function waits for your input, reads it, and sets the LED to the color you choose.
- The `setColor()` function uses `analogWrite()` to mix the red, green, and blue values to make the desired color. 💡

---

## 🔧 Set It Up

1. Connect the RGB LED to the Arduino: red to pin 9, green to pin 10, and blue to pin 11. Use a 220-ohm resistor for each pin.
2. If you’re using a common cathode RGB LED, connect the common pin to GND. If it’s common anode, connect it to 5V and adjust the code logic.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE.
5. Type a color ("red", "green", "blue", "cyan", "magenta", "yellow", "white", or "off") and press Enter to change the LED color! ✨


---

## 🎥 See It in Action

I made a video to show the RGB LED color chooser working. Type a color in the Serial Monitor, and the RGB LED changes to that color! Check it out below:

https://youtube.com/shorts/PaVuLNsi6rM?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about RGB LEDs and color mixing. 📚
- You can control the LED color by typing commands. 💻
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more colors by mixing different RGB values. Or, try adding a button to cycle through the colors instead of typing.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
