

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "esp8266";
const char *password = "12345678";

const int ledPin = D4; // 13

ESP8266WebServer server(80);


void handleRoot() {
  server.send(200, "text/html", getHtmlPage() );
}

String getHtmlPage() {
  String strHtml = "<!DOCTYPE html><html><head>";
 strHtml += "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">";
  strHtml += "<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=1, ";
  strHtml += "minimum-scale=1, width=device-width, height=device-height\">";
  strHtml += "<title>Controller</title>";
  strHtml += "</head><body><h1>Controller/ควบคุม</h1>";
  strHtml += "<h3>LED/Switch: ";
  strHtml += "</h3>";
  strHtml += "<br>";
  strHtml += "<a href='./on'>ON</a> <br><br> <a href='./off'>OFF</a>";
  strHtml += "</body></html>";
  return strHtml;
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
	server.on("/", handleRoot);
  server.on("/on", turnOn);
  server.on("/off", turnOff);
	server.begin();
	Serial.println("HTTP server started");
}

void turnOn() {
   digitalWrite(ledPin, LOW);
   Serial.println("now On");
   server.send(200, "text/html", getHtmlPage() );
}

void turnOff() {
   digitalWrite(ledPin, HIGH);
   Serial.println("now Off");
   server.send(200, "text/html", getHtmlPage() );
}


void loop() {
	server.handleClient();
}
