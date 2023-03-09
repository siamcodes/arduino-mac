void Can1() {
  ReadADC();
  Forward(Speed, 1);
  
  if(C <= 20){
    MotorStop();
    TurnLeft(Speed, 400);
    Forward(Speed, 3000);
  }
  
  
}
