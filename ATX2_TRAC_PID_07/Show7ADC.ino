void Show7ADC() {
  Read7ADC();     //อ่านค่าเซนนเซอร์
  glcdClear();
  glcdMode(3);    //โหมดหน้าจอ 270 องศา
  setTextSize(1); //ขนาดตัวอักษร
  glcd(0, 0, "L3 = %d", L3);
  glcd(1, 0, "L2 = %d", L2);
  glcd(2, 0, "L1 = %d", L1);
  glcd(3, 0, "C = %d", C);
  glcd(4, 0, "R1 = %d", R1);
  glcd(5, 0, "R2 = %d", R2);
  glcd(6, 0, "R3 = %d", R3);
}
