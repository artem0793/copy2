
/**
 * @file
 *
 */

class AnalogOutput: public EventTarget<AnalogOutput> {

  protected:

    int unsigned id;
    
    int value = 0;

    int minValue;
    
    int maxValue;

  public:
  
    AnalogOutput(int unsigned id, int min_value = 0, int max_value = 100) {
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

    int getValue() {
      return this->value;
    }

    void setValue(int new_value) {
      if (this->value != new_value) {
        this->value = new_value;

        analogWrite(this->id, map(this->value, this->minValue, this->maxValue, 0, 255));
        this->dispatchEvent(
          new Event<AnalogOutput>(EVENT_ON_CHANGE, this)
        );
      }
    }

};
