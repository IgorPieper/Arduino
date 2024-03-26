const int bartek = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(bartek);
  float voltage = reading * 5.0 / 1023.0;
  float temperature = voltage * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}
