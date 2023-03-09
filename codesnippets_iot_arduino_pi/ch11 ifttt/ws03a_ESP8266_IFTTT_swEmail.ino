
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti wifiMulti;

const int swPin = D2;  // GPIO4; 
const int ledPin = D4; // GPIO13

String url = "http://maker.ifttt.com/trigger/sw_on/with/key/cFZsBy9yOfGhLnxxxxx";
//String url = "https:ifttt.com";

void setup() {
  pinMode(swPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  Serial.begin(115200);
  delay(10);
  
  wifiMulti.addAP("NK-Ssssst", "ss1111");
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
  while (wifiMulti.run() != WL_CONNECTED) {   // ตรวจสอบสถานะเชื่อมต่อ
      Serial.print(".");
      digitalWrite(ledPin, HIGH); 
      delay(500);
  }
  digitalWrite(ledPin, LOW); 

  int swState = digitalRead(swPin); //swState = LOW;

  if (swState == LOW) {
    digitalWrite(ledPin, HIGH); 
    Serial.println("Sw is pressed, send request to IFTTT");
    httpRequest();
  } 
   else 
  {
    digitalWrite(ledPin, LOW);  
  }
  delay(100);     // หน่วงเวลา
}

void httpRequest() {
  HTTPClient http;   
  http.begin(url);              // เริ่มต้น

  Serial.println("[HTTP] GET...");
  int httpCode = http.GET();    // ส่ง Request GET

  
  if (httpCode > 0) {
    Serial.printf("Response Code: %d\n", httpCode);

   
    if (httpCode == HTTP_CODE_OK){
      String payload = http.getString();    // อ่านข้อมูลที่ Response กลับมา
      Serial.println(payload);
    } 
  } else {

      Serial.print("[HTTP] GET failed "); Serial.print(httpCode);
      Serial.println(http.errorToString(httpCode).c_str());
  }
  http.end();       // สิ้นสุด
}

