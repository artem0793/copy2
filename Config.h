
/**
 * @file
 * Configuration file.
 */

/**
 * Time for loop interval.
 */
const int unsigned OS_DELAY_TIME = 30;

/**
 * Default value for no value.
 * Do not change!
 */
const int NO_FREE_INDEX = -1;

/**
 * Max size of handlers for all events.
 */
const int unsigned MAX_SIZE_OF_EVENT_LISTENERS = 4;

/**
 * Max size of timeout queue.
 */
const int unsigned MAX_SIZE_OF_TIMEOUT_QUEUE = 4;

// Events names

/**
 * Setup event name.
 */
const String EVENT_ON_SETUP = "s";

/**
 * Connect event name.
 */
const String EVENT_ON_CONNECT = "c";

/**
 * Disconnect event name.
 */
const String EVENT_ON_DISCONNECT = "dc";

/**
 * Change event name.
 */
const String EVENT_ON_CHANGE = "ch";
