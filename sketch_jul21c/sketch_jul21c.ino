#include <analogWrite.h>
#define IN1 23
#define IN2 22
#define ENA 21
#define IN3 19
#define IN4 18
#define ENB 5

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); 
  digitalWrite(ENB, LOW); 
}

void loop() {
  char ch1;
  ch1 = Serial.read();
  if(ch1 == 'w' ){ //เดินหน้า
    analogWrite(ENA,50);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENB,50);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("Motor Forward");
    delay(3000);
  }else if(ch1 == 's'){  //ถอยหลัง
    analogWrite(ENA,50);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENB,50);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Motor Backward");
    delay(3000);
  }else if(ch1 == 'a'){  //เลี้ยวซ้าย
    analogWrite(ENA,50);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENB,50);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("Motor LEFT");
    delay(3000);
  }else if(ch1 == 'd'){  //เลีเยวขวา
    analogWrite(ENA,50);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENB,50);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Motor RIGHT");
    delay(3000);
  }else{
    analogWrite(ENA,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENB,0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  
}
