#include <WiFi.h>
#include <analogWrite.h>
#define IN1 23
#define IN2 22
#define ENA 21
#define IN3 19
#define IN4 18
#define ENB 5
int value = 0;
String header;

const char* ssid = "A12";
const char* password = "42117622";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, LOW);
  delay(10);

  Serial.print("Connecting to ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("WiFi connected");
  Serial.println("IP Address: ");
  Serial.print(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<!DOCTYPE html><html>");
            client.println("<head>");
            client.println("<meta charset=\"utf-8\">");
            client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("</head><body>");
            client.print("<a href='/w'>เดินหน้า</a> <br>");
            client.print("<a href='/s'>ถอยหลัง</a> <br>");
            client.print("<a href='/a'>เลี้ยวซ้าย</a> <br>");
            client.print("<a href='/d'>เลี้ยวขวา</a> <br>");
            client.println("</body></html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        if (currentLine.endsWith("GET /w")) {
          analogWrite(ENA, 50);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          analogWrite(ENB, 50);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          Serial.println("Motor Forward");
          delay(3000);
        } else if (currentLine.endsWith("GET /s")) {
          analogWrite(ENA, 50);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          analogWrite(ENB, 50);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          Serial.println("Motor Backward");
          delay(3000);
        } else if (currentLine.endsWith("GET /a")) {
          analogWrite(ENA, 50);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          analogWrite(ENB, 50);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          Serial.println("Motor LEFT");
          delay(3000);
        } else if (currentLine.endsWith("GET /d")) {
          analogWrite(ENA, 50);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          analogWrite(ENB, 50);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          Serial.println("Motor RIGHT");
          delay(3000);
        } else {
          analogWrite(ENA, 0);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          analogWrite(ENB, 0);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Disconnected");
  }
}
