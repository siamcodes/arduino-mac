

#define BLYNK_PRINT Serial

#include "DHT.h"
#define DHTPIN D4 // or 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2ff7bf72cad842c4a4d796e__________";

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "AndroidAP";
char pass[] = "ssss111";

//int value = 2;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  dht.begin();
}

void loop()
{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("failed to read DHT");
    return;
    }
  
  Blynk.run();
  Blynk.virtualWrite(V1, String(t));
  Blynk.virtualWrite(V2, String(h));
  
  Serial.print(t);
  Serial.println(h);
//  value++;
  delay(1000);
}

