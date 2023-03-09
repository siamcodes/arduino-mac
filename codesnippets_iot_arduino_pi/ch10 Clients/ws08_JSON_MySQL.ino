

//#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h> // kob

ESP8266WiFiMulti wifiMulti;

// dht
#include "DHT.h"
#define DHTPIN D4     // what digital pin we're connected to 2 d4 , 4 d2
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

const int ledPin = D4; // GPIO13
String url = "http://192.168.43.155/testiotinsert.php";

float temp, humid;
const char *deviceID = "sensor1234";

void setup() {
  dht.begin();  // dht
  Serial.println("DHT begins"); // dht
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  Serial.begin(115200);
  delay(10);
	
  wifiMulti.addAP("NK-Sssst", "a111111");
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

void readTempHumid(){
  humid = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(humid) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}

void loop() {
  while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      digitalWrite(ledPin, HIGH); 
      delay(500);
  }
  digitalWrite(ledPin, LOW); 
  readTempHumid(); //delay(200);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["temp"] = temp;
  root["humid"] = humid;
  root["deviceID"] = deviceID;
  String jsonStr;
  root.printTo(jsonStr);
  Serial.println(jsonStr);

  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  Serial.println("[HTTP] JSON...");

  int httpCode = http.POST(jsonStr);

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
  delay(5000);
}
