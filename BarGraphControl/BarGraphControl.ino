const int BARGRAPHSIZE = 10;
const int POTINPUT = A0;

int barPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  for(int barSegment = 0; barSegment < BARGRAPHSIZE; barSegment++) {
    pinMode(barPins[barSegment],OUTPUT);
    digitalWrite(barPins[barSegment],LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(POTINPUT);
  int barLevel = map(potValue, 0, 1023, 0, BARGRAPHSIZE);

  for(int barSegment = 0; barSegment < BARGRAPHSIZE; barSegment++) {
    if (barSegment < barLevel) {
      digitalWrite(barPins[barSegment],HIGH);
    }
    else {
      digitalWrite(barPins[barSegment],LOW);      
    }
  }
} 