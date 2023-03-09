void Forward(int MotorSpeed, int Time) {
  analogWrite(ML1, MotorSpeed);
  analogWrite(ML2, 0);
  analogWrite(MR1, MotorSpeed);
  analogWrite(MR2, 0);
  delay(Time);
}

void Backward(int MotorSpeed, int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, MotorSpeed);
  analogWrite(MR1, 0);
  analogWrite(MR2, MotorSpeed);
  delay(Time);
}

void TurnLeft(int MotorSpeed, int Time) {
  analogWrite(ML1, MotorSpeed);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, MotorSpeed);
  delay(Time);
}

void TurnRight(int MotorSpeed, int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, MotorSpeed);
  analogWrite(MR1, MotorSpeed);
  analogWrite(MR2, 0);
  delay(Time);
}

void UTurn(int MotorSpeed, int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, MotorSpeed);
  analogWrite(MR1, MotorSpeed);
  analogWrite(MR2, 0);
  delay(Time);
}

void MotorStop() {
  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);
}
