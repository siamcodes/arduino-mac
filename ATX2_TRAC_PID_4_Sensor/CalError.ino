void CalError() {   //กำรคำนวณ Error
  ConvertADC();    //เปลี่ยนจาก analog เป็็น digital (สีดำ=0 สีขาว=1)
  if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 1) ) Error = 6;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 0) ) Error = 5;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 0) ) Error = 4;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 0) && (R2 == 0) ) Error = 3;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 0) && (R2 == 1)) Error = 2;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 0) && (R2 == 1) ) Error = 1;
  else if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 1) ) Error = 0;
  else if ( (L2 == 1) && (L1 == 0)  && (R1 == 1) && (R2 == 1) ) Error = -1;
  else if ( (L2 == 1) && (L1 == 0)  && (R1 == 1) && (R2 == 1) ) Error = -2;
  else if ( (L2 == 0) && (L1 == 0)  && (R1 == 1) && (R2 == 1) ) Error = -3;
  else if ( (L2 == 0) && (L1 == 1)  && (R1 == 1) && (R2 == 1) ) Error = -4;
  else if ( (L2 == 0) && (L1 == 1)  && (R1 == 1) && (R2 == 1) ) Error = -5;
  else if ( (L2 == 1) && (L1 == 1) && (R1 == 1) && (R2 == 1) ) Error = -6;
  // else if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 1)) Error = 99; //สิ้นสุดทาง
  else if ( (L2 == 0) && (L1 == 0)  && (R1 == 0) && (R2 == 0) ) Error = 100; //แยก + T
  else if ( (L2 == 0) && (L1 == 0) ) Error = 101; //แยกซ้าย
  else if ((R1 == 0) && (R2 == 0) ) Error = 102; //แยกขวา

}
