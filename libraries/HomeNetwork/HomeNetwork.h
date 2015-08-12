#ifndef __HOMENETWORK_H__
#define __HOMENETWORK_H__

/*
HomeNetwork.h - Library for Prince Home Automation & IOT network of RF24 nodes
*/
#include <ChibiOS_AVR.h>
#include "RF24.h"
#include "RF24Network.h"
#include "nodesConfig.h"

class RF24;
class RF24Network;

class HomeNetwork
{
public:
  HomeNetwork(RF24& _radio, RF24Network& _network, HomeNetwork* _homeNetwork);
  void begin(uint16_t nodeID, void (* _pmsgReceivedF)(uint16_t,unsigned char,int32_t));
  void autoUpdate();
  void setTimeout(int32_t _homeNetwork_timeoutSendTime, int32_t _homeNetwork_timeoutAnswerTime);
  void setAutoUpdateTime(int32_t _homeNetwork_autoUpdateTime);
  bool respondToQuestion(uint16_t _msgSender, int32_t _ResponseData);
  bool send(uint16_t msgReceiver, int32_t msgContent, unsigned char msgType);
  bool sendCommand(uint16_t msgReceiver, int32_t msgContent);
  bool sendQuestion(uint16_t msgReceiver, int32_t msgContent, int32_t *pmsgResponse);

private:
  RF24& radio;
  RF24Network& network;
  HomeNetwork* homeNetwork;

  void (* pmsgReceivedF)(uint16_t,unsigned char,int32_t);

  bool autoUpdatePaused = false;

  // Tweaks optimized for compatability, reliability, driftsecurity and at least performance for Prince home IOT network
  // Tweak however you want though
  uint16_t homeNetwork_timeoutSendTime = 1000; // Amount of time before trying to resend message again to node
  uint16_t homeNetwork_defaultTimeoutSendTime = 1000;
  uint16_t homeNetwork_timeoutAnswerTime = 1000; // Amount of time to wait until given up waiting of answer to question
  uint16_t homeNetwork_defaultTimeoutAnswerTime = 1000;
  uint16_t homeNetwork_autoUpdateTime = 5; // How often the network is updated
  uint16_t homeNetwork_defaultAutoUpdateTime = 5;

  // Set delay between retries & # of retries for a "radio.write" command
  const uint8_t homeNetwork_retryDelay = 2;
  const uint8_t homeNetwork_retryTimes = 25;

  const uint8_t homeNetwork_powerAmplifierLevel = RF24_PA_MAX;  // Set power amplifier to highest
  const rf24_datarate_e homeNetwork_dataRate = RF24_2MBPS;  // Set data rate to 250kpbs(other settings: RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)

  const uint8_t homeNetwork_channel = 90; // Default Home network is using channel 90, dont know other channels though

  // Local communication functions
  uint16_t read(int32_t *pmsgReceived, unsigned char *pmsgType);
};
#endif
