
/**
 * @file
 * 
 */

const int unsigned PIN_TYPE_DIGITAL = 0;

const int unsigned PIN_TYPE_ANALOG = 1;

class Pin: public EventTarget<Pin> {
  protected:
    int unsigned pid;

  public:
    Pin(int unsigned pid, int unsigned type) {
      this->pid = pid;
      this->type = type;
    }
};
