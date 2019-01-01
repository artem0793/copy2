
/**
 * @file
 */

class TimeoutManager {

  protected:
    /**
     * Queue.
     */
    Timeout * queue[MAX_SIZE_OF_TIMEOUT_QUEUE];

  private:
    /**
     * Hidden constructor.
     */
    TimeoutManager() {}
    
    /**
     * Hidden destructor.
     */
    ~TimeoutManager() {}
    
    /**
     * Find free plase in array.
     */
    int getFreeQueueIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {
        if (this->queue[index] == NULL) {
          return index;  
        }
      }
      
      return NO_FREE_INDEX;
    }
        
  public:

    /**
     * Instance of OSystem.
     */
    static TimeoutManager & get() {
      static TimeoutManager instance;

      return instance;
    }
    
    /**
     * Add new timeout to queue.
     */
    int setTimeout(Timeout * timeout, int unsigned time) {
      int index = this->getFreeQueueIndex();      
      if (index != NO_FREE_INDEX) {
        timeout->expireTime = micros() + time;  
        this->queue[index] = timeout;
      }

      return index;
    }

    /**
     * Clear timeout by index.
     */
    void clearTimeout(int index) {
      if (this->queue[index] != NULL) {
        delete &(this->queue[index]);
      }
    }

    /**
     * Check all queue.
     */
    void triggerQueue() {
      int unsigned time = micros();

      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {      
        if (this->queue[index] != NULL && this->queue[index]->expireTime <= time) {
          this->queue[index]->execute();
          delete &(this->queue[index]);
        }
      }
    }

};
