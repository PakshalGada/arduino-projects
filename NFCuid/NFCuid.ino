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
  Serial.print("Card Detected! UID: ");
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