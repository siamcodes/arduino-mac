int IN1 = 23;
int IN2 = 22;
int IN3 = 21;
int IN4 = 19;
int sen1 = 17;
int sen2 = 16;
int sw1 = 12;
int sw2 = 14;


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(sen1, INPUT);
  pinMode(sen2, INPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
}

void loop() {

int s1 = digitalRead(sw1);
int s2 = digitalRead(sw2);
int sensor1 = digitalRead(sen1);
int sensor2 = digitalRead(sen2);

  if (s1 == LOW ) {
    if (sensor1 == LOW) {
      Stop();
    } else {
      Straight ();
    }

  } 
  
  if ( s2 == LOW) {
    if (sensor2 == LOW) {
      Stop();
    } else {
      Back();
    }
  }

}

void Straight () {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
}

void Back () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);
}

void Stop () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
