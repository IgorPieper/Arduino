volatile bool vibrationDetected = false;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), vibrationInterrupt, FALLING);
}

void loop() {
  if (vibrationDetected) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
    vibrationDetected = false;
  }
}

void vibrationInterrupt() {
  vibrationDetected = true;
}
