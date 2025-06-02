# 📏 Ultrasound Distance Measurement with Arduino 📏

Hello everyone! 👋 Today, we’ll make an ultrasound distance measurement project using Arduino. This project uses an ultrasonic sensor to measure the distance to an object and displays it in the Serial Monitor. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **HC-SR04 Ultrasonic Sensor** (To measure distance 📡)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections )
- **Computer** (To see distance values in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses an ultrasonic sensor to measure the distance to an object. The sensor sends out sound waves, which bounce off the object and return to the sensor. The Arduino calculates the distance based on the time it takes for the sound waves to return and shows the result in centimeters in the Serial Monitor. It’s a great way to learn about ultrasonic sensors! 📘

### 🔧 How the Ultrasonic Sensor Works

The main component in this project is the HC-SR04 ultrasonic sensor. It has two main pins for operation:

- **Trig Pin (9)**: This pin sends out a short pulse of ultrasonic sound waves when set to `HIGH` for 10 microseconds.
- **Echo Pin (10)**: This pin listens for the returning sound waves and goes `HIGH` for a duration proportional to the time it took for the waves to return. The Arduino measures this duration using `pulseIn()` and calculates the distance with the formula: `distance = duration * 0.0343 / 2`. The speed of sound is about 343 m/s (or 0.0343 cm/µs), and we divide by 2 because the sound travels to the object and back. 📐

## 💻 The Code

Here’s the code for the ultrasound distance measurement. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
// Define pins
const int trigPin = 9;
const int echoPin = 10;

// Variable for duration and distance
long duration;
float distance;

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us HIGH pulse on trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echoPin and calculate duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = duration * 0.0343 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(700);
}

```

What does this code do? 🤔

- It sets pin 9 as the trigger pin and pin 10 as the echo pin for the ultrasonic sensor.
- The `setup()` function starts Serial communication and sets the pin modes.
- The `loop()` function sends a pulse to trigger the sensor, measures the echo duration, calculates the distance, and prints it to the Serial Monitor.
- `delay(700)` waits 700 milliseconds between measurements. ⏳

---

## 🔧 Set It Up

1. Connect the HC-SR04 ultrasonic sensor to the Arduino: Trig pin to 9, Echo pin to 10, VCC to 5V, and GND to GND.
2. Plug your Arduino into your computer with a USB cable. ⚡
3. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE to see the distance values.
4. Place an object in front of the sensor and see the distance change as you move it closer or farther! ✨

## 🎥 See It in Action

I made a video to show the ultrasound distance measurement working. Move an object in front of the sensor, and the distance will show up in the Serial Monitor! Check it out below:

https://youtube.com/shorts/ArlTNBRS30U?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about ultrasonic sensors and distance measurement. 📚
- You can see how Arduino calculates distances using sound waves. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add an LED or buzzer to alert when the object is too close. Or, try displaying the distance on an LCD screen instead of the Serial Monitor.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
