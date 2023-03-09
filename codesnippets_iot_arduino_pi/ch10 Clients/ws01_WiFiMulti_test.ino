

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifiMulti;

const int ledPin = D4; // GPIO13

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // 
    Serial.begin(115200);
    delay(10);
	
    wifiMulti.addAP("NK-sss", "1111222");
    wifiMulti.addAP("esp8266", "12345678");

	  Serial.println("Connecting Wifi...");
    while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    digitalWrite(ledPin, LOW); // kob
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

}

void loop() {
     while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      digitalWrite(ledPin, HIGH); // 
      delay(500);
    }

     Serial.print("WiFi connected ");
     Serial.println(WiFi.localIP());
     digitalWrite(ledPin, LOW); // 


    delay(1500);

}
