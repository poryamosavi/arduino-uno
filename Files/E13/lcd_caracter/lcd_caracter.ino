#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, armsDown);
  lcd.createChar(3, armsUp);
  lcd.createChar(4, frownie);
  

  lcd.setCursor(0, 0);
  lcd.write((byte)0);
  lcd.setCursor(2, 0);
  lcd.write((byte)1);
  lcd.setCursor(4, 0);
  lcd.write((byte)2);
  lcd.setCursor(6, 0);
  lcd.write((byte)3);
    lcd.setCursor(8, 0);
  lcd.write((byte)4);
}

void loop() {
}
