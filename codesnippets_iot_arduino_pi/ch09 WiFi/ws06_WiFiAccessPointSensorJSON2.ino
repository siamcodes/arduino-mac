#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
 
#include <ESP8266WebServer.h>

// dht
#include "DHT.h"
#define DHTPIN D4     // 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);


/* Set these to your desired credentials. */
const char *ssid = "Kobkiat";
const char *password = "12345678";

int counter = 0;
float temp, humid;

ESP8266WebServer server(80);


void handleRoot() {
  //readTempHumid(); delay(200);
  float humid = dht.readHumidity(); // **01 DHT
  float temp = dht.readTemperature();
    temp=23.4; humid=60.50;
  counter++;

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["temp"] = temp;
  root["humid"] = humid;
  root["counter"] = counter;

  String jsonStr;
  root.printTo(jsonStr);
  server.send(200, "application/json", jsonStr );

  Serial.println(jsonStr);
}

void setup() {
  dht.begin();  // dht
  Serial.println("DHT begins"); // dht
  
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
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
