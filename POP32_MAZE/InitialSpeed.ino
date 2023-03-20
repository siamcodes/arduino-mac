void InitialSpeed(int MotorSpeed) {
  if (MotorSpeed <= 30) {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed ;
  }
  else if (MotorSpeed <= 50) {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed - 2;
  }
  else if (MotorSpeed <= 70) {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100) {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
}
