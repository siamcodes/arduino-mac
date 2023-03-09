#include <Ultrasonic.h>
Ultrasonic ultrasonic(4, 3);
#include <VNH3SP30.h>
const int trigPin1 = 11;
const int echoPin1 = 10;
const int trigPin2 = 2;
const int echoPin2 = 3;
const int trigPin3 = 12;
const int echoPin3 = 13;
float davomiylik1, davomiylik2, davomiylik3, sm1, sm2, sm3;

long duration;
int distance;
VNH3SP30 Motor1;    // define control object for motor 1
VNH3SP30 Motor2;    // define control object for motor 2

// motor pins (DIAG and CS pins not used in this example)
#define M1_PWM 5    // pwm pin motor
#define M1_INA 7    // control pin INA
#define M1_INB 8    // control pin INB

#define M2_PWM 6    // pwm pin motor
#define M2_INA 4    // control pin INA
#define M2_INB 9    // control pin INB
#define IR_left A4    //เซนเซอร์ซ้าย
#define IR_right A5   //เซนเซอร์ขวา


void setup() {
  // Setting up motor connections.
  // Please note the INA and INB pins are switched for motor2 as with this vehicle
  // this motor will run the reverse direction when the vehicle moves forward.
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Motor1.begin(M1_PWM, M1_INA, M1_INB, -1, -1);    // Motor 1 object connected through specified pins
  Motor2.begin(M2_PWM, M2_INB, M2_INA, -1, -1);    // Motor 2 object connected through specified pins
  Serial.begin(115200);
}

void FORWARD(int speed) {
  Motor1.setSpeed(speed);
  Motor2.setSpeed(speed);
}

void Stop(int brakePower) {
  Motor1.brake(brakePower);
  Motor2.brake(brakePower);
}

void turnLeft(int angle) {
  // turn vehicle by providing different speed settings to the motors.
  // angle can be positive (right turn) or negative (left turn).
  // If the vehicle is already stopped, the vehicle will turn in place.
  int currentSpeed = (Motor1.speed + Motor2.speed) / 2;
  Motor1.setSpeed(currentSpeed + angle);
  Motor2.setSpeed(currentSpeed - angle);
}
void turnRight(int angle) {
  // turn vehicle by providing different speed settings to the motors.
  // angle can be positive (right turn) or negative (left turn).
  // If the vehicle is already stopped, the vehicle will turn in place.
  int currentSpeed = (Motor1.speed + Motor2.speed) / 2;
  Motor1.setSpeed(currentSpeed - angle);
  Motor2.setSpeed(currentSpeed + angle);
}
void BACKWARD(int angle) {
  // turn vehicle by providing different speed settings to the motors.
  // angle can be positive (right turn) or negative (left turn).
  // If the vehicle is already stopped, the vehicle will turn in place.
  int currentSpeed = (Motor1.speed + Motor2.speed) / 2;
  Motor1.setSpeed(currentSpeed - angle);
  Motor2.setSpeed(currentSpeed - angle);
}

void plusUltra(){
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  davomiylik1 = pulseIn(echoPin1, HIGH);
  davomiylik2 = pulseIn(echoPin2, HIGH);
  davomiylik3 = pulseIn(echoPin3, HIGH);
  sm1 = davomiylik1 / 58.2;
  sm2 = davomiylik2 / 58.2;
  sm3 = davomiylik3 / 58.2;
  Serial.print("UL1  =");   Serial.println(sm1);
  Serial.print("UL1  =");   Serial.println(sm1);
  Serial.print("UL1  =");   Serial.println(sm1);  
}

void plusUltra1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  davomiylik1 = pulseIn(echoPin1, HIGH);
  sm1 = davomiylik1 / 58.2;
  Serial.print("UL1  =");
  Serial.println(sm1);
}

void plusUltra2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  davomiylik2 = pulseIn(echoPin2, HIGH);
  sm2 = davomiylik2 / 58.2;
  Serial.print("UL2  =");
  Serial.println(sm2);
}

void plusUltra3() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  davomiylik3 = pulseIn(echoPin3, HIGH);
  sm3 = davomiylik3 / 58.2;
  Serial.print("UL3  =");
  Serial.println(sm3);
}


void loop() {
  plusUltra1();
  delayMicroseconds(5);
  plusUltra2();
  delayMicroseconds(5);
  plusUltra3();
  delayMicroseconds(5);

  //ไม่เจอขาว
  if (digitalRead(left) == 1 && digitalRead(right) == 1) {
    FORWARD(100);
  }
  //ขาวด้านขวา
  else if (digitalRead(left) == 1 && digitalRead(right) == 0) {
    Stop(0);
    delay(200);
    BACKWARD(100);
    delay(2000);
    turnLeft(100);
     Stop(0);
    delay(200);
  }

  //ขาวด้านซ้าย
  else if (digitalRead(left) == 0 && digitalRead(right) == 1) {
    Stop(0);
    delay(200);
    BACKWARD(100);
    delay(2000);
    turnRight(100);
     Stop(0);
    delay(200);
  }

  //ขาวทั้งหมด
  else if (digitalRead(left) == 0 && digitalRead(right) == 0) {
    Stop(0);
    delay(200);
    BACKWARD(100);
    Stop(0);
    delay(200);
  }

  if (sm1 > 1 && sm1 < 70) { 
    FORWARD(255);
  }
  else if (sm2 > 1 && sm2 < 70) { 
    turnRight(255);
  }
  else if (sm3 > 1 && sm3 < 70) { 
    turnLeft(255);
  }
}
