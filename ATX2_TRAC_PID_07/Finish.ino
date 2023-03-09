void Finish(){  //หุ่นยนต์หยุดและแสดงเวลาทั้งหมด
 ReadTimer1();
 ao();
 beep(1);
 glcdClear();
 setTextSize(2);
 glcd(0,0, "Finish"); 
 glcd(1,0,"Time = %l.%l s", Timer1/1000, Timer1%1000);
 while(1){} //หยุดวนรอบตลอดดไป
}
