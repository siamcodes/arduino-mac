
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin(0,2);  

	//lcd.backlight();
	//lcd.print("Hello, world!");
}

void loop()
{
	  lcd.backlight();
    lcd.display();
    lcd.home();     
    lcd.print("Hello, IoT..");
    delay(2000);

    lcd.setCursor(0, 1);    
    lcd.print("Kobkiat");
    delay(2000);

    lcd.setCursor(8, 1);    
    lcd.print("Saraubon");
    delay(2000);

    lcd.clear();
    lcd.noDisplay();
    lcd.noBacklight();
    delay(2000);
}
