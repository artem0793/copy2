
/**
 * @file
 * Event API.
 */

template<typename TargetType>
class EventTarget {

  protected:
  
    /**
     * Mapping of free queue.
     */
    boolean mapping[MAX_SIZE_OF_EVENT_LISTENERS] = { false };

    /**
     * Array of handler with all events.
     */
    EventCallback<TargetType> * handlers[MAX_SIZE_OF_EVENT_LISTENERS];

    /**
     * Find free plase in array.
     */
    int getFreeMapIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->mapping[index] == false) {
          return index;  
        }
      }

      return NO_FREE_INDEX;
    }
    
  public:

    /**
     * Add hendler to event.
     */
    void addEventListener(String type, EventCallback<TargetType> * callback) {
      int index = this->getFreeMapIndex();

      if (index != NO_FREE_INDEX) {
        callback->type = type;
        this->handlers[index] = callback;
        this->mapping[index] = true;
      }
    }

    /**
     * Remove event handler.
     */
    void removeEventListener(EventCallback<TargetType> * callback) {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->mapping[index] == true && this->handlers[index] == callback) {
          delete &(this->handlers[index]);
          this->mapping[index] = false;
        }
      }
    }

    /**
     * Fire all events by group.
     */
    void dispatchEvent(Event<TargetType> * event) {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->mapping[index] == true && this->handlers[index]->type == event->type) {
          this->handlers[index]->callback(event);
        }
      }

      delete &event;
    }

};
