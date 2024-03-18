#define bartek 9

void setup()
{
  Serial.begin(9600);
  pinMode(bartek, OUTPUT);
}

void loop()
{
  for (int bartosz = 0; bartosz < 255; bartosz+=5){
    analogWrite(bartek, bartosz);
    delay(100);
  }
  for (int bartosz = 255; bartosz > 0; bartosz-=5){
    analogWrite(bartek, bartosz);
    delay(100);
  }
}
