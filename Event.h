
/**
 * @file
 * Event class.
 */

template<typename TargetType>
class Event {

  public:

    /**
     * Event name.
     */
    String type;

    /**
     * Target element.
     */
    TargetType * target;

    /**
     * Constructor.
     */
    Event(String type, TargetType * target) {
      this->type = type;
      this->target = target;
    }

};
