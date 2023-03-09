#define PWM1 2
#define INA1 3
#define INB1 4

 #define PWM2 5
 #define INA2 6
 #define INB2 7

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);

  //Free wheel สั่งล้อหมุุนอิสระ ไม่มีแรงหน่วง
  //digitalWrite(INA_PIN, HIGH);
  //digitalWrite(INB_PIN, LOW);
  //delay(1000);  //หน่วงเวลา 1 วินาที
}

void loop() {
  int i;

  //CW Run สั่งล้อหมุุนทิศทางที่ 1
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, LOW);
  
  for (i = 0; i < 255; i++) {   //Speed 0 to 255
    analogWrite(PWM1, i);       //0% Speed=0, 100% Speed=255
    analogWrite(PWM2, i);
    delay(20);
  }
  
  for (i = 255; i > 0; i--) {   //Slow 255 to 0
    analogWrite(PWM1, i);       //0% Speed=0, 100% Speed=255
    analogWrite(PWM2, i);
    delay(20);
  }

  //Break สั่งเบรค แกนมอเตอร์จะพยายามล็อกตัวเอง
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, HIGH);
  delay(1000);

  //CCW Run สั่งล้อหมุุนทิศทางที่ 2
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, HIGH);
  digitalWrite(INA2, LOW);
  digitalWrite(INB2, HIGH);
  
  for (i = 0; i < 255; i++) {   //Speed 0 to 255
    analogWrite(PWM1, i);       //0% Speed=0, 100% Speed=255
    analogWrite(PWM2, i);
    delay(20);
  }
  
  for (i = 255; i > 0; i--) {   //Slow 255 to 0
    analogWrite(PWM1, i);       //0% Speed=0, 100% Speed=255
    analogWrite(PWM2, i);
    delay(20);
  }

  //Break สั่งเบรค แกนมอเตอร์จะพยายามล็อกตัวเอง
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, HIGH);  
  delay(1000);

}
