
/**
 * @file
 * Display panel.
 */

class Panel {
  
  protected:
    
    Display * display;

  public:
    
    Panel() {
      this->display = get_display();
      power_display(true);
    }
    
    ~Panel() {
      this->display->home();
    }

    virtual void build() {
      
    }

};
