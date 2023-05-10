#define trigPin 12
#define echoPin 11
#define dioda 9
#define diodaz 8
#define bartek 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(dioda, OUTPUT);
  pinMode(diodaz, OUTPUT);
  pinMode(bartek, OUTPUT);
  

}

void loop() {  
  Serial.print(zmierzOdleglosc());
  Serial.println(" cm");
  delay(500);
} 

int zmierzOdleglosc() {
  long czas, dystans;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
  
  if(dystans<10){
    digitalWrite(dioda, HIGH);
    digitalWrite(diodaz, LOW);
  }
    else{
    digitalWrite(dioda, LOW);
    digitalWrite(diodaz, HIGH);
  }



  if(dystans<10){
   tone(bartek, 1000, 10);
  
   
  }
    else{
    digitalWrite(bartek, LOW);
    
  }

  return dystans;
}
