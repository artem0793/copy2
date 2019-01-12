
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
