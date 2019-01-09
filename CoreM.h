
/**
 * @file
 * Core system class.
 */

class CoreM: public EventTarget<CoreM> {

  private:
    // Hidden.
    CoreM(CoreM const &);
    // Hidden.
    CoreM & operator = (CoreM const &);

    /**
     * Hidden constructor.
     */
    CoreM() {}

    /**
     * Hidden destructor.
     */
    ~CoreM() {}

  public:    

    /**
     * Instance of OSystem.
     */
    static CoreM & get() {
      static CoreM instance;

      return instance;
    }

    /**
     * Instance of OSystem.
     */
    void init() {
      this->dispatchEvent(new Event<CoreM>("setup", this));
    }

    /**
     * loop callback.
     */
    void loop() {
      if (OS_DELAY_TIME > 0) {
        delay(OS_DELAY_TIME);
      }

      timeout_manager_get().trigger();
    }
};

/**
 * Get system obkect controller.
 */
CoreM & core_get() {
  return CoreM::get();
}
