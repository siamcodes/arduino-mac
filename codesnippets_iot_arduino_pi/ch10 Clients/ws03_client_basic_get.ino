

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifiMulti;

const int ledPin = D4; // GPIO13
const char* host = "httpbin.org"; //"google.com";
//const char* host = "google.com";
const char* param1   = "kobkiat";
int counter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  Serial.begin(115200);
  delay(10);
	
    wifiMulti.addAP("NK-Sss, "ss111");
    wifiMulti.addAP("esp8266", "12345678");
   wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");

	Serial.println("Connecting Wifi...");
  while (wifiMulti.run() != WL_CONNECTED) {
     Serial.print(".");
     delay(500);
  }
  digitalWrite(ledPin, LOW); // kob
  Serial.println("WiFi connected ");
  Serial.println(WiFi.localIP());
}

void loop() {
  while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      digitalWrite(ledPin, HIGH); 
      delay(500);
  }

  //Serial.print("WiFi connected ");
  //Serial.println(WiFi.localIP());
  digitalWrite(ledPin, LOW); // kob

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  counter++;
  
  String url = "/get";
  url += "?key=";
  url += param1;
  url += "&counter=";
  url += counter;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println(" closing connection");

  delay(60000);
}
