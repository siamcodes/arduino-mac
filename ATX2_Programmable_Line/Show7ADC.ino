void Show7ADC() // เเสดงค่าสีที่หน้าจอLCD
{
  Read7ADC();
  // glcdClear();               //เคลียร์หน้าจอ
  // glcdFillScreen(GLCD_BLUE); //กำหนดพื้นหลังให้เป็นสีน้ำเงิน
  glcdMode(3);                  //กำหนดโหมดของ270องศา
  // setTextColor(GLCD_RED);    //กำหนดสีของตัวอักษรให้เป็นสีเเดง
  setTextSize(1);               //กำหนดขนาดของตัวอักษร
  glcd(0, 0, "L3 = %d", L3);
  glcd(1, 0, "L2 = %d", L2);
  glcd(2, 0, "L1 = %d", L1);
  glcd(3, 0, "C = %d", C);
  glcd(4, 0, "R1 = %d", R1);
  glcd(5, 0, "R2 = %d", R2);
  glcd(6, 0, "R3 = %d", R3);
}
