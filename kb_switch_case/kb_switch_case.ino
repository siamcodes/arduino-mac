int iot = 12;
int ntp = 15;
int sw1 = 16;
int sw2 = 14;

void setup() {
  pinMode(iot, OUTPUT);
  pinMode(ntp, OUTPUT);  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT); 

}

void loop() {
   int s1 = digitalRead(sw1);
   int s2 = digitalRead(sw2);
  
  switch(s1){
    case HIGH: digitalWrite(iot, HIGH);
             break;
    case HIGH: digitalWrite(ntp, HIGH);
             break;
    default:
             digitalWrite(iot, LOW);
             digitalWrite(ntp, LOW);
  }

}
