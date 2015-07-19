#include <ChibiOS_AVR.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <HomeNetwork.h>
#include "config.h"

//Variables which stores the received values from other nodes
//Regularly check msgReceived variable if a message is received in thread
bool msgReceived = false;
uint16_t msgSender = -1;
unsigned char msgType = 'Z';
int32_t msgContent = -1;

RF24 radio(homeNetworkCEPin, homeNetworkCSNPin);
RF24Network network(radio);
HomeNetwork homeNetwork(radio, network, &homeNetwork);

void setup() {
  Serial.begin(115200);

  initLights();

  chBegin(chSetup);
  // chBegin never returns, main thread continues with mainThread()

  while (1);
}

static WORKING_AREA(wallSwitchThread, 64);
static WORKING_AREA(hNListenThread, 64);

void chSetup() {
  SPI.begin(); // SPI is used by homeNetwork
  homeNetwork.begin(nodeID, &msgReceived, &msgSender, &msgType, &msgContent);

  chThdCreateStatic(wallSwitchThread, sizeof(wallSwitchThread), NORMALPRIO + 2, WallSwitchThread, NULL);

  chThdCreateStatic(hNListenThread, sizeof(hNListenThread), NORMALPRIO + 2, HNListenThread, NULL);

}

void loop() {
  // not used
}



