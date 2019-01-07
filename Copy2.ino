
/**
 * @file
 * Main run file.
 */

#include "Tools.h"
#include "Test.h"

void setup() {
  // Load system.
  test();
  core_get().init();  
}

void loop() {
  // Run loop.
  core_get().loop();
}
