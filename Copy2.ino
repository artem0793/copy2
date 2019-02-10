
/**
 * @file
 * Main run file.
 */

#include "Tools.h"
//#include "Test.h"

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

class AnalogTest: public EventCallback<AnalogInput> {
 
  protected:

    void callback(Event<AnalogInput> * event) {
      Serial.println(event->target->getValue());
    }
};

void setup() {
  // Load system.
  // test();
  Serial.begin(9600);

  core_get().init();

//  DigitalInput * pin = new DigitalInput(2, 50);

//  Test * callback = new Test;

//  callback->led = new DigitalOutput(8);

//  pin->addEventListener("change", callback);


//  AnalogInput * analog_pin = new AnalogInput(0, 100);
//
//  AnalogTest * analog_callback = new AnalogTest;
//
//  analog_pin->addEventListener("change", analog_callback);

//    AnalogOutput * analog_pin = new AnalogOutput(9);
//    for (int i = 0; i <= 100; i++) {
//      delay(500);
//      analog_pin->setValue(i);
//      if (i == 100) {
//        i = 0;
//      }
//      Serial.println(i);
//    }

}

void loop() {
  // Run loop.
  core_get().loop();
}
