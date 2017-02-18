/*
  ---------------------------------------------------------------
  This is the global logical variables tab.
  All global variables are here.
  What differs from logical variables and config variables are
  that logical variables are used for logical functions, and should NOT be changed.
  It must be named "A_" in the start of the tab-name or else it won't compile
  ---------------------------------------------------------------
*/


/*
  ---------------------------------------------------------------
  Task initialized
  Some tasks depend on other tasks to start before starting itself,
  with these variables they can check if the depending task has started
  ---------------------------------------------------------------
*/

bool taskHTTPStarted = 0;
bool taskCeilingLightsStarted = 0;
bool taskMemStarted = 0;

/*
  ---------------------------------------------------------------
  Task-to-Task communication
  ---------------------------------------------------------------
*/
bool ceilingLightsStatus = 0; // Current status of the ceilingLights


/*
  ---------------------------------------------------------------
  Wallswitches
  ---------------------------------------------------------------
*/

unsigned long leftInterruptDetected = 0; // Has a value above 0 when an interrupt is detected
unsigned long rightInterruptDetected = 0; // Has a value above 0 when an interrupt is detected
unsigned long lastLeftInterruptDetected = 0; // Save last interrupt time
unsigned long lastRightInterruptDetected = 0; // Save last interrupt time

