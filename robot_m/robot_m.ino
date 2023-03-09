/*  //BOX2
  #define PWML  3
  #define INAL  4
  #define INBL 5

  //BOX2
  #define PWMR  0
  #define INAR  1
  #define INBR  2
*/
//BOX2
#define PWML  2
#define INAL  3
#define INBL 4

//BOX2
#define PWMR  5
#define INAR  6
#define INBR  7

//sensor วัตถุ
#define IR_LL 29
#define IR_L  31
#define IR_M  33
#define IR_R  35
#define IR_RR  27

//#define SW  41

//sensor เส้น
#define Line_L  A15
#define Line_R  A14
// สีดำ = 1 สีขาว =0

int L = 0;    //เซ็นเซอร์เช็คพื้น ฝั่ง ซ้าย
int R = 0;   //เซ็นเซอร์เช็คพื้น ฝั่ง ขวา

int LL = 0;   //เซ็นเซอร์เช็ควัตถุ ฝั่งซ้าย
int RR = 0;   //เซ็นเซอร์เช็ควัตถุ ฝั่งขวา
int MM = 0;  //เซ็นเซอร์เช็ควัตถุ ฝั่งกลาง
int LLL = 0;  //เซ็นเซอร์เช็ควัตถุ ฝั่งซ้ายสุด
int RRR = 0;   //เซ็นเซอร์เช็ควัตถุ ฝั่งขวาสุด

void read_sensor();
void STOP();
void Forward(int SpeedL, int SpeedR);
void Backward(int SpeedL, int SpeedR);
void Right(int SpeedL, int SpeedR);
void Left(int SpeedL, int SpeedR);

void setup() {
  Serial.begin(115200);
  Serial.println("Delay 5 Min");
  delay(5000);
  pinMode(PWML, OUTPUT);
  pinMode(INAL, OUTPUT);
  pinMode(INBL, OUTPUT);

  pinMode(PWMR, OUTPUT);
  pinMode(INAR, OUTPUT);
  pinMode(INBR, OUTPUT);

  pinMode(IR_LL, INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_RR, INPUT);

  pinMode (Line_L, INPUT);
  pinMode (Line_R, INPUT);

  /*pinMode(SW, INPUT_PULLUP);
    while (digitalRead(SW) != 0) {
    } delay(5000);
    Serial.println("Robotstart");*/
}

void loop() {
  delay(100);
  Serial.println("Robotstart");
  read_sensor();
//  if ((L >= 300) || (R >= 300)) {
//    delay(100);
//    Forward(255, 255);
//
//  }
  
  if ((LLL == 0) && (LL == 0) && (MM == 1) && (RR == 0) && (RRR == 0)) {//เดินหน้าเต็มกำลัง
    Forward(255, 255);
  }else if ((LLL == 0) && (LL == 1) && (MM == 1) && (RR == 1) && (RRR == 0)) {//เดินหน้าเต็มกำลัง
    Forward(255, 255);
  } else if ((LLL == 0) && (LL == 1) && (MM == 0) && (RR == 0) && (RRR == 0)) {//เอียงซ้าย
    Left(100, 200);
  }  else if ((LLL == 1) && (LL == 0) && (MM == 0) && (RR == 0) && (RRR == 0)) {//ซ้ายสุดตัว
    Left(255, 255);
  } else if ((LLL == 1) && (LL == 1) && (MM == 0) && (RR == 0) && (RRR == 0)) {//เอียงซ้าย?
    Left(100, 200);
  }  else if ((LLL == 0) && (LL == 1) && (MM == 1) && (RR == 0) && (RRR == 0)) {//เดินหน้าเอียงซ้าย
    Left(100, 200);
  }else if ((LLL == 0) && (LL == 0) && (MM == 0) && (RR == 0) && (RRR == 1)) {//ขวาสุดตัว
    Right(255, 255);
  } else if ((LLL == 0) && (LL == 0) && (MM == 0) && (RR == 1) && (RRR == 0)) {//เอียงขวา
    Right(200, 100);
  } else if ((LLL == 0) && (LL == 0) && (MM == 0) && (RR == 1) && (RRR == 1)) {//เอียงขวา?
    Right(200, 100);
  } else if ((LLL == 0) && (LL == 0) && (MM == 1) && (RR == 1) && (RRR == 0)) {//เดินหน้าเอียงขวา
    Right(100, 200);
  }else if ((R <= 300)) {
    STOP();
    delay(100);
    Backward(255, 255);
    delay(1000);
    Left(100, 200);
    delay(500);
  }else if ((L <= 300)) {
    STOP();
    delay(100);
    Backward(255, 255);
    delay(1000);
    Right(100, 200);
    delay(500);
  }
  
  /*else if ((LLL == 0) && (LL == 0) && (MM == 1 ) && (RR == 0) && (RRR == 0)) {//เอียงซ้าย
    Left(150, 200);
    delay(500);
    Right(200,150);
    delay(500);
    } */
}

