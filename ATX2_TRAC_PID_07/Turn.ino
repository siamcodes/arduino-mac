void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(100);
  Convert7ADC();
  while (L2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(100);    //ปรับค่าให้เลี้ยวตรงเส้น
  Convert7ADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}


void UTurn() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(300);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  Convert7ADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    Convert7ADC();
  }
  MotorStop();
}
