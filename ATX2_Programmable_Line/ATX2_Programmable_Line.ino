#include <ATX2.h>	// ATX2 Board
int L3, L2, L1, C, R1, R2, R3; //ตัวเเปลในการเก็บค่าสีจากเซ็นเซอร์
int RefL3, RefL2, RefL1, RefC, RefR1, RefR2, RefR3; //ตัวเเปลในการเก็บค่าเฉลี่ยสีจากเซ็นเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวเเปลความเร็ว
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรเกี่ยวกับ PID

void setup() {

  Speed = 60;       //ความเร็ววิ่งปกติ
  ACCSpeed = 80;    //ความเร็วตอนเร่ง
  SlowSpeed = 40;   //ความเร็วตอนช้า
  TurnSpeed = 60;   //ความเร็วตอนเลี้ยว
  XIO();            // ประกาศ input/Output ภายนอก
  //OK();
  beep(1);         //เสียงบัซเซอร์ 0-3
  //ShowLCD();     //เเสดงข้อความตอนเปิดเครื่อง
  //sw_ok_press(); //รอจนกว่าจะกดปุ่ม ok
  //beep(2);
  Show7ADC();     // เเสดงค่าสีที่หน้าจอLCD
  Initial7ADC();  //ใส่ค่าเฉลี่ยสีของเซ็นเซอร์
  sw_ok_press();  //รอจนกว่าจะกดปุ่ม ok
  beep(2);
  //Forward(int MotorSpeed,int Time) //เดินหน้าหน่วงเวลา
  InitialSpeed(50);  //ทดสอบวิ่งที่ 50
}

void loop() {
  // Trac(Speed);  //เดินตามเส้นธรรมดา
  // Show7ADC();   //เเสดงค่าสีที่หน้าจอLCD (ตอนใช้งานจริงใส่ Comment)
  //CalError();      //เรียกใช้ CalError
  //TracPID();       //เดินตามเส้นแบบ PID

  //TracJC(Speed,0); // เดินเจอแยกแล้ว
  //Finish();        //หยุดถึงเส้นชัย
  Can1();

}
