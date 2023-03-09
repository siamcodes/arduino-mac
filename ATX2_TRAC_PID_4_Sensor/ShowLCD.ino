void ShowLCD(){
  glcdClear();  //เคลียร์หน้าจอ
  glcdFillScreen(GLCD_BLUE);  //กำหนดสีพื้ื้นหลัง
  glcdMode(3);  //โหมดหน้าจอ 270 องศา
  setTextSize(2); //ขนาดตัวอักษร
  glcd(1,2, "ATX2+"); //แสดงข้อความแถว1 คอลัมน์3
  setTextColor(GLCD_YELLOW); //กำหนดสีข้อความ
  glcd(3,0, "Robot PID"); //แสดงข้อความแถว3 คอลัมน์1
}
