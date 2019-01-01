
/**
 * @file
 * EventCallback class.
 */

template<typename TargetType>
class EventCallback {
  
  public:

    /**
     * Envent name.
     */
    String type;

    /**
     * Handler callback.
     */
    virtual void callback(Event<TargetType> * event) {}

};
