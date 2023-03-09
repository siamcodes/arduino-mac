const int EA = 19;
const int EB = 18;

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(EA, ledChannel);
  ledcAttachPin(EB, ledChannel);
}

void loop() {
  ledcWrite(ledChannel, 20);
  delay(1000);
  ledcWrite(ledChannel, 20);
  delay(1000);
}
