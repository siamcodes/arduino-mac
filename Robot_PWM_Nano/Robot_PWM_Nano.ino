#define MR_IN1 5
#define MR_IN2 6
#define ML_IN1 10
#define ML_IN2 11
int SL = A7;
int SR = A6;
int sl = 0, sr = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MR_IN1, OUTPUT);
  pinMode(MR_IN2, OUTPUT);
  pinMode(ML_IN1, OUTPUT);
  pinMode(ML_IN2, OUTPUT);
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, LOW);
}

void loop() {
  sl = analogRead(SL);
  sr = analogRead(SR);
  Serial.println("Sensor L = " + (String)sl + " Sensor R = " + (String)sr);

  if (sl > 100 && sr > 100) {
    forward();
  } else if(sl > 100 && sr < 100){
    backward();
    delay(400);
    turnleft();
    delay(700);
  }
  else if(sl < 100 && sr > 100){
    backward();
    delay(400);
    turnright();
    delay(700);
  }
//  else if(sl < 100 && sr < 100){
//    backward();
//    delay(400);
//    turnright();
//    delay(1000);
//  }

  //  forward();
  //  delay(2000);
  //  stopped();
  //  delay(500);
  //  backward();
  //  delay(2000);
  //  stopped();
  //  delay(300);
  //  turnright();
  //  delay(1000);
  //  stopped();
  //  delay(300);
  //  turnleft();
  //  delay(2000);

}


void forward() {
  analogWrite(MR_IN1, 0);
  analogWrite(MR_IN2, 50);
  analogWrite(ML_IN1, 50);
  analogWrite(ML_IN2, 0);
}

void backward() {
  analogWrite(MR_IN1, 100);
  analogWrite(MR_IN2, 0);
  analogWrite(ML_IN1, 0);
  analogWrite(ML_IN2, 100);
}

void stopped() {
  analogWrite(MR_IN1, 0);
  analogWrite(MR_IN2, 0);
  analogWrite(ML_IN1, 0);
  analogWrite(ML_IN2, 0);
}

void turnright() {
  analogWrite(MR_IN1, 0);
  analogWrite(MR_IN2, 50);
  analogWrite(ML_IN1, 0);
  analogWrite(ML_IN2, 50);
}
void moveright(int A, int B) {
  analogWrite(MR_IN1, 0);
  analogWrite(MR_IN2, A);
  analogWrite(ML_IN1, 0);
  analogWrite(ML_IN2, B);
}
void turnleft() {
  analogWrite(MR_IN1, 50);
  analogWrite(MR_IN2, 0);
  analogWrite(ML_IN1, 50);
  analogWrite(ML_IN2, 0);
}
void moveleft(int A, int B) {
  analogWrite(MR_IN1, A);
  analogWrite(MR_IN2, 0);
  analogWrite(ML_IN1, B);
  analogWrite(ML_IN2, 0);
}
