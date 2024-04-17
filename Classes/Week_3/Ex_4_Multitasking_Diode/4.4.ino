#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5
#define LED5_PIN 6

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;

const long interval1_on = 1000;
const long interval1_off = 1000;
const long interval2_on = 500;
const long interval2_off = 500;
const long interval3_on = 2000;
const long interval3_off = 500;
const long interval4_on = 1500;
const long interval4_off = 1000;
const long interval5_on = 2000;
const long interval5_off = 1000;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // LED 1
  if ((digitalRead(LED1_PIN) == HIGH && currentMillis - previousMillis1 >= interval1_on) ||
      (digitalRead(LED1_PIN) == LOW && currentMillis - previousMillis1 >= interval1_off)) {
    previousMillis1 = currentMillis;
    digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
  }

  // LED 2
  if ((digitalRead(LED2_PIN) == HIGH && currentMillis - previousMillis2 >= interval2_on) ||
      (digitalRead(LED2_PIN) == LOW && currentMillis - previousMillis2 >= interval2_off)) {
    previousMillis2 = currentMillis;
    digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
  }

  // LED 3
  if ((digitalRead(LED3_PIN) == HIGH && currentMillis - previousMillis3 >= interval3_on) ||
      (digitalRead(LED3_PIN) == LOW && currentMillis - previousMillis3 >= interval3_off)) {
    previousMillis3 = currentMillis;
    digitalWrite(LED3_PIN, !digitalRead(LED3_PIN));
  }

  // LED 4
  if ((digitalRead(LED4_PIN) == HIGH && currentMillis - previousMillis4 >= interval4_on) ||
      (digitalRead(LED4_PIN) == LOW && currentMillis - previousMillis4 >= interval4_off)) {
    previousMillis4 = currentMillis;
    digitalWrite(LED4_PIN, !digitalRead(LED4_PIN));
  }

  // LED 5
  if ((digitalRead(LED5_PIN) == HIGH && currentMillis - previousMillis5 >= interval5_on) ||
      (digitalRead(LED5_PIN) == LOW && currentMillis - previousMillis5 >= interval5_off)) {
    previousMillis5 = currentMillis;
    digitalWrite(LED5_PIN, !digitalRead(LED5_PIN));
  }
}
