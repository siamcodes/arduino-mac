#define PWM_PIN 23
#define INA_PIN 22
#define INB_PIN 21

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(INA_PIN, OUTPUT);
  pinMode(INB_PIN, OUTPUT);

  //Free wheel, ลอจิกสั่งมอเตอร์ให้หมุนได้อิสระ ไม่มีแรงหน่วง
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, HIGH);
  delay(1000);  //หน่วงเวลา 1 วินาที
}

void loop() {
  int i;
  
  //CW Run ลอจิกสั่งหมุนทิศทางที่ 1
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, LOW);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_PIN, i);    // 0% Speed = 0, 100% Speed = 255
    delay(20);
  }
  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_PIN, i);    // 0% Speed = 0, 100% Speed = 255
    delay(20);
  }

  //Break ลอจิกสั่งเบรค 
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, HIGH);
  delay(1000);    //หน่วงเวลา 1 วินาที

    //CCW Run ลอจิกสั่งหมุนทิศทางที่ 2
  digitalWrite(INA_PIN, LOW);
  digitalWrite(INB_PIN, HIGH);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_PIN, i);    // 0% Speed = 0, 100% Speed = 255
    delay(20);
  }
  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_PIN, i);    // 0% Speed = 0, 100% Speed = 255
    delay(20);
  }

  //Break ลอจิกสั่งเบรค 
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, HIGH);
  delay(1000);    //หน่วงเวลา 1 วินาที

}
