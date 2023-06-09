#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int potPin = A0;
const int fanPin = 9;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Sicaklik: ");
  pinMode(fanPin, OUTPUT);
}

void loop() {
  int sicaklik = map(analogRead(potPin), 0, 1023, 0, 100);
  
  lcd.setCursor(10, 0);
  lcd.print(sicaklik);
  lcd.print(" C");
  
  if (sicaklik > 30) {
    analogWrite(fanPin, 150);
  } else {
    analogWrite(fanPin, 255);
  }
  
  delay(500);
}
