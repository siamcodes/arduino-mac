

#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h> 


ESP8266WiFiMulti wifiMulti;

const int ledPin = D4; // GPIO13



String url = "http://api.openweathermap.org/data/2.5/weather?q=bangkok&appid=92eb9b443bc_____";

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  Serial.begin(115200);
  delay(10);
	
  wifiMulti.addAP("NK-Ssss", "assss111");
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

  HTTPClient http;
  http.begin(url);

  Serial.println("[HTTP] GET...");
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("Response Code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK){
      String payload = http.getString();
      Serial.println(payload);

    } // http ok 
  } else {
      Serial.print("[HTTP] GET failed "); Serial.print(httpCode);
      Serial.println(http.errorToString(httpCode).c_str());
  }
    
  http.end();
  delay(60000);
}
