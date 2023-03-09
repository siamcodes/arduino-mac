#include <ESP8266WiFiMulti.h>
#include <time.h>

ESP8266WiFiMulti wifiMulti;

// Config time
int timezone = 7;

char ntp_server1[20] = "2.th.pool.ntp.org";
char ntp_server2[20] = "time.navy.mi.th";
char ntp_server3[20] = "time.uni.net.th";

int dst = 0;

const int ledPin = D4; // GPIO13

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // kob
  
  wifiMulti.addAP("NK-Sprint", "apex1111");
  wifiMulti.addAP("esp8266", "12345678");
  Serial.begin(115200);

  Serial.println("Connecting WiFi..");
  while (wifiMulti.run() != WL_CONNECTED) {
     Serial.print(".");
     delay(500);
  }
  digitalWrite(ledPin, LOW); 
  Serial.println("WiFi connected ");
  Serial.println(WiFi.localIP());

  configTime(timezone * 3600, dst, ntp_server1, ntp_server2, ntp_server3);
//  configTime(timezone * 3600, dst, ntp_server1, ntp_server2);
  Serial.println("Waiting for time");
  while (!time(nullptr)) {
    Serial.print(">");
    delay(500);
  }

}

String strTimeNow() {
  time_t now = time(nullptr);
  struct tm* tnow = localtime(&now);
  String tmpStr = "";
  tmpStr += String(tnow->tm_hour);
  tmpStr += ":";
  tmpStr += String(tnow->tm_min);
  tmpStr += ":";
  tmpStr += String(tnow->tm_sec);
  return tmpStr;
}

void loop() {
//  Serial.println(strTimeNow());
  String timenow = strTimeNow();

    // do what you want
  Serial.print("\nNow: "); 
  Serial.println(timenow);  

  delay(10000);
}


