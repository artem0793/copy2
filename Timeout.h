
/**
 * @file
 */

class Timeout {

  protected:
    /**
     * Main callback handler.
     */
    virtual void callback();
    
  public:
    /**
     * Time to expire.
     */
    int unsigned expireTime;

    /**
     * Execute callback.
     */
    void execute() {
      this->callback();
    }

};
