uint8_t ledBrightness = minLEDBrightness;
NIL_WORKING_AREA(apartmentStatusLEDThread, 0); // 0 bytes seems to work fine
NIL_THREAD(ApartmentStatusLEDThread, arg) {
  pinMode(ledPin, OUTPUT);
  Serial.println(F("Started Apartment Status LED Thread"));

  while (TRUE) {
    if (ledStatus) {
      // change the brightness for next time through the loop:
      ledBrightness = ledBrightness + fadeAmount;

      analogWrite(ledPin, ledBrightness);

      // reverse the direction of the fading at the ends of the fade:
      if (ledBrightness <= minLEDBrightness) {
        fadeAmount = -fadeAmount;
        nilThdSleepMilliseconds(1000);
      }
      else if (ledBrightness >= maxLEDBrightness) {
        fadeAmount = -fadeAmount;
        nilThdSleepMilliseconds(1000);
      }

    } else {
      // reverse the direction of the fading at the ends of the fade:
      if (fadeAmount > 0) { // Reverse fade if its fading up
        fadeAmount = -fadeAmount;
      } else if (ledBrightness != 0) { // Keep fading out LED untill 0
        ledBrightness = ledBrightness + fadeAmount;
        analogWrite(ledPin, ledBrightness);
      } else if (ledBrightness == 0) {
        nilThdSleepMilliseconds(200); // Idle when LED has shut down
      }
    }
    nilThdSleepMilliseconds(fadeTime);
  }
}

void setLED(bool state) {
  if (ledStatus != state) {
    switch (state) {
      case HIGH:
        //Make it fade up
        if (fadeAmount < 0)
          fadeAmount = -fadeAmount;
        // Make LED start from the minimum value and go up
        ledBrightness = minLEDBrightness;
        break;
    }
    ledStatus = state;
  }
}
