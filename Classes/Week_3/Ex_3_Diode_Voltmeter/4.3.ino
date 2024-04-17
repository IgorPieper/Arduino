#define WHITE_LED_PIN  2
#define YELLOW_LED_PIN 3
#define GREEN_LED_PIN  4
#define BLUE_LED_PIN   5
#define RED_LED_PIN    6
#define ANALOG_IN_PIN  A2

void setup() {
  pinMode(WHITE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(ANALOG_IN_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(ANALOG_IN_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);

  digitalWrite(WHITE_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  if (voltage > 0) digitalWrite(WHITE_LED_PIN, HIGH);
  if (voltage >= 1) digitalWrite(YELLOW_LED_PIN, HIGH);
  if (voltage >= 2) digitalWrite(GREEN_LED_PIN, HIGH);
  if (voltage >= 3) digitalWrite(BLUE_LED_PIN, HIGH);
  if (voltage >= 4) digitalWrite(RED_LED_PIN, HIGH);

  delay(100);
}
