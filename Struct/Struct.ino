struct LED {
  String name;
  int iot = 12;
  int ntp = 15;
  int wifi = 2;
  int bt = 17;
};

struct LED led1;

void setup() {
  Serial.begin()9600;
  pinMode(led1.iot, OUTPUT);
  pinMode(led1.ntp, OUTPUT);
  pinMode(led1.wifi, OUTPUT);
  pinMode(led1.bt, OUTPUT);
  led1.name = "Design by Somkiat";
}

void loop() {
  Serial.println("Hello "+  led1.name);
  digitalWrite(led1.iot, LOW);
  delay(1000);
  digitalWrite(led1.iot, HIGH);
  delay(1000);
}
