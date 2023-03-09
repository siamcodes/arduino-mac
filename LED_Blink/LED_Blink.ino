const int D1 = 2;
const int D2 = 3;
const int D3 = 4;
const int D4 = 5;
int D[] = {2, 3, 4, 5};


void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D, OUTPUT);

}

void loop() {
  onAll();
  delay(2000);
  offAll();
  delay(500);
  forWard();
  backWard();
  backWard();
  backWard();
  backWard();  
}

void onAll() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void offAll() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}

void forWard() {
  for (int i = 0; i <= 3; i++) {
    digitalWrite(D[i], HIGH);
    delay(200);
    digitalWrite(D[i], LOW);
    delay(200);
  }
}

void backWard() {
  for (int i = 3; i >= 0; i--) {
    digitalWrite(D[i], HIGH);
    delay(50);
    digitalWrite(D[i], LOW);
    delay(50);
  }
}
