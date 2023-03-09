#define LED1 23
#define LED2 22
const int LED3 = 19;
const int LED4 = 18;
const int LED5 = 17;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED4, HIGH);
  delay(100);
  digitalWrite(LED4, LOW);
  delay(100);
  digitalWrite(LED5, HIGH);
  delay(100);
  digitalWrite(LED5, LOW);
  delay(100);
}
