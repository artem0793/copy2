
/**
 * @file
 * Main run file.
 */

#include "Tools.h"
//#include "Test.h"

class DigitalOutput: public EventTarget<DigitalOutput> {
  
  protected:
    
    int unsigned id;
    
    boolean value = false;
    
  public:

    DigitalOutput(int unsigned id) {
      this->id = id;
      pinMode(this->getId(), OUTPUT);
      this->dispatchEvent(new Event<DigitalOutput>("connect", this));
    }

    ~DigitalOutput() {
      this->dispatchEvent(new Event<DigitalOutput>("disconnect", this));
    }

    void setValue(boolean value) {
      this->value = value;
      
      this->dispatchEvent(new Event<DigitalOutput>("change", this));
      
      digitalWrite(this->getId(), this->value ? HIGH : LOW);
    }
 
    boolean getValue() {
      return this->value;
    }
    
    int unsigned getId() {
      return this->id;
    }

};

class DigitalInput: public EventTarget<DigitalInput> {
    
  protected:
    
    int unsigned id;
    
    int unsigned severity;
    
    int index;
    
    boolean value = false;

  public:

    DigitalInput(int unsigned id, int unsigned severity) {
      this->id = id;
      this->severity = severity;
      pinMode(this->getId(), INPUT);
      
      this->dispatchEvent(new Event<DigitalInput>("connect", this));
      this->setListener();
    }

    ~DigitalInput() {
      this->clearListener();
      this->dispatchEvent(new Event<DigitalInput>("disconnect", this));
    }

    void setListener();
    
    void clearListener() {
      clear_timeout(this->index);
    }

    boolean getValue() {
      return this->value;
    }
    
    void setValue(boolean value) {
      this->value = value;
    }

    int unsigned getId() {
      return this->id;
    }
};
    
class DigitalInputEventListener: public Timeout {
  
  protected:

    DigitalInput * pin;

    void callback() {
      boolean value = digitalRead(this->pin->getId()) == HIGH ? true : false;

      if (this->pin->getValue() != value) {
        this->pin->setValue(value);
        this->pin->dispatchEvent(new Event<DigitalInput>("change", this->pin));  
      }
    }
    
  public:
    
    DigitalInputEventListener(DigitalInput * pin) {
      this->pin = pin;
      this->loop = true;
    }
};

void DigitalInput::setListener() {
  this->index = set_timeout(new DigitalInputEventListener(this), this->severity);
}
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
