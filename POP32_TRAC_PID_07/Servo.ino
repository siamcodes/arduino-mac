void ServoGrip() { //กำหนดองศาการคีบ
  servo(3, 70); //1=Servo1, 70=องศาServo
}

void ServoPut() { //กำหนดองศาการปล่อย
  servo(3, 150);
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น
  servo(2, 45);
}

void ServoGripDown() { //กำหนดองศาการยกลง
  servo(2, 145);
}


void Grip() { //คีบหน่วงเวลา
  ao();
  ServoGrip();
  delay(200);
}

void Put() { //ปล่อยหน่วงเวลา
  ao();
  ServoPut();
  delay(200);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUp();
  delay(200);
}


void GripDown() { //ยกแขนลงหน่วงเวลา
  ao();
  ServoGripDown();
  delay(200);
}
