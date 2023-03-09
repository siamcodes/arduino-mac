void Can1() {  //สนาม WRG
  Forward(Speed, 30);
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 1
  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว 
  TurnLeft();             //เลี้ยวซ้าย 2
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 3
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 4
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 5
  TracJC(Speed,50);       //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 6
  TracJC(Speed,50);       //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 7
  TracJC(Speed, 50);  //เดินข้ามแยก8
  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 9
  TracJC(SlowSpeed,50);       //เตรียมเลี้ยว
  TracJC(Speed, 50);  //เดินข้ามแยก10
  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
  TracJC(SlowSpeed,50);  //เดินข้ามแยก11
  TracJC(SlowSpeed,30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 12
  TracJC(ACCSpeed, 200);  //เดินข้ามแยก13
  TracJC(ACCSpeed, 200);  //เดินข้ามแยก14

}

void Can1Normal() //สนามที่บ้าน
{
  Forward(SlowSpeed, 50);          //เดินจากจุดเริ่มต้น 200
  TracNormalJC(SlowSpeed, 20);      //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalJC(SlowSpeed, 20);      //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalJC(SlowSpeed, 50);      //ข้ามแยก
  TracNormalTime(ACCSpeed,300); //แทรกหน่วงเวลา
}

/*
void Can2Normal()  //สนาม WRG
{
  Forward(Speed, 100);          //เดินจากจุดเริ่มต้น 200
  for (int i=1; i<=5; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 1-5
    TurnLeft();                   //เลี้ยวซ้าย
  }

   for (int i=1; i<=2; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 6-7
    TurnRight();                   //เลี้ยวขวา
  } 
  TracNormalJC(ACCSpeed, 30);      //แทรกเดินตรง 8
  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 9
  TurnRight();                  //เลี้ยว

  for(int i=1;i <=3; i++){
    TracNormalJC(Speed, 30);      //แทรกเดินตรง 10-12
  }
  
  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 13
  TurnLeft();                  //เลี้ยว
  TracNormalJC(ACCSpeed, 50);      //แทรกเดินตรง 14
  TracNormalTime(ACCSpeed, 3000); //แทรกหน่วงเวลา 15
}

*/
