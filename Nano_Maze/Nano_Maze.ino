int MR1 = 5;
int MR2 = 6;
int ML1 = 9;
int ML2 = 10;

int L1,R1,C;

int Speed=100;
int ACCSpeed=250;
int SlowSpeed=70;
int TurnSpeed=70;


void setup() {
  Serial.begin(9600);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  //Forward(Speed, 2000);
 // TurnLeft(Speed, 400);   
  TurnRight(Speed, 400); 
  MotorStop();
}

void loop() {
  //ShowADC();
  
}
