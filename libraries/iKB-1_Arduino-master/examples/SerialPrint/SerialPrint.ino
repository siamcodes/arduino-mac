#include <iKB-1.h>
#include <Wire.h>

iKB_1 ikb(&Wire1);

void setup() {
  Wire1.begin(4, 5);
  ikb.begin();
  ikb.Serial->begin(9600);
}

void loop() {
  ikb.Serial->println("Hello, iKB-1");
  delay(100);
}
