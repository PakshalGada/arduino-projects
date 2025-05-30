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
  
 
  Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, or off):");
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
    }else if (userInput == "white") {
      setColor(255, 255, 255);
      Serial.println("LED set to WHITE");
    } else if (userInput == "off") {
      setColor(0, 0, 0); 
      Serial.println("LED turned OFF");
    } else {
      Serial.println("Invalid input! Please enter red, green, blue, cyan, magenta, yellow, or off:");
    }
    
    Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, or off):");
  }
}

void setColor(int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
