int buttonPin = 4;
int bartek = 8;

void setup() {
  pinMode(bartek, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    digitalWrite(bartek, HIGH);
  } else {
    digitalWrite(bartek, LOW);
  }
}
