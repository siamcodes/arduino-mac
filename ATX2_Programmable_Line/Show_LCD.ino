void ShowLCD() //เเสดงข้อความตอนเปิดเครื่อง
{
  glcdClear();                  //เคลียร์หน้าจอ
 // glcdFillScreen(GLCD_BLUE);    // กำหนดพื้นหลังให้เป็นสีน้ำเงิน
  glcdMode(3);                  //กำหนดโหมดของ270องศา
 // setTextColor(GLCD_RED);       //กำหนดสีของตัวอักษรให้เป็นสีเเดง
  setTextSize(2);               //กำหนดขนาดของตัวอักษร
  glcd(0,0,"ATX2+");            //เเสดงข้อความบรรทัด0หลัก0
 // setTextColor(GLCD_YELLOW);    //กำหนดสีของตัวอักษรให้เป็นสีเหลือง
  glcd(1,0,"CDTI Robot Club");           //เเสดงข้อความบรรทัด1หลัก0
}
