#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int var = 0; // ตัวแปรสำหรับทดสอบแสดงผล

int Buzzer = A0;
int RY1 = 8;

void setup() {
  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("ArdinoAll OLED Start Work !!!");
  }

  pinMode(RY1, OUTPUT);
  
}

void loop() {
/*
  digitalWrite(RY1, LOW);
  analogWrite(Buzzer, 255);
  delay(2000);
  
  digitalWrite(RY1,HIGH);
  for(int i=0; i<10; i++){
    analogWrite(Buzzer, 0);
    delay(500);
    analogWrite(Buzzer, 255);
    delay(500);
  }
  delay(2000);
  */
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("OLED"); // แสดงผลข้อความ ALL

  OLED.setTextSize(1);
  OLED.print("welcome to");
  OLED.println(" All");
  OLED.setTextColor(BLACK, WHITE); //กลับสีข้อความกับพื้นหลัง
  OLED.print("www.elec.app");
  OLED.setTextColor(WHITE, BLACK);
  OLED.setCursor(60, 0);
  OLED.setTextSize(2);
  OLED.println(var, DEC);

  OLED.setCursor(0, 40);
  OLED.setTextSize(2);
  OLED.println("Smart Farm"); // แสดงผลข้อความ ALL


  OLED.display(); // สั่งให้จอแสดงผล
  var++;
  delay(1000);
}
