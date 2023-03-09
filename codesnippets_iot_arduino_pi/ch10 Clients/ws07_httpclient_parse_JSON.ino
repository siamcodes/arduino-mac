

//#include <ESP8266WiFi.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h> 
#include <ArduinoJson.h> // **

void setup() {
  Serial.begin(115200);
  delay(10);
}

void loop() {

  //   char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  String json = "{\"deviceID\":\"sensor1234\",\"temp\":\"25.4\",\"humid\":\"60.50\"}";
  Serial.println("\nJSON String");
  Serial.println(json);
  


  // Parsing
  Serial.println("\nParsing..");
  
  const size_t bufferSize = 200;
  DynamicJsonBuffer jsonBuffer(bufferSize);
  JsonObject& root = jsonBuffer.parseObject(json);
  // Parameters
  if (root.success()) {
     const char* temp = root["temp"];
     const char* humid = root["humid"];
     const char* deviceID = root["deviceID"];

     Serial.printf("temp -> %s \n", temp);
     Serial.printf("humidity -> %s \n", humid);
     Serial.printf("device -> %s \n", deviceID);

  }
       
  delay(20000);
}
