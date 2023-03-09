

#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h> // kob

ESP8266WiFiMulti wifiMulti;

const int ledPin = D4; // GPIO13

//String url = "http://httpbin.org/get?key=kobkiat&counter=3";

String url = "http://itp.net/test/testiotinsert.php";

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // 
  Serial.begin(115200);
  delay(10);
	
  wifiMulti.addAP("NK-Sss", "apsss1111");
  wifiMulti.addAP("esp8266", "12345678");
  
  Serial.println("Connecting WiFi..");
  while (wifiMulti.run() != WL_CONNECTED) {
     Serial.print(".");
     delay(500);
  }
  digitalWrite(ledPin, LOW); 
  Serial.println("WiFi connected ");
  Serial.println(WiFi.localIP());
}

void loop() {
  while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      digitalWrite(ledPin, HIGH); 
      delay(500);
  }
  digitalWrite(ledPin, LOW); 

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["temp"] = 25.2;
  root["humid"] = 55.80;
  root["deviceID"] = "sensor1234";
  String jsonStr;
  root.printTo(jsonStr);
  Serial.println(jsonStr);

  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  Serial.println("[HTTP] POST...");

  int httpCode = http.POST(jsonStr);

//http.writeToStream(&Serial);

  if (httpCode > 0) {
    Serial.printf("Response Code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK){
      String payload = http.getString();
      Serial.println(payload);
    } 
  } else {
      Serial.print("[HTTP] failed "); Serial.print(httpCode);
      Serial.println(http.errorToString(httpCode).c_str());
  }
    
  http.end();
  
  delay(30000);
}
