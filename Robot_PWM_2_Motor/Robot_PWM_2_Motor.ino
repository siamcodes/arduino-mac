#define PWM_M1 23
#define INA_M1 22
#define INB_M1 21

#define PWM_M2 19
#define INA_M2 18
#define INB_M2 17

int i;


void setup() {
  pinMode(PWM_M1, OUTPUT);
  pinMode(INA_M1, OUTPUT);
  pinMode(INB_M1, OUTPUT);

  pinMode(PWM_M2, OUTPUT);
  pinMode(INA_M2, OUTPUT);
  pinMode(INB_M2, OUTPUT);


  //Free wheel, ลอจิกสั่งมอเตอร์ให้หมุนได้อิสระ ไม่มีแรงหน่วง
  digitalWrite(INA_M1, HIGH);
  digitalWrite(INB_M1, LOW);
  digitalWrite(INA_M2, HIGH);
  digitalWrite(INB_M2, LOW);
  delay(1000);  //หน่วงเวลา 1 วินาที
}

void loop() {
  forward();
  stopped();
  backward();
  stopped();
}

void stopped() {
  //Break ลอจิกสั่งเบรค
  digitalWrite(INA_M1, HIGH);
  digitalWrite(INB_M1, HIGH);
  digitalWrite(INA_M2, HIGH);
  digitalWrite(INB_M2, HIGH);
  delay(1000);    //หน่วงเวลา 1 วินาที
}

void forward() {
  //CW Run ลอจิกสั่งหมุนทิศทางที่ 1
  digitalWrite(INA_M1, HIGH);
  digitalWrite(INB_M1, LOW);
  digitalWrite(INA_M2, HIGH);
  digitalWrite(INB_M2, LOW);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }

  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }
}

void backward() {
  //CCW Run ลอจิกสั่งหมุนทิศทางที่ 2
  digitalWrite(INA_M1, LOW);
  digitalWrite(INB_M1, HIGH);
  digitalWrite(INA_M2, LOW);
  digitalWrite(INB_M2, HIGH);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }

  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }

}