void read_sensor() {
  L = analogRead(Line_L);    //เซ็นเซอร์เช็คพื้น ฝั่ง ซ้าย
  R = analogRead(Line_R);   //เซ็นเซอร์เช็คพื้น ฝั่ง ขวา

  LLL = digitalRead(IR_LL);   //เซ็นเซอร์เช็ควัตถุ ฝั่งซ้ายสุด
  LL = digitalRead(IR_L);   //เซ็นเซอร์เช็ควัตถุ ฝั่งซ้าย
  MM  = digitalRead(IR_M);   //เซ็นเซอร์เช็ควัตถุ ฝั่งกลาง
  RR = digitalRead(IR_R);   //เซ็นเซอร์เช็ควัตถุ ฝั่งขวา
  RRR = digitalRead(IR_RR);   //เซ็นเซอร์เช็ควัตถุ ฝั่งขวาสุด

  Serial.print("Line_L ="); Serial.print(L); Serial.print('\t');
  Serial.print("Line_R ="); Serial.print(R); Serial.print('\t');
  Serial.print("LLL ="); Serial.print(LLL); Serial.print('\t');
  Serial.print("LL ="); Serial.print(LL); Serial.print('\t');
  Serial.print("MM ="); Serial.print(MM); Serial.print('\t');
  Serial.print("RR ="); Serial.print(RR); Serial.print('\t');
  Serial.print("RRR ="); Serial.println(RRR);
}

void STOP() {
  digitalWrite(INAL, LOW);
  digitalWrite(INBL, HIGH);
  analogWrite(PWML, 0);
  digitalWrite(INAR, HIGH);
  digitalWrite(INBR, LOW);
  analogWrite(PWMR, 0);
}

//เดินหน้า
void Forward(int SpeedL, int SpeedR) {
  Serial.println("Forward");
  digitalWrite(INAL, HIGH);
  digitalWrite(INBL, LOW);
  analogWrite(PWML, SpeedL);
  digitalWrite(INAR, LOW);
  digitalWrite(INBR, HIGH);
  analogWrite(PWMR, SpeedR);
}

//เดินถอยหลัง
void Backward(int SpeedL, int SpeedR) {
  Serial.println("Backward");
  digitalWrite(INAL, LOW);
  digitalWrite(INBL, HIGH);
  analogWrite(PWML, SpeedL);
  digitalWrite(INAR, HIGH);
  digitalWrite(INBR, LOW);
  analogWrite(PWMR, SpeedR);
}

//ขวา
void Right(int SpeedL, int SpeedR) {
  Serial.println("Turn Right");
  digitalWrite(INAL, HIGH);
  digitalWrite(INBL, LOW);
  analogWrite(PWML, SpeedL);
  digitalWrite(INAR, LOW);
  digitalWrite(INBR, HIGH);
  analogWrite(PWMR, SpeedR);
}

//ซ้าย
void Left(int SpeedL, int SpeedR) {
  Serial.println("Turn Left");
  digitalWrite(INAL, HIGH);
  digitalWrite(INBL, LOW);
  analogWrite(PWML, SpeedL);
  digitalWrite(INAR, LOW);
  digitalWrite(INBR, HIGH);
  analogWrite(PWMR, SpeedR);
}
