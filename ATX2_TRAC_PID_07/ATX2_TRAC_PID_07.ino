#include <ATX2.h>
int L3, L2, L1, C, R1, R2, R3; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL3, RefL2, RefL1, RefC, RefR1, RefR2, RefR3; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 70;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 50; //ความเร็วตอนช้า 50
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 70

  XIO();          //ประกาศ INPUT/OUTPUT ภายนอก
  beep(1);        //เสียงบัซเซอร์ 0-3
  //GripDown();     //ยกแขนลง
  //Grip();         //คีบ
  //ShowLCD();      //แสดงค่าเริ่ิ่มต้น LCD ตอนเปิิดเครื่อง
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //delay(500);   //หน่วงเวลา
  Show7ADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  Initial7ADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  // Forward(100, 2000); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็็นนเวลา 2 วินาที
  // TurnLeft();
  // TurnRight();
  // UTurn();
  // TracNormalJC(Speed, 50);
  // TracNormalSonar(Speed, 5);
  // TracNomalTime(ACCSpeed,1000);
  // MotorStop();
  ResetTimer1();
  
}

void loop() {
  // Can1Normal();
  // CalError();
  // TracPID();
  // TracJC(Speed,0);
  // TracSonar(Speed,4);
  // TracTime(Speed, 2000);
  Can2();
  Finish();
}
