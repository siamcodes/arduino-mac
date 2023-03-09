void Can1() {
  ReadADC();

  if (L == 1 || R == 1) {
    MotorStop();
    Backward(Speed, 300);
    UTurn(Speed, 800);
  } else if (L == 0 || R == 0) {
    MotorStop();
    Forward(Speed, 1);
  } else if (L == 0 || R == 1) {
    MotorStop();
    TurnLeft(Speed, 1);
  } else if (L == 1 || R == 0) {
    MotorStop();
    TurnRight(Speed, 1);
  }


}
