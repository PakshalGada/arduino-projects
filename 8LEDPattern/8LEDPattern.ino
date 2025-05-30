int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=100;
byte LEDs1=0b10000000;
byte LEDs2=0b01000000;
byte LEDs3=0b00100000;
byte LEDs4=0b00010000;
byte LEDs5=0b00001000;
byte LEDs6=0b00000100;
byte LEDs7=0b00000010;
byte LEDs8=0b00000001;


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

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs2);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs3);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs4);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs5);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs6);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs7);
digitalWrite(latchPin,HIGH);
delay(dt);

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs8);
digitalWrite(latchPin,HIGH);
delay(dt);
}
