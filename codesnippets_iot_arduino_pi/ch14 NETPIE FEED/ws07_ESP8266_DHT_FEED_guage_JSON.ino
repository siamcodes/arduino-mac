
#include <ArduinoJson.h> // **

#include <ESP8266WiFi.h>
#include <MicroGear.h>
#include "DHT.h"                     
const char* ssid     = "NK-Sss";       // ชื่อ ssid
const char* password = "sss1111";        // รหัสผ่าน wifi

#define APPID   "KobkiatProject"
#define KEY     "TF1AL0IhaAt____"         // key
#define SECRET  "ibXicoegWzU_____"
#define ALIAS   "esp8266NetpieFeed"

#define FEEDID   "KobkiatFeed"         
#define FEEDAPI  "Q2uG6esyeJVXWSr______lCYbKZ"    

//----

#define DHTPIN    D4          // GPIO2 ขาที่ต่อเข้ากับขา DATA (บางโมดูลใช้คำว่า OUT) ของ DHT
#define DHTTYPE   DHT22       // ***** e.g. DHT11, DHT21, DHT22
DHT dht(DHTPIN, DHTTYPE);

float humid = 0;     // ค่าความชื้น
float temp  = 0;     // ค่าอุณหภูมิ

long lastDHTRead = 0;
long lastTimeWriteFeed = 0;

WiFiClient client;
MicroGear microgear(client);

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    microgear.setAlias(ALIAS);
}

void setup() {
    Serial.begin(115200);
    dht.begin(); // initialize โมดูล DHT

    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.print(".");
        }
    }
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    microgear.on(CONNECTED, onConnected);
    microgear.init(KEY,SECRET,ALIAS);   // กำหนดค่าตันแปรเริ่มต้นให้กับ microgear
    microgear.connect(APPID);           // ฟังก์ชั่นสำหรับเชื่อมต่อ NETPIE
}

void loop() {
    if (microgear.connected()) {
        microgear.loop();

        if(millis() - lastDHTRead > 2000){
          humid = dht.readHumidity() -4;     // อ่านค่าความชื้น
          temp  = dht.readTemperature()-4;  // อ่านค่าอุณหภูมิ
          lastDHTRead = millis();
          
          Serial.print("Humid: "); Serial.print(humid); Serial.print(" %, ");
          Serial.print("Temp: "); Serial.print(temp); Serial.println(" C ");
    
          // ตรวจสอบค่า humid และ temp เป็นตัวเลขหรือไม่
          if (isnan(humid) || isnan(temp)) {
            Serial.println("Failed to read from DHT sensor!");
          }
          else{
            // เตรียมสตริงในรูปแบบ "{humid},{temp}"
           // String datastring = (String)humid+","+(String)temp;
           // Serial.print("Sending --> ");
           // Serial.println(datastring);
//            microgear.publish(DHTDATATOPIC,datastring);  
            Serial.print("publish temp-> ");
            Serial.print(temp); Serial.print(" humid->");
            Serial.println(humid);
            microgear.publish("/outdoor/temp", (String)temp);
            microgear.publish("/outdoor/humid", (String)humid);
          }
        }
        
        if(millis()-lastTimeWriteFeed > 15000){
          lastTimeWriteFeed = millis();
          if(humid!=0 && temp!=0){

            DynamicJsonBuffer jsonBuffer;
            JsonObject& root = jsonBuffer.createObject();
            root["temp"] = temp;
            root["humid"] = humid;

            String jsonData;
            root.printTo(jsonData);
  
            Serial.print("Write Feed --> ");
            Serial.println(jsonData);
//            microgear.writeFeed(FEEDID,data); //**
//            microgear.writeFeed(FEEDID,data,FEEDAPI); 
            microgear.writeFeed(FEEDID,jsonData,FEEDAPI); 
          }
        }
    }
    else {
        Serial.println("connection lost, reconnect...");
        microgear.connect(APPID); 
    }
}
