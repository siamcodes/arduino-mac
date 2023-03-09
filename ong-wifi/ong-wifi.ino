#include <analogWrite.h>
#include <WiFi.h>
 
const char* ssid     = "kkkkk";
const char* password = "uginokok16";
 
WiFiServer server(80);
#define LED1 23
#define LED2 22
#define PWM1 21
#define LED3 19
#define LED4 18
#define PWM2 5


void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(PWM2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(PWM1, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
  digitalWrite(PWM2, LOW); 
}

void loop() {
  WiFiClient client = server.available();
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/23H\">here</a> forward. <br>");
            client.print("Click <a href=\"/23L\">here</a> backward.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/22H\">here</a> left. <br>");
            client.print("Click <a href=\"/22L\">here</a> right.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/21H\">here</a> to turn the LED on pin 21 on.<br>");
            client.print("Click <a href=\"/21L\">here</a> to turn the LED on pin 21 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/19H\">here</a> to turn the LED on pin 19 on.<br>");
            client.print("Click <a href=\"/19L\">here</a> to turn the LED on pin 19 off.<br>");
            client.print("<br>");
 
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
  char ch1;
  ch1 = Serial.read();
  if(currentLine.endsWith("GET /23H")){
    analogWrite(PWM1,50);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    analogWrite(PWM2,50);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    Serial.println("Motor Forward");
    delay(1000);
  }if(currentLine.endsWith("GET /23L")){
    analogWrite(PWM1,50);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    analogWrite(PWM2,50);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    Serial.println("Motor Backward");
    delay(1000);
  }if(currentLine.endsWith("GET /22H")){
    analogWrite(PWM1,50);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    analogWrite(PWM2,50);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    Serial.println("Motor Left");
    delay(1000);}
  if(currentLine.endsWith("GET /22L")){
    analogWrite(PWM1,50);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    analogWrite(PWM2,50);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    Serial.println("Motor Right");
    delay(1000);}
    
  else{
    analogWrite(PWM1,0);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    analogWrite(PWM2,0);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
