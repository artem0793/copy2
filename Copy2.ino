
/**
 * @file
 * Main run file.
 */

#include "Tools.h"

class MyButton: public Button {
  public:
    
    MyButton(int pin): Button(pin) {
      
    }
    
    void onClick() {
      Serial.println("Jr");
    }
};

void setup() {
  // Load system.
  core_get().init();
  Serial.begin(9600);
  new MyButton(12);
}

void loop() {
  // Run loop.
  core_get().loop();
}
