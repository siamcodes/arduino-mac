

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                

void setup() 
{ 
  myservo.attach(D1);  
  myservo.write(90);
  delay(1000);
} 
 
void loop() 
{ 
  delay(1500);
  
  myservo.write(0);
  delay(1000);

  myservo.write(45);
  delay(1000);
 
  myservo.write(90);
  delay(1000);

  myservo.write(180);
  delay(1000);

  myservo.write(90);
  delay(1000);
} 

