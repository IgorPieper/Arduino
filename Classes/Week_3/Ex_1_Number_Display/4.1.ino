#define DATA_PIN  8
#define LATCH_PIN 7
#define CLOCK_PIN 6

byte digits[] = {
 0b11000000, //0
 0b11111001, //1
 0b10100100, //2
 0b10110000, //3
 0b10011001, //4
 0b10010010, //5
 0b10000010, //6
 0b11111000, //7
 0b10000000, //8
 0b10010000  //9
};

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int number = input.toInt();
    int displayNumber = number % 10;

    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, digits[displayNumber]);
    digitalWrite(LATCH_PIN, HIGH);
  }
}
