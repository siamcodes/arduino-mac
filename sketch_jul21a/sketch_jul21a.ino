void setup() {
  Serial.begin(9600);
}

void loop() {
  int a = 10;
  do{
    Serial.println(a);
    a--;
  }while (a <= 0);
}
