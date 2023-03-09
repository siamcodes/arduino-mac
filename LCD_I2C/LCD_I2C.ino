#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2)

void setup() {
  lcd.begin(0, 2); //เริ่ม LCD โดยใช้ SDA=0, SCL=2
}

void loop() {
  lcd.backlight();
  lcd.display();

  lcd.home();
  lcd.print("Hello World");
  delay(2000);

}
