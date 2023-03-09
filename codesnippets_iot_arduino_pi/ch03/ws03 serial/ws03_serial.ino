
const int ledPin = D4;
int timeOn = 500;
int timeOff = 600;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.print("LED On/Off ");
  Serial.println(timeOn + timeOff);
}

void loop() {
  digitalWrite(ledPin, HIGH);  
  Serial.println("LED On");    
  delay(timeOn);    

  digitalWrite(ledPin, LOW); 
  Serial.println("LED Off"); 
  delay(timeOff);                
}
