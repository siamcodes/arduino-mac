
const int ledPin = D4;
int timeOn = 1000;
int timeOff = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, HIGH);  
  Serial.println(1);
  delay(timeOn);    

  digitalWrite(ledPin, LOW); 
  Serial.println(0); 
  delay(timeOff);                  
}
