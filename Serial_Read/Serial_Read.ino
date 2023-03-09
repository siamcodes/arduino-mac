#define LED1  23
#define LED2  22

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); 

}

void loop() {
  char ch1 ;
  ch1 = Serial.read();
  if(ch1 == 'a'){
    digitalWrite(LED1, HIGH);
  }else{
    digitalWrite(LED1, LOW);
  }
  delay(100);
}
