// Prince Home Network IOT Listener

RF24 radio(8, 9); // CE & CSN pins
RF24Network network(radio);
HomeNetwork homeNetwork(radio, network);

/**
 *  Thread for the Home Network
 **/
static msg_t Thread1(void *arg)
{
  chThdSleepMilliseconds(3000); // If this thread starts too fast, the Arduino will crash!

  SPI.begin(); // SPI is used by the RF24 module
  homeNetwork.begin(nodeID); // Run RF24 config for the customized Prince Home Automation and IOT Network
  Serial.println(F("Started network\n"));

  while (1) {
    homeNetwork.update(); // Check the network regularly for the entire network to function properly

    int16_t msgSenderReceived;
    int32_t msgReceived;
    unsigned char msgTypeReceived = 'Z';
    msgSenderReceived = homeNetwork.read(&msgReceived, &msgTypeReceived);

    // Put code in this if-statement which should occur when a message is received
    if (msgReceived != -1) {
      msgSender = msgSenderReceived;
      msgContent = msgReceived;
      msgType = msgTypeReceived;
      Serial.print(F("---------------Received Data Raw------------------- \nRaw Message sender: "));
      Serial.println(msgSender);
      Serial.println(F("Raw Type content: "));
      Serial.write(msgType);
      Serial.print(F("\nRaw Message content: "));
      Serial.println(msgContent);
      Serial.println(F("-----------------------------------------------"));
    }

    chThdSleepMilliseconds(50);  //Give other thread some time to run
  }
}
