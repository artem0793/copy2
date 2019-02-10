
class DigitalOutput: public EventTarget<DigitalOutput> {
  
  protected:
    
    int unsigned id;
    
    boolean value = false;
    
  public:

    DigitalOutput(int unsigned id) {
      this->id = id;

      pinMode(this->id, OUTPUT);
      this->dispatchEvent(
        new Event<DigitalOutput>(EVENT_ON_CONNECT, this)
      );
    }

    ~DigitalOutput() {
      this->dispatchEvent(
        new Event<DigitalOutput>(EVENT_ON_DISCONNECT, this)
      );
    }

    void setValue(boolean value) {
      if (this->value != value) {
        this->value = value;
        digitalWrite(this->id, this->value ? HIGH : LOW);
        this->dispatchEvent(
          new Event<DigitalOutput>(EVENT_ON_CHANGE, this)
        );
      }
    }
 
    boolean getValue() {
      return this->value;
    }

};
