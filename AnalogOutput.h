
/**
 * @file
 *
 */

class AnalogOutput: public EventTarget<AnalogOutput> {

  protected:

    int unsigned id;
    
    float value = 0.0;

    float minValue;
    
    float maxValue;

  public:
  
    AnalogOutput(int unsigned id, float min_value = 0, float max_value = 100) {
      this->id = id;
      this->minValue = min_value;
      this->maxValue = max_value;

      pinMode(this->id, OUTPUT);

      this->dispatchEvent(
        new Event<AnalogOutput>(EVENT_ON_CONNECT, this)
      );
    }
    
    ~AnalogOutput() {
      this->dispatchEvent(
        new Event<AnalogOutput>(EVENT_ON_DISCONNECT, this)
      );
    }

    float getValue() {
      return this->value;
    }

    void setValue(float new_value) {
      if (this->value != new_value) {
        analogWrite(this->id, map(new_value, this->minValue, this->maxValue, 0, 255));
        this->value = new_value;
      }
    }

};
