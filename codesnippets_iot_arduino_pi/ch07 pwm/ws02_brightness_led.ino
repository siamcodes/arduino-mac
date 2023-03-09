
const int ledPin = 13; 
const int delayTime = 50;
int duty;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (duty = 0; duty < 1023; duty += 10) {
    analogWrite(ledPin, duty);
    Serial.println(duty);
    delay(delayTime);
  }
  
}
