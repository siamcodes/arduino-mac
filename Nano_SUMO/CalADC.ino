void CalADC(){
 ReadADC();
 
   // 5v
 float volts = analogRead(A1)*0.0048828125;  // value from sensor * (5/1024)
 int distance = 13*pow(volts, -1); // worked out from datasheet graph
 delay(100); // slow down serial port 
 
 if (distance <= 40){
   Serial.println(distance);   // print the distance
 }
}
