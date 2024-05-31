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
    char command = Serial.read();
    switch(command) {
      case 'r':
        setColor(255, 0, 0); // Czerwony
        Serial.println("Color changed to RED");
        break;
      case 'g':
        setColor(0, 255, 0); // Zielony
        Serial.println("Color changed to GREEN");
        break;
      case 'b':
        setColor(0, 0, 255); // Niebieski
        Serial.println("Color changed to BLUE");
        break;
      case 'c':
        setColor(0, 0, 0); // Wyłącz diodę
        Serial.println("LED is OFF");
        break;
      default:
        Serial.println("Unknown command");
        break;
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
