
/**
 * @file
 * Кнопка.
 */

/**
 * Пример подключения:
 * Плюс пустить в кнопку и через сопротивление в минус, 
 * а замыкающий конец кнопки в пин.
 *
 * Пример кода:
 * class MyButton: public Button {
 *   public:
 *     MyButton(int pin): Button(pin) {
 *       Serial.begin(9600);
 *     }
 *   
 *     void onClick() {
 *       Serial.println("click: Ok");
 *     }
 *  };
 * 
 *  new MyButton(12);
 */
class Button: public EventTarget<Button> {
  
  protected:
    DigitalInput * pin;
    
  public:

    Button(int unsigned pin_id);

    ~Button() {
      delete this->pin;
    }
    
    void triggerStatus(boolean status) {
      this->dispatchEvent(
        new Event<Button>(status ? EVENT_ON_PUSH_DOWN : EVENT_ON_PUSH_UP, this)
      );

      if (status) {
        this->onDown();
      }
      else {
        this->onClick();
        this->dispatchEvent(
          new Event<Button>(EVENT_ON_CLICK, this)
        );
        this->onUp();
      }
    }

    virtual void onDown() {}
    virtual void onClick() {}
    virtual void onUp() {}
};

class ButtonEventCallback: public EventCallback<DigitalInput> {
  
  protected:
    
    Button * button;
  
  public:
    
    ButtonEventCallback( Button * button) {
       this->button = button;
    }
    
    /**
     * Handler callback.
     */
    void callback(Event<DigitalInput> * event);

};

Button::Button(int unsigned pin_id) {
  this->pin = new DigitalInput(pin_id, 50);
  this->pin->addEventListener(
    EVENT_ON_CHANGE,
    new ButtonEventCallback(this)
  );
}

void ButtonEventCallback::callback(Event<DigitalInput> * event) {
  this->button->triggerStatus(event->target->getValue());
};
