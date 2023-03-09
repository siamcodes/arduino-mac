void Can1() {
  ReadADC();

  if (L == 1 || R == 1) {
    MotorStop(10);
    Backward(Speed, 300);
    UTurn(Speed, 800);
  } else if (L == 0 || R == 0) {
    MotorStop(10);
    Forward(Speed, 1);
  } else if (L == 0 || R == 1) {
    MotorStop(10);
    TurnLeft(Speed, 1);
  } else if (L == 1 || R == 0) {
    MotorStop(10);
    TurnRight(Speed, 1);
  }


}
