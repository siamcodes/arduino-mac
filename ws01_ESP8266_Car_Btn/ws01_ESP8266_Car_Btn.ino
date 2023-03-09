//#include <ESP8266WiFi.h>
#include <WiFi.h>

#define MOTOR_A_PWM 23  //D1
#define MOTOR_A_DIR 22  //D2
#define MOTOR_B_PWM 21  //D3
#define MOTOR_B_DIR 19  //D4

const char* ssid = "A12";
const char* password = "42117622";

int forwardSpeed = 950;
int turnSpeed = 600;
int forwardDir = LOW;
int backwardDir = HIGH;



WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  IPAddress ip(192, 168, 43, 20); // this 3 lines for a fix IP-address
  IPAddress gateway(192, 168, 43, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet); //
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

  pinMode(MOTOR_A_PWM, OUTPUT);   // M A
  pinMode(MOTOR_A_DIR, OUTPUT);   // M A
  pinMode(MOTOR_B_PWM, OUTPUT);   // B 
  pinMode(MOTOR_B_DIR, OUTPUT);   // B DirB

  stopCar();
}


void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
   // stopCar();
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("\nnew client");
  while(!client.available()){
    delay(20);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.print("REQ from client <- ");Serial.println(req);
  client.flush();
  
  // Match the request
  int motorAForward = 1;
  int motorBForward = 1;
  if (req.indexOf("/engines/") != -1) {
    String parameters = req.substring(13);
    //Serial.println(parameters);
    int separatorPos = parameters.indexOf(",");
    int httpPos = parameters.indexOf(" HTTP");
//    String leftText = parameters.substring(0,separatorPos);
    String dirChar = parameters.substring(separatorPos + 1, httpPos);

    Serial.println(" charDir " + dirChar );

    if (dirChar.equals("f")){
        outputMotor(forwardSpeed, forwardSpeed, forwardDir);
      } else if (dirChar.equals("l")){
        outputMotor(turnSpeed, forwardSpeed, forwardDir);
      } else if (dirChar.equals("r")){
        outputMotor(forwardSpeed, turnSpeed, forwardDir) ;     
      } else if (dirChar.equals("b")){
        outputMotor(1023-turnSpeed, 1023-turnSpeed, backwardDir) ;         
      } else if (dirChar.equals("s")){
        stopCar();
      }
    
  } else if (req.indexOf("/index.html") != - 1 || req.indexOf("/") != - 1) {
     client.print(getHtmlPage());
     return;
  } 
 
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n Car ";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
  delay(100);
}

void outputMotor(int speed_A, int speed_B, int mDir) {
    analogWrite(MOTOR_A_PWM, speed_A); //5
    digitalWrite(MOTOR_A_DIR, mDir); // 0
   
    analogWrite(MOTOR_B_PWM, speed_B); // 4
    digitalWrite(MOTOR_B_DIR, mDir); // 0
    Serial.printf("Motor A %d dir %d , B %d Dir %d \n", speed_A, mDir, speed_B, mDir);
}

void stopCar() {
    analogWrite(MOTOR_A_PWM, 0); //5
    digitalWrite(MOTOR_A_DIR, 0); // 0
   
    analogWrite(MOTOR_B_PWM, 0); // 4
    digitalWrite(MOTOR_B_DIR, 0); // 0
}

/*
void stopCar1() {  // mpt full stop
    digitalWrite(MOTOR_A_PWM, 1);
    digitalWrite(MOTOR_B_PWM, 1);
    digitalWrite(MOTOR_A_DIR, 1);
    digitalWrite(MOTOR_B_DIR, 1);
} */


String getHtmlPage() {
  String js = createJS();
  String css = "<style>.button {background-color: #990033;border: none;border-radius: 4px;color: white;padding: 7px 15px;font-size: 20px;text-align: center;text-decoration: none;text-decoration: none;}</style>";  
  String strHtml = "<!DOCTYPE html><html><head>";
  strHtml += js;
  strHtml += css;
  strHtml += "<meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>";
  strHtml += "<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=2, ";
  strHtml += "minimum-scale=1, width=device-width, height=device-height\">";
  strHtml += "<title>Controller</title>";
  strHtml += "</head><body onload='init()'> <center><h1>IoT Car</h1>";
  strHtml += "<br>";
  strHtml += "<input type='button' class='button' id='btnF' value='Forward'><br><br>";
  strHtml += "<input type='button' class='button' id='btnL' value='<< Left '>&nbsp; ";
//  strHtml += "<input type='button' class='button' id='btnS' value='Stop'> ";     
  strHtml += "&nbsp; <input type='button' class='button' id='btnR' value='Right >> '><br><br>";      
  strHtml += "<input type='button' class='button' id='btnB' value='Backward'><br><br>";  
  strHtml += "<div id='status'/>..</div>";
//  strHtml += "<div id=\"vector\"/>...</div>";
  strHtml += "</center></body></html>";
  return strHtml;
}


String createJS () {
  String js = "<script type='text/javascript'> ";
  js += "  function init() { ";
  js += "   document.getElementById('btnF').addEventListener('touchstart', moveF, false); ";  
  js += "   document.getElementById('btnF').addEventListener('touchend', stopCar, false); ";
  js += "   document.getElementById('btnL').addEventListener('touchstart', moveL, false); ";  
  js += "   document.getElementById('btnL').addEventListener('touchend', stopCar, false); "; 
  js += "   document.getElementById('btnR').addEventListener('touchstart', moveR, false); ";  
  js += "   document.getElementById('btnR').addEventListener('touchend', stopCar, false); ";
  js += "   document.getElementById('btnB').addEventListener('touchstart', moveB, false); ";  
  js += "   document.getElementById('btnB').addEventListener('touchend', stopCar, false); ";
//  js += "   document.getElementById('btnS').addEventListener('touchstart', stopCar, false); ";  
//  js += "   document.getElementById('btnS').addEventListener('touchend', stopCar, false); ";        
  js += "  } ";
  
  js += " function move(dir) {";
  js += "     document.getElementById('status').innerHTML = dir; ";
  js += "     var request = new XMLHttpRequest();";
  js += "     request.open('GET', '/engines/' + dir , true);";
  js += "     request.send(null);";
  js += "} ";
  
  js += " function moveF() {";
  js += "    move('f'); ";
  js += "} ";  
  js += " function moveL() {";
  js += "    move('l'); ";
  js += "} ";    
  js += " function moveR() {";
  js += "    move('r'); ";
  js += "} ";  
  js += " function moveB() {";
  js += "    move('b'); ";
  js += "} ";   
  
  js += " function stopCar() {";
  js += "     document.getElementById('status').innerHTML = 's'; ";
  js += "     var request = new XMLHttpRequest();";
  js += "     request.open('GET', '/engines/s' , true);";
  js += "     request.send(null);";
  js += "} "; 
  js += "</script>";
  //  Serial.println(js);
  return(js);
}
