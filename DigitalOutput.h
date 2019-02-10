
class DigitalOutput: public EventTarget<DigitalOutput> {
  
  protected:
    
    int unsigned id;
    
    boolean value = false;
    
  public:

    DigitalOutput(int unsigned id) {
      this->id = id;
      
      pinMode(this->getId(), OUTPUT);
      
      this->dispatchEvent(new Event<DigitalOutput>(EVENT_ON_CONNECT, this));
    }

    ~DigitalOutput() {
      this->dispatchEvent(new Event<DigitalOutput>(EVENT_ON_DISCONNECT, this));
    }

    void setValue(boolean value) {
      this->value = value;
      
      this->dispatchEvent(new Event<DigitalOutput>(EVENT_ON_CHANGE, this));
      
      digitalWrite(this->getId(), this->value ? HIGH : LOW);
    }
 
    boolean getValue() {
      return this->value;
    }
    
    int unsigned getId() {
      return this->id;
    }

};
