
/**
 * @file
 *
 */

class AnalogInput: public EventTarget<AnalogInput> {
    
  protected:
    
    int unsigned id;
    
    int unsigned severity;
    
    int index;
    
    float value = 0.0;
    
    float minValue;
    
    float maxValue;

  public:

    AnalogInput(int unsigned id, int unsigned severity, float min_value = 0, float max_value = 100) {
      this->id = id;
      this->severity = severity;
      this->minValue = min_value;
      this->maxValue = max_value;
      this->dispatchEvent(
        new Event<AnalogInput>(EVENT_ON_CONNECT, this)
      );
      this->setListener();
    }

    ~AnalogInput() {
      this->clearListener();
      this->dispatchEvent(
        new Event<AnalogInput>(EVENT_ON_DISCONNECT, this)
      );
    }

    void setListener();
    
    void clearListener() {
      clear_timeout(this->index);
    }

    float getValue() {
      return this->value;
    }
    
    void setValue(float value) {
      this->value = value;
    }

    int unsigned getId() {
      return this->id;
    }

    void triggerValue() {
      float new_value = map(
        analogRead(this->id),
        0, 1023,
        this->minValue, this->maxValue
      );
      
      if (this->value != new_value) {
        this->value = new_value;
        this->dispatchEvent(
          new Event<AnalogInput>(EVENT_ON_CHANGE, this)
        );  
      }
    }
};
    
class AnalogInputEventListener: public Timeout {

  protected:

    AnalogInput * pin;

    void callback() {
      this->pin->triggerValue();
    }
    
  public:
    
    AnalogInputEventListener(AnalogInput * pin) {
      this->pin = pin;
      this->loop = true;
    }
};

void AnalogInput::setListener() {
  this->index = set_timeout(
    new AnalogInputEventListener(this), 
    this->severity
  );
}
