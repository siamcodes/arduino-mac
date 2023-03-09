void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  glcdClear();
  glcdMode(3);    //โหมดหน้าจอ 270 องศา
  setTextSize(1); //ขนาดตัวอักษร
  glcd(1, 0, "L2 = %d", L2);
  glcd(2, 0, "L1 = %d", L1);
  glcd(3, 0, "R1 = %d", R1);
  glcd(4, 0, "R2 = %d", R2);

}

void ShowSonar() {
  ReadSonar();
  glcdClear();
  glcdMode(3);    //โหมดหน้าจอ 270 องศา
  setTextSize(1); //ขนาดตัวอักษร
  glcd(7, 0, "Sonar = %d", Sonar);
  if(Sonar <= 5 ){
    beep();
  }
}
