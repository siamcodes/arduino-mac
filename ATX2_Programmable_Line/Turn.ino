void TurnLeft() {
  MotorStop();
  sl(TurnSpeed);
  delay(6000 / TurnSpeed);
  sl(TurnSpeed / 2);
  Convert7ADC();
  while (L2 == 1) {
    Convert7ADC();
  }
  MotorStop();
}

void TurnRight() {
  MotorStop();
  sr(TurnSpeed);
  delay(6000 / TurnSpeed);
  sr(TurnSpeed / 2);
  Convert7ADC();
  while (R2 == 1) {
    Convert7ADC();
  }
  MotorStop();
}

void UTurnLeft() {
  MotorStop();
  MotorStop();
  sl(TurnSpeed);
  delay(18000 / TurnSpeed);
  Convert7ADC();
  while (L2 == 1) {
    Convert7ADC();
  }
  MotorStop();
}

void UTurnRight() {
  MotorStop();
  sr(TurnSpeed);
  delay(18000 / TurnSpeed);
  Convert7ADC();
  while (R2 == 1) {
    Convert7ADC();
  }
  MotorStop();
}

void Left(int Speed , int Time) {
  sl(SlowSpeed);
  delay(Time);
  ao();
}

void Right(int Speed , int Time) {
  sr(SlowSpeed);
  delay(Time);
  ao();
}

void TurnLeftDelay(int Speed , int Time) {
  tl(SlowSpeed);
  delay(Time);
}

void TurnRightDelay(int Speed , int Time) {
  tr(SlowSpeed);
  delay(Time);
}

void L90(){
 fd(SlowSpeed);
 while (L3==0,L2==0,C==0){sl(TurnSpeed);}
 while (L3==1,L2==1,C==1){sl(TurnSpeed);}
}

void R90(){
 fd(SlowSpeed);
 while (R3==0,R2==0,C==0){sr(TurnSpeed);}
 while (R3==1,R2==1,C==1){sr(TurnSpeed);}
}
