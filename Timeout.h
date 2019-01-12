
/**
 * @file
 * Abstract timeout callback.
 */

class Timeout {

  protected:

    /**
     * Main callback handler.
     */
    virtual void callback() {}

  public:
    
    int index = NO_FREE_INDEX;
    
    boolean lock = false;

    boolean loop = false;

    int unsigned expireTime = 0;

    int unsigned timer = 0;

    /**
     * Main execute callback.
     */
    void execute() {
      this->lock = true;
      this->callback();
      this->lock = false;
    }

};
