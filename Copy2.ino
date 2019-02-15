
/**
 * @file
 * Main run file.
 */

#include "Tools.h"

void setup() {
  // Load system.
  core_get().init();
  Serial.begin(9600);
  Display lcd(0x27,20,4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
}

void loop() {
  // Run loop.
  core_get().loop();
}
