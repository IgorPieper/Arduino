int liczba = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  delay(500);
  Serial.println(liczba);
  liczba++;

  if (liczba % 10 == 0){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}
