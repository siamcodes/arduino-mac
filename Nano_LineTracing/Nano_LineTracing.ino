int ML1 = 9;
int ML2 = 10;
int MR1 = 5;
int MR2 = 6;

int Speed = 70;  //ความเร็วปกติ
int ACCSpeed = 100;  //ความเร็วตอนเร่ง
int SlowSpeed = 50; //ความเร็วตอนช้า


void setup() {
  Serial.begin(9600);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);

  Forward(Speed, 2000);   
  //Backward(Speed, 2000);
  //TurnLeft(Speed, 400);
  //TurnRight(Speed, 400);
  //UTurn(Speed,800);
  MotorStop();
  
}

void loop() {
  Serial.begin(9600);
  ShowADC();  //เมื่อใช้งานจริงให้ Comment ใว้
  
}
