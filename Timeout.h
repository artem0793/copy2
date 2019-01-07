
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

    boolean lock = false;

    int unsigned expireTime = 0;

    /**
     * Main execute callback.
     */
    void execute() {
      this->lock = true;
      this->callback();
    }

};
