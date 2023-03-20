void MotorStop()  // มอเตอรหยุด
{
  ao();       //มอเตอร 2ตัวหยุด
  delay(10); //หน่วงเวลา 20 ms (1s= 1000ms)
}

void Forward(int MotorSpeed, int Time) //เดินหน้าหน่วงเวลา
{
  InitialSpeed(MotorSpeed);   //กำาหนดความเร็วต่างๆ
  fd2(LeftSpeed, RightSpeed); // เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time)  //เดินหน้าหน่วงเวลา
{
  InitialSpeed(MotorSpeed);   //กำหนดความเร็วต่างๆ
  bk2(LeftSpeed, RightSpeed); // เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(400);
//  ConvertADC();
//  while (L < 10) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(100);    //ปรับค่าให้เลี้ยวตรงเส้น
//  ConvertADC();
//  while (R < 10) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}

void UTurn() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
//  ConvertADC();
//  while (R < 10) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}
