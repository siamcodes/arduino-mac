 
const int analogInPin = A0;
int sensorValue = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);

  //sensorValue = map(sensorValue, 0, 800, 0, 1050);

  Serial.println(sensorValue);
  delay(1800);
}
