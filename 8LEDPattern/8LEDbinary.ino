int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=1000;
byte LEDs1=0b0000000;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs1);
digitalWrite(latchPin,HIGH);
delay(dt);
Serial.println(LEDs1,BIN);
LEDs1=LEDs1+1;
}