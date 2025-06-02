# 📱 NFC UID Reader with Arduino 📱

Hello everyone! 👋 Today, we’ll make an NFC UID reader project using Arduino. This project uses an MFRC522 RFID module to read the unique identifier (UID) of NFC cards and display it in the Serial Monitor. Let’s get started! 🚀

---

## 🛠️ What You’ll Need

Here’s what you need for this project:

- **Arduino Board** (I used an Arduino Uno 🖥️)
- **MFRC522 RFID Module** (To read NFC cards 📡)
- **NFC Card or Tag** (To test the reader 🏷️)
- **Breadboard** (To connect everything 🧩)
- **Jumper Wires** (To make connections)
- **Computer** (To see UID values in the Serial Monitor 💻)

---

## 💡 How It Works

This project uses an MFRC522 RFID module to detect and read the unique identifier (UID) of NFC cards. When you place an NFC card near the reader, the Arduino reads the card’s UID and prints it to the Serial Monitor in hexadecimal format, along with the UID length in bytes. It’s a great way to learn about RFID technology! 📘

### 🔧 How the MFRC522 RFID Module Works

The main component in this project is the MFRC522 RFID module. This module communicates with NFC cards using radio frequency (RF) signals at 13.56 MHz. It has two key pins for communication with the Arduino via SPI:

- **SS/SDA Pin (10)**: This is the slave select pin for SPI communication.
- **RST Pin (9)**: This resets the module.

The module sends out an RF signal to detect nearby NFC cards. When a card is detected, it reads the card’s UID (a unique number stored on the card) and sends it to the Arduino. The code uses the `MFRC522` library to handle communication, check for new cards, and read the UID, which is then printed to the Serial Monitor. 🔄

---

## 💻 The Code

Here’s the code for the NFC UID reader. Copy it into your Arduino IDE and upload it to your board. 🖱️

```cpp
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9    // Reset pin
#define SS_PIN 10    // SDA (Slave Select) pin

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  while (!Serial);     // Wait for serial port to connect
  SPI.begin();         // Initialize SPI bus
  mfrc522.PCD_Init();  // Initialize MFRC522

  // Set maximum antenna gain
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);

  // Check if MFRC522 is responding
  Serial.println("Checking RFID Module...");
  byte version = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  if (version == 0x00 || version == 0xFF) {
    Serial.println("ERROR: MFRC522 not detected. Check wiring or power.");
    while (true);  // Halt execution
  } else {
    Serial.print("MFRC522 Version: 0x");
    Serial.println(version, HEX);
    Serial.println("RFID Reader Initialized");
    Serial.println("Antenna Gain Set to Maximum");
    Serial.println("Place your NFC card near the reader...");
  }
}

void loop() {
  // Check if module is still responsive
  byte version = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  if (version == 0x00 || version == 0xFF) {
    Serial.println("ERROR: MFRC522 lost connection. Check wiring.");
    delay(1000);
    return;
  }

  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    Serial.println("No card detected. Waiting...");
    delay(500);
    return;
  }

  // Try to select the card
  if (!mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Card detected but failed to read serial. Try adjusting card position.");
    delay(500);
    return;
  }

  // Print UID
  Serial.printqh("Card Detected! UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  Serial.print("UID Length: ");
  Serial.print(mfrc522.uid.size);
  Serial.println(" bytes");

  // Halt PICC and stop encryption
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(1000);  // Wait before next read
}

```

What does this code do? 🤔

- It includes the `SPI` and `MFRC522` libraries to communicate with the RFID module.
- It sets pin 10 as the SDA (slave select) pin and pin 9 as the reset pin for the MFRC522.
- The `setup()` function initializes Serial communication, SPI, and the MFRC522 module, and checks if the module is responding.
- The `loop()` function checks for new NFC cards, reads their UID, and prints it to the Serial Monitor in hexadecimal format.
- `delay(1000)` waits 1 second between readings. ⏳

---

## 🔧 Set It Up

1. Connect the MFRC522 RFID module to the Arduino: SDA to pin 10, RST to pin 9, SCK to pin 13, MOSI to pin 11, MISO to pin 12, VCC to 3.3V (or 5V depending on your module), and GND to GND.
2. Plug your Arduino into your computer with a USB cable. ⚡
3. Upload the code, then open the Serial Monitor (Tools > Serial Monitor) in the Arduino IDE to see the UID values.
4. Place an NFC card or tag near the reader to see its UID! ✨

---

## 🎥 See It in Action

I made a video to show the NFC UID reader working. Place an NFC card near the reader, and the UID will show up in the Serial Monitor! Check it out below:

https://youtube.com/shorts/G5VgeqCzc-k?feature=share

---

## 🌟 Why This Project Is Great

- It’s a simple way to learn about RFID and NFC technology. 📚
- You can see how Arduino reads NFC card UIDs. 💡
- It’s a good project for beginners to try. 🌱

---

## 🚀 What’s Next?

You can add an LED or buzzer to signal when a card is detected. Or, try comparing the UID to a known value to create a simple access control system.

Happy building! 🛠️

---
Blog Post = https://pakshal.vercel.app
Github= https://github.com/PakshalGada/arduino-projects
Youtube= https://www.youtube.com/@pakshalgada
