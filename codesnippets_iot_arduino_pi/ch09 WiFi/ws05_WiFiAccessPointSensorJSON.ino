

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>

// dht
#include "DHT.h"
#define DHTPIN D4     //
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "Kobkiat";
const char *password = "12345678";

int counter = 0;
float temp, humid;

ESP8266WebServer server(80);


void handleRoot() {
  readTempHumid(); delay(200);
//  float humid = dht.readHumidity(); // **01 DHT
//  float temp = dht.readTemperature();
    temp=24.60; humid=60.50;//****
  counter++;

  char sJson[120];
  char str_temp[6];
  char str_humid[6];
    
  dtostrf(temp, 4, 2, str_temp); /* 4 is mininum width, 2 is precision*/
  dtostrf(humid, 4, 2, str_humid);
  sprintf(sJson,"{\"temp\":%s,\"humid\":%s,\"counter\":%d}", str_temp, str_humid, counter);


  server.send(200, "text/plain", sJson );


  Serial.println(sJson);
}

void setup() {
  dht.begin();  // dht
  Serial.println("DHT begins"); // dht
  
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);

	server.begin();
	Serial.println("HTTP server started.");
}

void readTempHumid(){ // not used
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
	server.handleClient();
}
