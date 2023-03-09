void ReadADC() {
  L2 = analog(5);
  L1 = analog(4);
  R1 = analog(3);
  R2 = analog(2);
}

void ReadSonar() {
  Sonar = analog(7)/10;
}
