const int lightSensorPin = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(lightSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("Napięcie: ");
  Serial.print(voltage);
  Serial.print("V, Wartość czujnika: ");
  Serial.println(sensorValue);

  delay(1000);
}
