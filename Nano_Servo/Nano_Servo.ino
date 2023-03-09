#include <Servo.h>
Servo myservo;          //ประกาศตัวแปรแทน Servo
int led = 13;
int val = 0;


void setup()
{
  Serial.begin(9600);
  myservo.attach(9);    //กำหนดขา 9 ควบคุม Servo
  pinMode(A0, INPUT);   // sets the pin as input
  pinMode(led, OUTPUT);
  myservo.write(0);     // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(1000);          // หน่วงเวลา 1000ms
}

void loop()
{
  val = analogRead(A0); //อ่านค่าสัญญาณ digital ขา8 ที่ต่อกับเซ็นเซอร์
  Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.print(val); // พิมพ์ค่าของตัวแปร val
  Serial.print(" mm\n");
  if (val < 80) {       // ค่า เป็น 0 ตรวจจับเจอวัตถุ สั่งให้ไฟ LED ติด
    myservo.write(0);    // สั่งให้ Servo หมุนไปองศาที่ 90
    digitalWrite(led, HIGH);
    delay(1000);          // หน่วงเวลา 1000ms
    // while(1){}
  }
  else {
    myservo.write(90);     // สั่งให้ Servo หมุนไปองศาที่ 0
    digitalWrite(led, LOW);
    delay(1000);          // หน่วงเวลา 1000ms
    // while(1){}
  }
  delay(100);

}
