

#include <Stepper.h>

const int stepsPerRevolution = 96;  


Stepper myStepper(stepsPerRevolution, D1, D2, D3, D4); 

void setup() {

  myStepper.setSpeed(60);

  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
 //i++;
 //Serial.println(i);
}

