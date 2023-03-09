void TracPID()    //Trac เส้นแบบ PID 7 Sensor
{
  int Output, LeftOutput, RightOutput, KpTemp;
  int intersec = 1;

  if (abs(Error) <= 1) KpTemp = 1; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + (Kd * (Error - PreError)); //สมการ PID
  LeftOutput = LeftSpeed + Output;  //ความเร็วมอเตอร์ด้านซ้าย
  RightOutput = RightSpeed - Output;  // ความเร็วมอเตอร์ด้านขวา
  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;
  if (RightOutput < 0) RightOutput = 0;
  fd2(LeftOutput, RightOutput);
  PreError = Error;
  Integral += Error;

}

void TracJC(int MotorSpeed, int Time){
  InitialSpeed(MotorSpeed);
  CalError();
  while (Error < 100) {
    TracPID();
    CalError();
  }
  Forward(MotorSpeed, Time);
}
