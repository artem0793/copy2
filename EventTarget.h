
/**
 * @file
 * Event API.
 */

template<typename TargetType>
class EventTarget {
  protected:
    
    /**
     * Array of handler with all events.
     */
    EventCallback<TargetType> * eventHandlers[MAX_SIZE_OF_EVENT_LISTENERS];
    
    /**
     * Find free plase in array.
     */
    int getFreeEventHandlerIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->eventHandlers[index] == NULL) {
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
      int index = this->getFreeEventHandlerIndex();

      if (index != NO_FREE_INDEX) {
        callback->type = type;
        this->eventHandlers[index] = callback;
      }
    }

    /**
     * Remove event handler.
     */
    void removeEventListener(EventCallback<TargetType> * callback) {
      for (int unsigned index = 0; index <= MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->eventHandlers[index] == callback) {
          delete this->eventHandlers[index];
        }
      }
    }

    /**
     * Fire all events by group.
     */
    void dispatchEvent(Event<TargetType> * event) {
      for (int unsigned index = 0; index <= MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->eventHandlers[index]->type == event->type) {
          this->eventHandlers[index]->callback(event);
        }
      }

      delete event;
    }

};
