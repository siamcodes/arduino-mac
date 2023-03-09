#define LED1  23
#define LED2  22

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); 
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(100);
   digitalWrite(LED1, LOW);
  delay(100);
   digitalWrite(LED2, HIGH);
  delay(100);
   digitalWrite(LED2, LOW);
  delay(100);

}
