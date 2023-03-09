//void Can1() {  //สนาม WRG
//  Forward(Speed, 30);
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 1
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว 
//  TurnLeft();             //เลี้ยวซ้าย 2
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 3
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 4
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 5
//  TracJC(Speed,50);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 6
//  TracJC(Speed,50);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 7
//  TracJC(Speed, 50);  //เดินข้ามแยก8
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 9
//  TracJC(SlowSpeed,50);       //เตรียมเลี้ยว
//  TracJC(Speed, 50);  //เดินข้ามแยก10
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
//  TracJC(SlowSpeed,50);  //เดินข้ามแยก11
//  TracJC(SlowSpeed,30);       //เตรียมเลี้ยว
//  ao();
//  delay(500);
//  TurnLeft();             //เลี้ยวซ้าย 12
//  TracJC(ACCSpeed, 200);  //เดินข้ามแยก13
//  TracJC(ACCSpeed, 200);  //เดินข้ามแยก14
//  TracJC(0, 0);    //เตรียมหยุด ท้ายสุด
//  ao();
//}

//---------------------

void Can2(){
  Forward(Speed, 30); 
  TracJC(Speed,10);
  TracJC(Speed,0);
  TurnLeft();
  TracJC(Speed,0);
  TurnLeft();
  TracJC(Speed,10);
  TracJC(Speed,0);
  TurnLeft();
  TracTime(Speed,1000);
  
}
