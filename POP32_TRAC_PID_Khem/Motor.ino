void MotorStop(){ //มอเตอร์หยุด
   ao();  //มอเตอร์หยุดทั้งหมด
   delay(10); //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  FD2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  BK2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() {     //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed);      //หมุนซ้าย
  delay(100);
  Convert7ADC();
  while (L2 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}

void TurnRight() {    //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed);      //หมุนซ้าย
  delay(100);         //ปรับค่าให้เลี้ยวตรงเส้น
  Convert7ADC();
  while (R2 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}

void UTurn() {        //ขวา
  MotorStop();
  sr(TurnSpeed);      //หมุนซ้าย
  delay(300);         //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  Convert7ADC();
  while (R2 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}
