void Trac(int MotorSpeed) //เดินตามเส้นปกติ 5 เซ็นเซอร์
{
  Convert7ADC();
  if (C == 0) Forward(MotorSpeed, 1); //ตัวกลางเจอสีดำ
  else if (L2 == 0) tl(80); //ด้านซ้ายเจอสีดำ
  else if (L1 == 0) tl(60); //ด้านซ้ายเจอสีดำ
  else if (R2 == 0) tr(80); //ด้านขวาเจอสีดำ
  else if (R1 == 0) tr(60); //ด้านขวาเจอสีดำ

}
