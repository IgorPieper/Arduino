void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sos_signal();
  Serial.println("SOS");
  delay(3000);
}

void sos_signal() {
  dot(); dot(); dot();
  dash(); dash(); dash();
  dot(); dot(); dot();
  delay(1000);
}

void dot() {
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
}

void dash() {
  digitalWrite(13, HIGH);
  delay(750);
  digitalWrite(13, LOW);
  delay(250);
}
