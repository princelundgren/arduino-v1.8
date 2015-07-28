/**
 ** CommandExecutioner thread
 ** Executes commands
 **/

int32_t executeCommand = 0;

// Declare a semaphore with an inital counter value of zero.
SEMAPHORE_DECL(cmdExSem, 0);

static msg_t CommandExecutioner(void *arg)
{
  Serial.println(F("Started CommandExecutioner thread, waiting for command to be executed"));

  while (1)
  {
    // Wait for signal to run
    chSemWait(&cmdExSem);

    switch (executeCommand) {
      case cmdSetPCDisableMonitors:
        pcDisableMonitors();
        Serial.println(F("Disabled Monitors"));
        break;
      case cmdSetPCEnableMonitors:
        pcEnableMonitors();
        Serial.println(F("Enabled Monitors"));
        break;
    }
  }
  return 0;
}

/*
 * Run this function to enable CommandExecutionerThread to run
 */
void executeCommand(int32_t _commandToExecute) {
  commandToExecute = _commandToExecute;
  chSemSignal(&cmdExSem);
}
