
/**
 * @file
 * Arduino API.
 */

// API tools.
#include "Config.h"
#include "Event.h"
#include "EventCallback.h"
#include "EventTarget.h"
#include "Timeout.h"
#include "TimeoutManager.h"
// System.
#include "OSystemCore.h";

/**
 * Get init system.
 */
void system_get() {
  OSystemCore::get();
}

/**
 * Trigger loop.
 */
void _system_loop() {
  OSystemCore::get().loop();
}

/**
 * Add new timeout to queue.
 */
int set_timeout(Timeout * timeout, int unsigned time) {
  return TimeoutManager::get().setTimeout(timeout, time);
}

/**
 * Clear timeout by index.
 */
void clear_timeout(int unsigned index) {
  TimeoutManager::get().clearTimeout(index);
}
