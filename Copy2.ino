
/**
 * @file
 * Main run file.
 */

#include "Tools.h"

void setup() {
  // Load system.
  core_get().init();
}

void loop() {
  // Run loop.
  core_get().loop();
}
