#include <ATX2.h>
int  RefR = 500, RefL = 500, RefC = 500;
int L, R, C;

void setup() {
  setTextSize(3);
  glcdMode(3);

}
void loop() {
  R = analog(4);
  L = analog(5);
  C = analog(6);

  glcd(0, 0, "R=%d ", analog(4));
  glcd(1, 0, "L=%d ", analog(5));
  glcd(2, 0, "C=%d ", analog(6));
  glcd(3, 0, "UL=%d ", sonar());

  if ((L > RefL) && (R > RefR) && (C < RefC)) { 
    FD(100);
  } else if ((L > RefL && R <= RefR)) {
    SR(50);
  } else if ((L < RefL && R > RefR)) {
    SL(50);
  } else {
    FD(50);
  }

  if (sonar() < 10) {
    BK(100); delay(50); AO();
    SR(40); delay(400); AO();
    FD(40); delay(800); AO();
    SL(40); delay(800); AO();
  }
}
