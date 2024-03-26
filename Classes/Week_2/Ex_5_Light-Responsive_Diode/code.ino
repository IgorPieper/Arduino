const int lightSensorPin = A5;
const int ledPin = 9;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(lightSensorPin);
  int ledValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(ledPin, ledValue);

  Serial.print("Napięcie: ");
  Serial.print(ledValue);
  Serial.print("V, Wartość czujnika: ");
  Serial.println(sensorValue);

  delay(1000);
}
