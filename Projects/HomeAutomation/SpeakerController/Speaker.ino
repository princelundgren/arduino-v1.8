
boolean speakerMuteStatus = 0;

bool getSpeakerPowerSwitchStatus() {
  return digitalRead(SPEAKER_POWER_RELAY_PIN);
}

void toggleSpeakerPower(void) {
  Serial.print(F("Toggling speaker power: "));
  Serial.println(digitalRead(SPEAKER_POWER_RELAY_PIN));
  if (digitalRead(SPEAKER_POWER_RELAY_PIN))
  {
    sendSpeakerPowerOffCommand();
  }
  else
  {
    sendSpeakerPowerOnCommand();
  }
}

void sendSpeakerPowerOnCommand(void) {
  digitalWrite(SPEAKER_POWER_RELAY_PIN, 1);
  nilThdSleepMilliseconds(1000); // Wait for Speaker to recharge its capacitors and reach standby mode
  sendSpeakerCommand(SPEAKER_IR_POWER); // Send IR power command
  Serial.println(F("Turning on speaker"));
}

void sendSpeakerPowerOffCommand(void) {
  digitalWrite(SPEAKER_POWER_RELAY_PIN, 0);
  Serial.println(F("Turning off speaker"));
}

void sendSpeakerUpVolCommand(void)
{
  for (int i = 0; i < 2 ; i++)
    sendSpeakerCommand(SPEAKER_IR_UPVOLUME);
  speakerMuteStatus = false;
  Serial.println(F("Increased volume level"));
}

void sendSpeakerDownVolCommand(void)
{
  for (int i = 0; i < 2 ; i++)
    sendSpeakerCommand(SPEAKER_IR_DOWNVOLUME);
  speakerMuteStatus = false;
  Serial.println(F("Dropped volume level"));
}

void toggleSpeakerMuteCommand(void)
{
  if (getSpeakerPowerSwitchStatus()) {
    sendSpeakerCommand(SPEAKER_IR_MUTE);
    speakerMuteStatus = !speakerMuteStatus;
    Serial.print(F("Toggling mute: "));
    Serial.println(speakerMuteStatus);
  }
}

void sendSpeakerMuteOnCommand(void)
{
  if (!speakerMuteStatus && getSpeakerPowerSwitchStatus())
  {
    sendSpeakerCommand(SPEAKER_IR_MUTE);
    speakerMuteStatus = 1;
    Serial.println(F("Sent mute on command to speaker"));
  }
}

void sendSpeakerMuteOffCommand(void)
{
  if (speakerMuteStatus && getSpeakerPowerSwitchStatus())
  {
    sendSpeakerCommand(SPEAKER_IR_MUTE);
    speakerMuteStatus = 0;
    Serial.println(F("Sending mute off command to speaker!"));
  }
}

void toggleSpeakerModeCommand(void)
{
  if (getSpeakerPowerSwitchStatus()) {
    Serial.print(F("Toggling mode: "));
    if (!getSpeakerModeStatus()) { // If its Line-In mode, toggle to PC
      setSpeakerModePCCommand();
    } else { // If its PC mode, toggle to Line-In
      setSpeakerModeLineInCommand();
    }
  }
}

void setSpeakerModePCCommand(void)
{
  if (getSpeakerPowerSwitchStatus() && !getSpeakerModeStatus()) {
    sendSpeakerCommand(SPEAKER_IR_MODE);
    nilThdSleepMilliseconds(300);
    sendSpeakerCommand(SPEAKER_IR_RIGHT);
    nilThdSleepMilliseconds(300);
    sendSpeakerCommand(SPEAKER_IR_OK);
    setSpeakerModeStatus(1);
    Serial.println(F("Set to PC Mode"));
  }
}

void setSpeakerModeLineInCommand(void)
{
  if (getSpeakerPowerSwitchStatus() && getSpeakerModeStatus()) {
    sendSpeakerCommand(SPEAKER_IR_MODE);
    nilThdSleepMilliseconds(300);
    sendSpeakerCommand(SPEAKER_IR_LEFT);
    nilThdSleepMilliseconds(300);
    sendSpeakerCommand(SPEAKER_IR_OK);
    setSpeakerModeStatus(0);
    Serial.println(F("Set to Line In Mode"));
  }
}

// Will return 0 if Line in, 1 if PC
bool getSpeakerModeStatus() {
  return EEPROM.read(SPEAKER_EEPROM_MODE_ADDRESS);
}

void setSpeakerModeStatus(bool status) {
  EEPROM.write(SPEAKER_EEPROM_MODE_ADDRESS, status);
}


void sendSpeakerCommand(unsigned long command)
{
  irsend.send(NEC, command, 32);
}

