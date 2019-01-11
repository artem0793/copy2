
/**
 * @file.
 */

class TestTimeout: public Timeout {
  protected:
    void callback() override {
      Serial.println("Жопа");
    }
};

class TestTimeoutFirst: public Timeout {
  protected:
    void callback() override {
      Serial.println("Жопа");
      Serial.println(set_timeout(new TestTimeout, 0));
      core_get().loop();
    }
};

class TestEventHandler: public EventCallback<CoreM> {
  void callback(Event<CoreM> * event) override {
    Serial.println(event->type);
    event->target->removeEventListener(this);
  }
};

class TestTimeoutLoop: public Timeout {
  
  int unsigned i = 0;

  public:
    TestTimeoutLoop() {
      this->loop = true;
    }
  
  protected:
    void callback() override {
      if (this->i > 4) {
        clear_timeout(this->index);
      }
      else {
        Serial.println("Жопа");
        this->i++;  
      }
    }

};

void test_1() {
  Serial.print("Тест 1: Должно быть ");
  Serial.print(MAX_SIZE_OF_TIMEOUT_QUEUE);
  Serial.print(" Жоп, а потом еще одна. \n");
  for (int unsigned i = 0; i < MAX_SIZE_OF_TIMEOUT_QUEUE; i++) {
    Serial.println(set_timeout(new TestTimeout, 0));  
  }
  core_get().loop();
  Serial.println(set_timeout(new TestTimeout, 0));
  core_get().loop();
  Serial.println("END \n");
}

void test_2() {
  Serial.println("Тест 2: Рекурсия, должно быть Жопа в Жопе");
  Serial.println(set_timeout(new TestTimeoutFirst, 0));
  core_get().loop();
  Serial.println("END \n");
}

void test_3() {
  Serial.println("Тест 3: Событие setup");
  core_get().addEventListener("setup", new TestEventHandler);
  core_get().init();
  Serial.println("END \n");
}

void test_4() {
  Serial.println("Тест 4: Loop timeout - должно быть 5 Жоп");
//  TestTimeoutLoop * x = new TestTimeoutLoop;
//  x->loop = true;
//  Serial.println(set_timeout(x, 0));
  Serial.println(set_timeout(new TestTimeoutLoop, 0));

  for (int unsigned i = 0; i < 10; i++) {
    core_get().loop();
  }

  Serial.println("END \n");
}

void test() {
  Serial.begin(9600);
  Serial.print("Time: ");
  Serial.print(millis());
  Serial.print("\n\n");
  test_1();
  test_2();
  test_3();
  test_4();
  Serial.end();
  exit(1);
}
