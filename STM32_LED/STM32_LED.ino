int LED1 = PC13;

void setup() {
  pinMode(LED1, OUTPUT);

}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);

}
