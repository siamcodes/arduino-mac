#define MOTOR_A_IA 5  //มอเตอร์ A Input  A
#define MOTOR_A_IB 6  //มอเตอร์ A Input  B

#define MOTOR_A_PWM  MOTOR_A_IA   // มอเตอร์ A PWM Speed
#define MOTOR_A_DIR  MOTOR_A_IB   // มอเตอร์ A Direction

#define PWM_SPEED1  100
#define PWM_SPEED2  1000
#define DIR_DELAY  3000

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);  
  digitalWrite(MOTOR_A_DIR, LOW);  //stop
  digitalWrite(MOTOR_A_PWM, LOW);  //stop

}

void loop() {
  Serial.println("speed 1 forward");
  digitalWrite(MOTOR_A_DIR, LOW);     //direction
  analogWrite(MOTOR_A_PWM, PWM_SPEED2); //PWM speed1
  delay(DIR_DELAY);

}
