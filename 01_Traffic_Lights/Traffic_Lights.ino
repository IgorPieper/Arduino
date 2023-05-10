
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  tone(13, 1000, 1000);
  digitalWrite(13, HIGH);   
  delay(100); 
  digitalWrite(13, LOW);  
  delay(5000);
  digitalWrite(12, HIGH);   
  delay(1000);                       
  digitalWrite(12, LOW);  
  delay(1000);  
  digitalWrite(11, HIGH);   
  delay(1000);                       
  digitalWrite(11, LOW);  
  delay(1000);   
  digitalWrite(12, HIGH);   
  delay(1000);                       
  digitalWrite(12, LOW);  
  delay(1000);                    
}
