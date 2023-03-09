#define PWM_PIN 18
#define INA_PIN 23
#define INB_PIN 22

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(INA_PIN, OUTPUT);
  pinMode(INB_PIN, OUTPUT);

  //Free wheel สั่งล้อหมุุนอิสระ ไม่มีแรงหน่วง
  //digitalWrite(INA_PIN, HIGH);
  //digitalWrite(INB_PIN, LOW);
  //delay(1000);  //หน่วงเวลา 1 วินาที
}

void loop() {
  int i;

  //CW Run สั่งล้อหมุุนทิศทางที่ 1
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, LOW);
  
  for (i = 0; i < 255; i++) {   //Speed 0 to 255
    analogWrite(PWM_PIN, i);    //0% Speed=0, 100% Speed=255
    delay(20);
  }
  for (i = 255; i > 0; i--) {   //Slow 255 to 0
    analogWrite(PWM_PIN, i);    //0% Speed=0, 100% Speed=255
    delay(20);
  }

  //Break สั่งเบรค แกนมอเตอร์จะพยายามล็อกตัวเอง
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, HIGH);
  delay(1000);

  //CCW Run สั่งล้อหมุุนทิศทางที่ 2
  digitalWrite(INA_PIN, LOW);
  digitalWrite(INB_PIN, HIGH);
  for (i = 0; i < 255; i++) {   //Speed 0 to 255
    analogWrite(PWM_PIN, i);    //0% Speed=0, 100% Speed=255
    delay(20);
  }
  for (i = 255; i > 0; i--) {   //Slow 255 to 0
    analogWrite(PWM_PIN, i);    //0% Speed=0, 100% Speed=255
    delay(20);
  }

  //Break สั่งเบรค แกนมอเตอร์จะพยายามล็อกตัวเอง
  digitalWrite(INA_PIN, HIGH);
  digitalWrite(INB_PIN, HIGH);
  delay(1000);

}
