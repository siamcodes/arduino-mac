int MR1=19;
int MR2=18;

void setup() {
 
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);

}

void loop() {
  digitalWrite(MR1,HIGH);
  digitalWrite(MR1,LOW);
  delay(1000);
}
