#define RANGE_MIN 200
#define SPEED 40
#define PWM1 2
#define INA1 3
#define INB1 4

#define PWM2 5
#define INA2 6
#define INB2 7

turnLEFT();
turnRIGHT();
forWARD();
allSTOP();

void setup() {
  serial.begin(9600);

  pinMode(PWM1, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);

}

void loop() {
  int range = analog(1);
  int dir = analog(2);

  if (range > RANGE_MIN) {
    if (dir < 400) {
      turnLEFT(SPEED);
    } else if (dir > 600) {
      turnRIGHHT(SPEED)
    } else {
      forWARD(SPEED);
    }

  } else {
    allSTOP();
  }

}


void turnLEFT(int SPEED) {
  digitalWrite(PWM1, HIGH);
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  delay(SPEED);
}

void turnRIGHT() {
  digitalWrite(PWM1, HIGH);
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, HIGH);
  delay(SPEED);
}

void forWARD() {
  digitalWrite(PWM1, HIGH);
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  delay(SPEED);
}

void allSTOP() {
  digitalWrite(PWM1, HIGH);
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, LOW);
  delay(SPEED);
}
