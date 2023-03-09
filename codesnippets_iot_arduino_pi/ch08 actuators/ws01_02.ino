
void setup() {
  pinMode(D7, OUTPUT); //
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D7, LOW);
  delay(1000);                      // Wait 

  digitalWrite(D7, HIGH);
  delay(2000);                      // Wait  
}
