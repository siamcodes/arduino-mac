#include <DHT.h>
DHT dht;

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int Buzzer = A0;  //กำหนด Buzzer ที่ขา A0
int RY1 = 8;       //กำหนดค่า Relay ที่ขา 8
int Soil = 9;  //กำหนดค่าเซนเซอร์ที่ขา 9
int val = 0;
//int var = 0; // ตัวแปรสำหรับทดสอบแสดงผล
float humidity, temperature;

void setup() {
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  /* if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
     Serial.println("SSD1306 allocation failed");
    } else {
     Serial.println("ArdinoAll OLED Start Work !!!");
    }
  */
  pinMode(RY1, OUTPUT);
  pinMode(Soil, OUTPUT); //เ
  dht.setup(2); // data pin 2
}

void loop() {
  ReadSensor();
  //ShowSensor();

  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("Humi:"); // แสดงผลข้อความ
  OLED.setCursor(60, 0);
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(humidity);
  OLED.setCursor(0, 20);
  OLED.setTextSize(2);
  OLED.print("Temp:");
  OLED.setCursor(60, 20);
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(temperature);
  OLED.setCursor(0, 40);
  OLED.setTextSize(2);
  OLED.print("Soil:");
  OLED.setCursor(60, 40);
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(val);
  OLED.display(); // สั่งให้จอแสดงผล

  if (val < 500) {
    digitalWrite(RY1, HIGH);
    analogWrite(Buzzer, 255);
    delay(10000);
    digitalWrite(RY1, LOW);
    analogWrite(Buzzer, 50);
    delay(10);
  }
  else {
    digitalWrite(RY1, LOW);
    analogWrite(Buzzer, 255);
  }

  //var++;
  //delay(1000);
}
