
/**
 * Test.
 */

#include "OSystemAPI.h"
#include "Tests.h"

void setup() {
  Serial.begin(9600);
  // Load system.
  system_get();
  run_test();
}

void loop() {
  // Run loop.
  _system_loop();
}
