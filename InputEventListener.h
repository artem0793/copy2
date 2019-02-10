
/**
 * @file
 * 
 */

template<typename TargetType>
class InputEventListener: public Timeout {
  
  protected:

    TargetType * pin;

    void callback() {
      this->pin->triggerValue();
    }
    
  public:
    
    InputEventListener(TargetType * pin) {
      this->pin = pin;
      this->loop = true;
    }
};
