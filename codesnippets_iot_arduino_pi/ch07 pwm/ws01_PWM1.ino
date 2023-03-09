const int ledPin = 13; 
const int delayTime = 3000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("0");
  analogWrite(ledPin, 0);
  delay(delayTime);

  Serial.println("255");
  analogWrite(ledPin, 255);
  delay(delayTime); 

  Serial.println("512");
  analogWrite(ledPin, 512);
  delay(delayTime);  

  Serial.println("767");
  analogWrite(ledPin, 767);    
  delay(delayTime);    

  Serial.println("1023");
  analogWrite(ledPin, 1023);    delay(delayTime);  
}
