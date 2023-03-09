 
const int analogInPin = A0;
int sensorValue = 0; 

const int ledPin = 13;  
int adcValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  adcValue = sensorValue;
  
  Serial.println(adcValue);
  analogWrite(ledPin, adcValue);
  
  delay(10);  
}



