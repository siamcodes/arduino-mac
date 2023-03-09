void MotorStop(int Time){
  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);
}

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
  analogWrite(ML1, 0);
  analogWrite(ML2, MotorSpeed);
  analogWrite(MR1, MotorSpeed);
  analogWrite(MR2, 0);
  delay(Time); //400
}

void TurnRight(int MotorSpeed ,int Time) {
  analogWrite(ML1, MotorSpeed);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, MotorSpeed);
  delay(Time);  //400
}

void UTurn(int MotorSpeed, int Time) {
  analogWrite(ML1, MotorSpeed);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, MotorSpeed);
  delay(Time);  //800
}
