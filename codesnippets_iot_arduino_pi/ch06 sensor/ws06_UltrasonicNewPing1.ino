

#include <NewPing.h>

#define TRIGGER_PIN  D5  
#define ECHO_PIN     D6  
#define MAX_DISTANCE 500 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); 
}

void loop() {
  delay(50);             
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); 
  Serial.println("cm");
}
