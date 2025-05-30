int xpin=A0;
int ypin=A1;
int spin=2;
int xval;
int yval;
int sval;
int dt=200;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(xpin,INPUT);
pinMode(ypin,INPUT);
pinMode(spin,INPUT);
digitalWrite(spin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
xval=analogRead(xpin);
yval=analogRead(ypin);
sval=digitalRead(spin);
delay(dt);

Serial.print("X Value= ");
Serial.print(xval);
Serial.print(" Y Value= ");
Serial.print(yval);
Serial.print(" Switch State = ");
Serial.println(sval);

}
