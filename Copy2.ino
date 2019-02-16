
/**
 * @file
 * Main run file.
 */

#include "Tools.h"

void setup() {
  // Load system.
  core_get().init();
  Serial.begin(9600);

}

void loop() {
  // Run loop.
  core_get().loop();
}
