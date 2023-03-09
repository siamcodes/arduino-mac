int led[] = {9, 10, 11, 12};

void setup() {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);

}

void loop() {
  for (int i = 0; i <= 3; i++) {
    digitalWrite(led[i], HIGH);
    delay(100);
    digitalWrite(led[i], LOW);
    delay(100);
  }

 for (int i = 3; i >= 0; i--) {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);
    delay(200);
  }
}
