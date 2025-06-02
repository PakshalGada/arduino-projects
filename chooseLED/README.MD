# LED Color Chooser with Arduino

Hello everyone! 👋 Today, we’ll make an LED color chooser using Arduino. You can pick a color—green, blue, or red—and the Arduino will light up the matching LED. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **3 LEDs** (Green, Blue, and Red 🌟)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Resistors** (220 ohms for each LED ⚡)
- **Computer** (To type commands into the Serial Monitor 💻)

---

## 💡 How It Works

This project lets you choose which LED to light up by typing a color into the Serial Monitor. The Arduino reads your input and turns on the right LED. You can also type "All" to turn on all LEDs or "clear" to turn them all off. It’s a great way to learn about Serial communication! 📘

## 💻 The Code

Here’s the code for the LED color chooser. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
const int green_led = 11;
const int blue_led = 10;
const int red_led = 12;

String main_string = "Please! choose the color to light up ";
String color_string = "The colors are 'green', 'blue', 'red' ";
String clear_command = "Type 'All' to turn on all the led or Type 'clear' to turn off all the led";
String get_color;

void setup() {
  Serial.begin(9600);

  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  Serial.println(main_string);
  Serial.println(color_string);
  Serial.println(clear_command);
}

void loop() {
  while (Serial.available() == 0) {
    // wait for user input
  }
  get_color = Serial.readString();
  get_color.trim(); // remove any leading/trailing whitespace
  get_color.toLowerCase();
  Serial.println(get_color);

  // turn off all LEDs initially
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, LOW);

  if (get_color == "green") {
    digitalWrite(green_led, HIGH);
  } else if (get_color == "blue") {
    digitalWrite(blue_led, HIGH);
  } else if (get_color == "red") {
    digitalWrite(red_led, HIGH);
  } else if (get_color == "all") {
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, HIGH);
    digitalWrite(red_led, HIGH);
  } else if (get_color == "clear") {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
  } else {
    Serial.println("Invalid color! Please choose 'green', 'blue', or 'red'.");
  }
}

```

What does this code do? 🤔

- It sets pins 11, 10, and 12 for the green, blue, and red LEDs.
- The `setup()` function starts Serial communication and prints instructions.
- The `loop()` function waits for your input, reads it, and turns on the correct LED based on what you type.
- It also handles "all" and "clear" commands to control all LEDs at once. 💡

---

## 🔧 Set It Up

1. Connect the green LED to pin 11, the blue LED to pin 10, and the red LED to pin 12 on the Arduino. Use a 220-ohm resistor for each LED.
2. Connect the other side of each LED to GND on the breadboard.
3. Plug your Arduino into your computer with a USB cable. ⚡
4. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE.
5. Type a color ("green", "blue", "red", "all", or "clear") and press Enter to control the LEDs! ✨

- --

## 🎥 See It in Action

I made a video to show the LED color chooser working. Type a color in the Serial Monitor, and the right LED lights up! Check it out below:

https://youtube.com/shorts/-PXTkRql9Aw?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about Serial communication with Arduino. 📚
- You can control LEDs by typing commands. 💻
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add more LEDs with different colors. Or, try adding a button to cycle through the colors instead of typing.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
