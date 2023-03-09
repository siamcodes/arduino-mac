
const int ledPin = 13; 
const int buttonPin = 4; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH); 
  } 
   else 
  {
    digitalWrite(ledPin, LOW);  
  }
                       
  delay(100);                  
}
