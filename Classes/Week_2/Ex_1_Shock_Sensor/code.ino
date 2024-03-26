const int sensorPin = 8;

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  if (sensorState == LOW) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(10);
}
