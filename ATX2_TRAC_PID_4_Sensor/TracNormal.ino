void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (L1 == 1 && R1 == 1) Forward(MotorSpeed, 1);
  else if (L2 == 0) tl(50);
  else if (L1 == 0) tl(30);
  else if (R2 == 0) tr(50);
  else if (R1 == 0) tr(30);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while ((L2 == 1) || (R2 == 1)) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalSonar(int MotorSpeed, int Distance) { //แทรกเส้นธรรมดา นเจอวัตถุให้หยุด
  ReadSonar();  //อ่่านค่า sonar
  Forward(MotorSpeed, 1);
  while (Sonar > Distance) {  //sonar() > Distance
    Trac(MotorSpeed);
  }
}

void TracNormalTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Forward(MotorSpeed, 1);
  while (Timer0 < Time) {
    Trac(MotorSpeed);
    ReadTimer0();
  }
}
