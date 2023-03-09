
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  if (Serial.available() > 0) {
    int inRead = Serial.read();

    if (inRead == '1') {
        digitalWrite(ledPin, HIGH);
      } else if (inRead == '0') {
        digitalWrite(ledPin, LOW);
        }
  /*
    switch (inRead) {
      case '1':
        digitalWrite(ledPin, HIGH);
        break;

      case '0':
        digitalWrite(ledPin, LOW);
      default:
        digitalWrite(ledPin, LOW);
     } */
    
    delay(100);                  
  }
}
