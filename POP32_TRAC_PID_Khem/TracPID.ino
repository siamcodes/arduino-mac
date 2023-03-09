void TracPID()      //แทรกเส้นนแบบ PID 7 เซนนเซอร์
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(Error) <= 3) KpTemp = 1; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID
  
  LeftOutput = LeftSpeed + Output;        //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้าย์หยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวา์หยุด

  fd2(LeftOutput, RightOutput);  //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error;              //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;            //บวกผลรวมของ Error ไปเรื่ื่อยๆ
}

void TracJC(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeed(MotorSpeed);
  CalError();
  while (Error < 100) {                  //ยังไม่เจอแยก ให้้ทำการ TracPID
    TracPID();
    CalError();
  }
  Forward(MotorSpeed, Time);
}

/*
void TracSonar(int MotorSpeed, int Distance) { //แทรกเส้น PID นเจอวัตถุให้หยุด
  InitialSpeed(MotorSpeed);
  while (sonar() > Distance) {   //เกินระยะที่กำหนดดให้ แทรก 
    CalError();
    TracPID();
  }
}
*/

void TracTime(int MotorSpeed, int Time) {   //แทรกเส้น PID แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {                   //ยังไม่ถึงเวลาที่กำหนดให้ทำต่อไป
    CalError();
    TracPID();
    ReadTimer0();
  }
}
