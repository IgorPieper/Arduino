const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    int red = 0, green = 0, blue = 0;
    sscanf(command.c_str(), "%d %d %d", &red, &green, &blue);
    setColor(red, green, blue);

    Serial.print("Color changed to: ");
    Serial.print("R=");
    Serial.print(red);
    Serial.print(", G=");
    Serial.print(green);
    Serial.print(", B=");
    Serial.println(blue);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
