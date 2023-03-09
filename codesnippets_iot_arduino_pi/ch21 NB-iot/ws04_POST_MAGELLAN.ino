#include "Magellan.h"
Magellan magel;

char auth[]="f4503fb0-87f4-11e8-8955-________";   //Token Key you can get from magellan platform

String payload;

void setup() {
  Serial.begin(9600);
  magel.begin(auth);           //init Magellan LIB
}

void loop() {

  //magel.getSignal();
  /*
  	Example send random temperature and humidity to Magellan IoT platform
  */
  String Temperature=String(random(0,100));
  String Humidity=String(random(0,100));

  String pressure=String(random(0,50));


  payload="{\"Temperature\":"+Temperature +
              ",\"Humidity\":"+Humidity +
              ",\"Pressure\":"+pressure + "}";       
              
              //please provide payload with json format

  magel.post(payload);                            							   //post payload data to Magellan IoT platform
  
}
