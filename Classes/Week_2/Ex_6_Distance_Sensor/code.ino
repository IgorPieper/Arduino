const int trigPin = 2;
const int echoPin = 3;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_BUILTIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    float distance = measureDistance();
    Serial.print("Odleglosc: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if(distance < 30) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(100);
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
