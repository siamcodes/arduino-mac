void MotorStop()      //มอเตอร์หยุดทำงาน
{
  ao();               //มอเตอร์ทั้งสองข้างหยุด
  delay(10);          //หน่วงเวลา 10ms(1s = 1000ms)
}

void Forward(int MotorSpeed, int Time) //เดินหน้าหน่วงเวลา
{
  InitialSpeed(MotorSpeed);            //กำหนดความเร็วต่าง
  fd2(LeftSpeed, RightSpeed);          //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time) //ถอยหน่วงเวลา
{
  InitialSpeed(MotorSpeed);           //กำหนดความเร็วต่าง
  bk2(LeftSpeed, RightSpeed);         //ถอยหลัง
  delay(Time);
}
