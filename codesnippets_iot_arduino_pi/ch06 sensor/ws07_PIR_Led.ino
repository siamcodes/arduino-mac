
const int ledPin = 5;  // D1
const int builtinLed = D4;
const int pirPin = 13; //D7
int pirState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(builtinLed, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  pirState = digitalRead(pirPin);
  Serial.print("PIR state :"); Serial.println(pirState);
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(builtinLed, LOW);
    Serial.println("Motion detected!");
  } 
   else 
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(builtinLed, HIGH);  
  }
                       
  delay(200);                  
}
