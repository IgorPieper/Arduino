const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equalsIgnoreCase("on")) {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    } else if (command.equalsIgnoreCase("off")) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }
  }
}
