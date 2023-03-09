
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
  counter++;
  String strHtml = "<!DOCTYPE html><html>";
  strHtml += "<head><meta http-equiv='refresh' content='3'/>";
  strHtml += "<meta name=\"viewport\" content=\"user-scalable=no, initial-scale=1, maximum-scale=1, ";
  strHtml += "minimum-scale=1, width=device-width, height=device-height\">";
  strHtml += "<title>Web Server</title>";
//  strHtml += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
  strHtml += "</head><body><h1>Web Server</h1>";
  strHtml += "<h3>Sensors</h3>";
  strHtml += "<ul><li>Temperature (C) : ";
  strHtml += (temp-2);//****
  strHtml += "</li>";
  strHtml += "<li>Humid (%) : ";
  strHtml += humid;
  strHtml += "</li>";
  strHtml += "<li>Counter : ";
  strHtml += counter;
  strHtml += "</li></ul>";
  
  strHtml += "</body></html>";
	server.send(200, "text/html", strHtml);
  
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

void readTempHumid(){
  humid = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.readTemperature();

  if (isnan(humid) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
  
void loop() {
	server.handleClient();
}
