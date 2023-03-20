#include <POP32.h>
#define Encoder_output_A2 6 // Motor Left Green
#define Encoder_output_B2 5 // Motor Left Yellow
#define Encoder_output_A1 4 // Motor Right Green
#define Encoder_output_B1 3 // Motor Right Yellow
int PulseML = 0;
int PulseMR = 0;

int L, C, R;
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed;   //ตัวแปรเกื่ยวกับความเร็ว

void setup() {
  pinMode(Encoder_output_A2, INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder_output_B2, INPUT); // sets the Encoder_output_B pin as the input
  pinMode(Encoder_output_A1, INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder_output_B1, INPUT); // sets the Encoder_output_B pin as the input

  Speed = 50;         //ความเร็วปกติ
  ACCSpeed = 100;     //ความเร็วตอนนเร่ง
  SlowSpeed = 30;     //ความเร็วตอนช้า
  TurnSpeed = 70;     //ความเร็วตอนเลี้ยว
  beep();           //เสียงบัซเซอร์ 0-3
  ShowADC();
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok

  //Forward(Speed, 1000);
  //Backward(Speed, 1000);
  TurnLeft();
  //TurnRight();
  //UTurn();
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A2), EncoderML, RISING);   //Interrupt Motor L (Channel A2)
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A1), EncoderMR, RISING);   //Interrupt Motor R (Channel A1)
  MotorStop();
  beep(1);
  ShowEncode();
}

void loop() {
  //ShowADC();
  //Can();
}
