int liczba = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop()
{
  delay(500);
  Serial.println(liczba);
  liczba++;

  if (liczba % 10 == 0){
    digitalWrite(8, HIGH);
    delay(1500);
    digitalWrite(8, LOW);
    delay(500);
  }
}
