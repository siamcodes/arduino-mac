void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  Convert7ADC();
  if (C == 0) Forward(MotorSpeed, 1);
  else if (L3 == 0) tl(70);
  else if (L2 == 0) tl(40);
  else if (L1 == 0) tl(20);
  else if (R3 == 0) tr(70);
  else if (R2 == 0) tr(40);
  else if (R1 == 0) tr(20);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  Convert7ADC();
  while ((L2 == 1) || (R2 == 1)) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalSonar(int MotorSpeed, int Distance) { //แทรกเส้นธรรมดา นเจอวัตถุให้หยุด
  Forward(MotorSpeed, 1);
  while (sonar() > Distance) { 
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
