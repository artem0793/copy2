
/**
 * @file
 */

class TimeoutManager {

  protected:

    /**
     * Mapping of free queue.
     */
    boolean mapping[MAX_SIZE_OF_TIMEOUT_QUEUE] = { false };

    /**
     * Queue.
     */
    Timeout * queue[MAX_SIZE_OF_TIMEOUT_QUEUE];

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
    int getFreeMapIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {
        if (this->mapping[index] == false) {
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
    int add(Timeout * timeout, int unsigned timer) {
      int index = this->getFreeMapIndex();      

      if (index != NO_FREE_INDEX) {
        this->mapping[index] = true;
        this->queue[index] = timeout;
        this->queue[index]->expireTime = millis() + timer;
      }

      return index;
    }

    /**
     * Clear timeout by index.
     */
    void removeAt(int unsigned index) {
      if (this->mapping[index] == true) {
        this->mapping[index] = false;
      }
    }

    /**
     * Check all queue.
     */
    void trigger() {
      int unsigned timer = millis();

      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {        
        if (
            this->mapping[index] == true && 
            this->queue[index]->lock == false && 
            this->queue[index]->expireTime <= timer
        ) {
          this->queue[index]->execute();
          this->mapping[index] = false;
        }
      }
    }

};

/**
 * Get timeout manager.
 */
TimeoutManager & timeout_manager_get() {
  return TimeoutManager::get();
}

/**
 * Add new timeout to queue.
 */
int set_timeout(Timeout * timeout, int unsigned timer) {
  return timeout_manager_get().add(timeout, timer);
}

/**
 * Clear timeout by index.
 */
void clear_timeout(int unsigned index) {
  timeout_manager_get().removeAt(index);
}
