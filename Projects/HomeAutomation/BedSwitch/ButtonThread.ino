NIL_WORKING_AREA(buttonThread, 100); // 50 bytes seems to work fine
NIL_THREAD(ButtonThread, arg) {

  pinMode(BUTTON_PIN, INPUT);

  bool buttonStatus = 0; // variable for reading the pushbutton status
  bool lastButtonStatus = 0;

  Serial.println(F("Started Button listener Thread"));

  while (1) {
    buttonStatus = digitalRead(BUTTON_PIN);

    if (buttonStatus && !lastButtonStatus) {
      Serial.println("Pressed button..");

      apartmentStatusUpdaterPaused = true; // Pause the apartment status polling
      apartmentStatusUpdaterPauseExecuted = true;
      while (!apartmentStatusUpdaterPauseExecuted) // Wait for the pause to happen
        nilThdSleepMilliseconds(10);

      executeCommand(CMD_APARTMENT_TOGGLE);

      lastButtonStatus = HIGH;
      nilThdSleepMilliseconds(buttonDebounceTime);

      apartmentStatusUpdaterPaused = false; // Resume the apartment status polling

    } else if (!buttonStatus && lastButtonStatus) {
      lastButtonStatus = LOW;
      Serial.print("Disabled button for ");
      Serial.print(buttonRepressTime);
      Serial.println(" seconds");
      nilThdSleepMilliseconds(buttonRepressTime); // Wait 10 seconds before able to press button again
      Serial.println("Button is enabled again!");
    }

    nilThdSleepMilliseconds(buttonReadUpdateTime);
  }
}

