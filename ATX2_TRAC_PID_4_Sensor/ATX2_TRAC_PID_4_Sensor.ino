#include <ATX2.h>
int L2, L1, R1, R2; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefR1, RefR2; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID
int Sonar;

void setup() {
  Speed = 50;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 20; //ความเร็วตอนช้า 50
  TurnSpeed = 30;  //ความเร็วตอนเลี้ยว 70

  XIO();          //ประกาศ INPUT/OUTPUT ภายนอก
  beep(1);        //เสียงบัซเซอร์ 0-3

  //GripDown();     //ยกแขนลง
  //Grip();         //คีบ
  //ShowLCD();      //แสดงค่าเริ่ิ่มต้น LCD ตอนเปิิดเครื่อง
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //delay(500);   //หน่วงเวลา

  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  //Forward(Speed, 500); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็็นนเวลา 2 วินาที
  // TurnLeft();
  // TurnRight();
  // UTurn();
  // TracNormalJC(Speed, 50);
  // TracNormalSonar(Speed, 5);
  // TracNomalTime(ACCSpeed,1000);
  //MotorStop();
  ResetTimer1();
  InitialSpeed(20);  //ทดสอบวิ่งที่ 50
}

void loop() {
  Trac(20);
  // Can1Normal();
  // CalError();
  // TracPID();
  // TracJC(Speed,0);
 // Finish();
}
