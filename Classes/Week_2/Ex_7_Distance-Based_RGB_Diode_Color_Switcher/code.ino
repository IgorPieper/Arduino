const int trigPin = 2;
const int echoPin = 3;

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    float distance = measureDistance();
    Serial.print("Odleglosc: ");
    Serial.print(distance);
    Serial.println(" cm");
    displayColor(distance);
    delay(1000);
  }
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 58.0;

  return distance;
}

void displayColor(float distance) {

  int value = map(distance, 0, 200, 0, 255);

  if (distance < 25) { // Fioletowy
    analogWrite(redPin, value); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, value); 
  } else if (distance < 50) { // Niebieski
    analogWrite(redPin, 0); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, value); 
  } else if (distance < 75) { // Jasnieniebieski
    analogWrite(redPin, 0); 
    analogWrite(greenPin, value); 
    analogWrite(bluePin, value); 
  } else if (distance < 100) { // Zielony
    analogWrite(redPin, 0); 
    analogWrite(greenPin, value); 
    analogWrite(bluePin, 0); 
  } else if (distance < 125) { // Jasnozielony
    analogWrite(redPin, value/2); 
    analogWrite(greenPin, value); 
    analogWrite(bluePin, 0); 
  } else if (distance < 150) { // Żółty
    analogWrite(redPin, value); 
    analogWrite(greenPin, value); 
    analogWrite(bluePin, 0); 
  } else if (distance < 175) { // Pomarańczowy
    analogWrite(redPin, value); 
    analogWrite(greenPin, value/2); 
    analogWrite(bluePin, 0); 
  } else { // Czerwony
    analogWrite(redPin, value); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 0); 
  }
}
