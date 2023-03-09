#define PWM_M1 23
#define INA_M1 22
#define INB_M1 21

#define PWM_M2 19
#define INA_M2 18
#define INB_M2 17

int SN1 = 10;
int SN2 = 20;
int S1 ;
int S2 ;

int i;

void setup() {
  pinMode(PWM_M1, OUTPUT);
  pinMode(INA_M1, OUTPUT);
  pinMode(INB_M1, OUTPUT);

  pinMode(PWM_M2, OUTPUT);
  pinMode(INA_M2, OUTPUT);
  pinMode(INB_M2, OUTPUT);

  pinMode(SN1, INPUT);
  pinMode(SN2, INPUT);

}

void loop() {

  S1 = digitalRead(SN1);
  S2 = digitalRead(SN2);
  
  if(S1 == LOW && S2 == LOW){
     forward();
  }else if(S1 == HIGH && S2 == HIGH){
     backward();
  }else if(S1 == LOW && S2 == HIGH){
     turnleft();
  }else if(S1 == HIGH && S2 == LOW){
     turnright();
  }else{
    stopped();
  }
  
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

  for (i = 255; i > 0; i--) { //ค่อยๆ ลดความเร็ว จาก 255 ถึง 0
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

  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 255 ถึง 0
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }
}

void turnleft() {
  //CCW Run ลอจิกสั่งหมุนทิศทางที่ 2
  digitalWrite(INA_M1, LOW);
  digitalWrite(INB_M1, HIGH);
  digitalWrite(INA_M2, HIGH);
  digitalWrite(INB_M2, LOW);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }

  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 255 ถึง 0
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }
}

void turnright() {
  //CCW Run ลอจิกสั่งหมุนทิศทางที่ 2
  digitalWrite(INA_M1, HIGH);
  digitalWrite(INB_M1, LOW);
  digitalWrite(INA_M2, LOW);
  digitalWrite(INB_M2, HIGH);

  for (i = 0; i < 255; i++) { //ค่อยๆ เพิ่มความเร็ว จาก 0 ถึง 255
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }

  for (i = 255; i > 0; i--) { //ค่อยๆ เพิ่มความเร็ว จาก 255 ถึง 0
    analogWrite(PWM_M1, i);    // 0% Speed = 0, 100% Speed = 255
    analogWrite(PWM_M2, i);
    delay(20);
  }
}
