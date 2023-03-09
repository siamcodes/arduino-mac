#include <IFTTTMaker.h>


#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "DHT.h"

#define DHTPIN 2  // D4
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//------- Replace the following! ------
char ssid[] = "NK-Spsss";    
char password[] = "sss111";  
#define KEY "cFZsBy9yOfGhLn________"  // Get it from this page https://ifttt.com/services/maker/settings
#define EVENT_NAME "temp" // Name of your event name, set when you are creating the applet


WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

void setup() {

  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  dht.begin();
}

void loop() {
  delay(4000);

  float humid = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humid) || isnan(temp) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
    //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
  if(ifttt.triggerEvent(EVENT_NAME, "id508", (String)temp, (String)humid )){
    Serial.println("Successfully sent");
  } else
  {
    Serial.println("Failed!");
  }
  
}
