
#include <ESP8266WiFi.h>
#include <MicroGear.h>


const char* ssid     = "NK-Sssss";       // ชื่อ ssid
const char* password = "sss1111";        // รหัสผ่าน wifi

#define APPID   "KobkiatProject"
#define KEY     "TF1AL0IhaA____"         // key
#define SECRET  "ibXicoegWzUL6Q____"
#define ALIAS   "esp8266LED"

//----

const int ledpin = D4;          // GPIO2 ขาที่ต่อเข้ากับขา DATA (บางโมดูลใช้คำว่า OUT) ของ DHT

float humid = 0;     // ค่าความชื้น
float temp  = 0;     // ค่าอุณหภูมิ
long lastDHTRead = 0;

int ledstatus = false;

WiFiClient client;
MicroGear microgear(client);

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
    Serial.print("Incoming message --> ");
    msg[msglen] = '\0';
    Serial.println((char *)msg);

    if (*(char *)msg == '0') {
        digitalWrite(ledpin, HIGH);
        Serial.println("publish /LEDstate 0");
        microgear.publish("/LEDstate", 0);
      }
      else if (*(char *)msg == '1') {
        digitalWrite(ledpin, LOW);
        microgear.publish("/LEDstate", 1);
        Serial.println("publish /LEDstate 1");
     }
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    microgear.setAlias(ALIAS);
    //microgear.subscribe("/LEDcommand");
    microgear.subscribe("/kobkiat/switch"); // from other chapter
}

void setup() {
    Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH); // off led

    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.print(".");
        }
    }
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    microgear.on(MESSAGE,onMsghandler);
    microgear.on(CONNECTED, onConnected);
    microgear.init(KEY,SECRET,ALIAS);   // กำหนดค่าตันแปรเริ่มต้นให้กับ microgear
    microgear.connect(APPID);           // ฟังก์ชั่นสำหรับเชื่อมต่อ NETPIE
}

void loop() {
    if (microgear.connected()) {
        microgear.loop();
      
        
    } else {
        Serial.println("connection lost, reconnect...");
        microgear.connect(APPID); 
    }
}

