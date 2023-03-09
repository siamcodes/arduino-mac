

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>


const char *ssid = "esp8266";
const char *password = "12345678";

const int ledPin = D4; // 13
boolean ledStatus = false;//  
String strLedStatus;
String strButtonLabel;


ESP8266WebServer server(80);


void handleRoot() {
  server.send(200, "text/html", getHtmlPage() );
}

String getHtmlPage() {
  if (ledStatus) {
      strLedStatus = "ขณะนี้ On";
      strButtonLabel = "Turn OFF";
      Serial.println("led on now");
  
    } else {
      strLedStatus = "ขณะนี้ OFF";
      strButtonLabel = "Turn On";

    }

  String css = "<style>.button {background-color: #990033;border: none;border-radius: 4px;color: white;padding: 7px 15px;text-align: center;text-decoration: none;text-decoration: none;}</style>";  
    
  String strHtml = "<!DOCTYPE html><html><head>";
  strHtml += css;
  strHtml += "<meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>";
  strHtml += "<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=1, ";
  strHtml += "minimum-scale=1, width=device-width, height=device-height\">";
  strHtml += "<title>Controller</title>";
  strHtml += "</head><body><h1>Controller/ควบคุม</h1>";
  strHtml += "<h3>LED/Switch: ";
  strHtml += strLedStatus;//****
  strHtml += "</h3>";
  strHtml += "<br>";
  strHtml += "<a href='./toggle' class='button'>";
  strHtml += strButtonLabel;
  strHtml += "</a> ";
  strHtml += "</body></html>";
  return strHtml;
}

void setup() {
  //ledStatus = false;
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
  server.on("/toggle", toggleLed);

	server.begin();
	Serial.println("HTTP server started");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void toggleLed() {
   if (ledStatus) {
      digitalWrite(ledPin, HIGH);
      ledStatus = false;
      Serial.println("now Off");
    } else {
      digitalWrite(ledPin, LOW);
      ledStatus = true;
      Serial.println("now On");
     }
   server.send(200, "text/html", getHtmlPage() );
}


void loop() {
	server.handleClient();
}
