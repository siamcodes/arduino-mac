

#include <ESP8266WiFi.h>
#include <MicroGear.h>

const char* ssid     = "ssid";
const char* password = "pwd";

#define APPID   "KobkiatProject"
#define KEY     "TF1AL0Ixxxxxxxx" // dev
#define SECRET  "ibXicoegWzUL6xxxxxxxxxx"
#define ALIAS "esp8266Switch1"    //

char* outTopic = "switchByHtml";
char* subscribeTopic = "/kobkiat/switch"; 

WiFiClient client;

int timer = 0;
//char state = 0;

int ledPin = 2; // D4

MicroGear microgear(client);

/* If a new message arrives, do this */
void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
    Serial.print("Incoming message --> "); Serial.print(topic); Serial.print(" : ");
    msg[msglen] = '\0';
    Serial.println((char *)msg);

    //if (*(char *)msg == '1') { // ok from netpie
      if ((char)msg[0]=='1') { // 1 sent from sw html (to turn On)
        microgear.chat(outTopic,"1"); Serial.println(outTopic); //**
        digitalWrite(ledPin, LOW); // on
        digitalWrite(BUILTIN_LED, LOW);
      } else {
        microgear.chat(outTopic,"0"); //Serial.println(outTopic); //**
        digitalWrite(ledPin, HIGH);
        digitalWrite(BUILTIN_LED, HIGH);
      }
}

void onFoundgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Found new member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();  
}

void onLostgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Lost member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();
}

/* When a microgear is connected, do this */
void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    /* Set the alias of this microgear ALIAS */
    microgear.setAlias(ALIAS);
    microgear.subscribe(subscribeTopic);
}


void setup() {
    /* Add Event listeners */

    /* Call onMsghandler() when new message arraives */
    microgear.on(MESSAGE,onMsghandler);

    /* Call onFoundgear() when new gear appear */
    microgear.on(PRESENT,onFoundgear);

    /* Call onLostgear() when some gear goes offline */
    microgear.on(ABSENT,onLostgear);

    /* Call onConnected() when NETPIE connection is established */
    microgear.on(CONNECTED,onConnected);

    Serial.begin(115200);
    Serial.println("Starting...");

    pinMode(ledPin, OUTPUT); //**
    digitalWrite(ledPin, HIGH); // init off led
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);

    /* Initial WIFI, this is just a basic method to configure WIFI on ESP8266.                       */
    /* You may want to use other method that is more complicated, but provide better user experience */
    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
    }

    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    /* Initial with KEY, SECRET and also set the ALIAS here */
    microgear.init(KEY,SECRET,ALIAS);

    /* connect to NETPIE to a specific APPID */
    microgear.connect(APPID);
}

void loop() {
    /* To check if the microgear is still connected */
    if (microgear.connected()) {
        Serial.println("connected");

        /* Call this method regularly otherwise the connection may be lost */
        microgear.loop();

        timer = 0;
    } else {
        Serial.println("connection lost, reconnect...");
        if (timer >= 5000) {
            microgear.connect(APPID);
            timer = 0;
        }
        else timer += 100;
    }
    delay(300);
}
