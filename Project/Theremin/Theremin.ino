// Definicje pinów dla czujników 1-3 (czujnik 4 jest zakomentowany)
const int trigPin1 = 2;
const int echoPin1 = 3;

const int trigPin2 = 4;
const int echoPin2 = 5;

const int trigPin3 = 6;
const int echoPin3 = 7;

// const int trigPin4 = 8; // Zakomentowany czwarty czujnik
// const int echoPin4 = 9; // Zakomentowany czwarty czujnik

void setup() {
  // Ustawienia pinów dla każdego czujnika
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // pinMode(trigPin4, OUTPUT); // Zakomentowany czwarty czujnik
  // pinMode(echoPin4, INPUT);  // Zakomentowany czwarty czujnik

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Inicjalizacja komunikacji przez Serial
}

void loop() {
  // Odczyt odległości z czujników 1-3 (bez czujnika 4)
  float distance1 = measureDistance(trigPin1, echoPin1);
  float distance2 = measureDistance(trigPin2, echoPin2);
  float distance3 = measureDistance(trigPin3, echoPin3);
  // float distance4 = measureDistance(trigPin4, echoPin4); // Zakomentowany czwarty czujnik

  // Wysłanie odległości do komputera dla każdego czujnika
  Serial.print("Czujnik 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Czujnik 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Czujnik 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  // Serial.print("Czujnik 4: "); Serial.print(distance4); Serial.println(" cm"); // Zakomentowany czwarty czujnik

  // Sterowanie diodą LED na podstawie odległości dla czujnika 1
  if (distance1 < 30) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100); // Opóźnienie, aby uniknąć nadmiernego odświeżania
}

// Funkcja do pomiaru odległości, przyjmuje piny trig i echo jako argumenty
float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 58.0;

  return distance;
}
