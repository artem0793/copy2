
/**
 * @file
 * Core system class.
 */

class OSystemCore: public EventTarget<OSystemCore> {

  private:
      // Hidden.
    OSystemCore(OSystemCore const&);
    // Hidden.
    OSystemCore& operator= (OSystemCore const&);
    // Hidden.
    /**
     * Hidden constructor.
     */
    OSystemCore() { Serial.println("const: OSystemCore");}

    /**
     * Hidden destructor.
     */
    ~OSystemCore() { Serial.println("dest: OSystemCore");}

  public:    

    /**
     * Instance of OSystem.
     */
    static OSystemCore & get() {
      static OSystemCore instance;

      return instance;
    }

    /**
     * loop callback.
     */
    void loop() {
      TimeoutManager::get().triggerQueue();

      if (OS_DELAY_TIME > 0) {
        delay(OS_DELAY_TIME);
      }
    }
};
