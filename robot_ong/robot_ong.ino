#include <VNH3SP30.h>

VNH3SP30 Motor1;    // define control object for motor 1
VNH3SP30 Motor2;    // define control object for motor 2

// motor pins (DIAG and CS pins not used in this example)
#define M1_PWM 2    // pwm pin motor
#define M1_INA 3    // control pin INA
#define M1_INB 4    // control pin INB

#define M2_PWM 5    // pwm pin motor
#define M2_INA 6    // control pin INA
#define M2_INB 7    // control pin INB

void setup() {
  // Setting up motor connections. 
  // Please note the INA and INB pins are switched for motor2 as with this vehicle
  // this motor will run the reverse direction when the vehicle moves forward.

  Motor1.begin(M1_PWM, M1_INA, M1_INB, -1, -1);    // Motor 1 object connected through specified pins 
  Motor2.begin(M2_PWM, M2_INB, M2_INA, -1, -1);    // Motor 2 object connected through specified pins 
  Serial.begin(115200);   
}


void setSpeed(int speed) {
  Motor1.setSpeed(speed);
  Motor2.setSpeed(speed);
}

void brake(int brakePower) {
  Motor1.brake(brakePower);
  Motor2.brake(brakePower);
}

void turnLeft(int angle) {
  // turn vehicle by providing different speed settings to the motors.
  // angle can be positive (right turn) or negative (left turn).
  // If the vehicle is already stopped, the vehicle will turn in place.
  int currentSpeed = (Motor1.speed + Motor2.speed) / 2;
  Motor1.setSpeed(currentSpeed + angle);
  Motor2.setSpeed(currentSpeed - angle);
}

void turnRight(int angle) {
  // turn vehicle by providing different speed settings to the motors.
  // angle can be positive (right turn) or negative (left turn).
  // If the vehicle is already stopped, the vehicle will turn in place.
  int currentSpeed = (Motor1.speed + Motor2.speed) / 2;
  Motor1.setSpeed(currentSpeed + angle);
  Motor2.setSpeed(currentSpeed - angle);
}


void loop() {
  Serial.println("half speed forward");
  setSpeed(200); // Vehicle half-speed "forward"
//  turnLeft(200);   
//  brake(100);
//  turnRight(200);   
//  brake(100);
  
}
