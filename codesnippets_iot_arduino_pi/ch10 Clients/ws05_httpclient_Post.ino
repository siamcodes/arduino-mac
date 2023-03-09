

#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti wifiMulti;

const int ledPin = D4; // GPIO13


String url = "http://httpbin.org/post";


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  Serial.begin(115200);
  delay(10);
	
  wifiMulti.addAP("NK-Sssst", "sss111");
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

  String data = "title=halo&deviceID=ksbเทส&temp=25.25&humid=60.20";

  HTTPClient http;
  http.begin(url);
  //  http.begin("httpbin.org", 80, "/get?key=kobkiat&counter=3");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  Serial.println("[HTTP] POST...");
  int httpCode = http.POST(data);

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
