int LED_PIN = 3;
 
void setup()
{
  pinMode(LED_PIN, OUTPUT);
}
 
void loop()
{
  analogWrite(LED_PIN, (analogRead(A0)>>2));
}