int R,L;
int IR,IL,IC;
int ML1=5;
int ML2=6;
int MR1=9;
int MR2=10;

int Speed=50;
int ACCSpeed=100;

void setup() {
  Serial.begin(9600);   //เปิดใช้งาน Serial
  pinMode(ML1,OUTPUT);  
  pinMode(ML2,OUTPUT);
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);
  
  //Forward(Speed, 500);
  //TurnLeft(Speed, 400);  //ตัวแรกคือ ความเร็ว ตัวหลังคือเวลา 400
  //TurnRight(Speed, 400);  
  //UTurn(Speed,800);       
  //MotorStop();

}

void loop() {
   ShowADC();
  // Can1();
}
