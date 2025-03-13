#include <LiquidCrystal_I2C.h>

// C++ code
//

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

void setup()
{
  lcd1.init();
  lcd1.backlight();
  lcd1.print("hello world");
  lcd1.setCursor(0, 1);
  lcd1.print("i am nikita");

  lcd2.init();
  lcd2.backlight();
  lcd2.print("hello world");

  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
}