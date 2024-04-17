#include <Servo.h>

Servo servo;
int potpin = A0;
int val;

void setup() {
  servo.attach(3);
  servo.write(0);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  servo.write(val);
  delay(15);
}
