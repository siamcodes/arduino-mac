
const int ledPin = D4; 
const int sensorPin = D1; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  Serial.println(sensorState);

  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH); 
  } 
   else 
  {
    digitalWrite(ledPin, LOW);  
  }
                       
  delay(500);                  
}
