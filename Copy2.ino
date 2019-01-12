
/**
 * @file
 * Main run file.
 */

#include "Tools.h"
//#include "Test.h"




/////////////////////////////////////////////

class Test: public EventCallback<DigitalInput> {
  
  public:
  
   DigitalOutput * led;
   
  protected:
  
    void callback(Event<DigitalInput> * event) {
      if (event->target->getValue()) {
        this->led->setValue(this->led->getValue() ? false : true);  
      }
    }
};

void setup() {
  // Load system.
  // test();
  Serial.begin(9600);

  core_get().init();

  DigitalInput * pin = new DigitalInput(2, 50);

  Test * callback = new Test;

  callback->led = new DigitalOutput(8);

  pin->addEventListener("change", callback);

}

void loop() {
  // Run loop.
  core_get().loop();
}
