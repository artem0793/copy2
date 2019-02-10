
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

      pinMode(this->id, INPUT);
      this->dispatchEvent(new Event<DigitalInput>(EVENT_ON_CONNECT, this));
      this->setListener();
    }

    ~DigitalInput() {
      this->clearListener();
      this->dispatchEvent(new Event<DigitalInput>(EVENT_ON_DISCONNECT, this));
    }

    void setListener();
    
    void clearListener() {
      clear_timeout(this->index);
    }

    boolean getValue() {
      return this->value;
    }

    void triggerValue() {
      boolean value = digitalRead(this->id) == HIGH ? true : false;

      if (this->value != value) {
        this->value = value;
        this->dispatchEvent(
          new Event<DigitalInput>(EVENT_ON_CHANGE, this)
        );  
      }
    }

};
    
class DigitalInputEventListener: public Timeout {
  
  protected:

    DigitalInput * pin;

    void callback() {
      this->pin->triggerValue();
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
