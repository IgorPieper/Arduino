int bartek = 9;

void setup() {
  pinMode(bartek, OUTPUT);
}

void loop() {

  tone(bartek, 440);
  delay(1000);
  noTone(bartek);
  delay(10000);

}
