void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop() {
  int a = 10;
  while (a > 0) {
    Serial.println(a);
    a--;
  }

}
