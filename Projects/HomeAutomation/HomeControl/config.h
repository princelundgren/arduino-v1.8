/*
*  This is the config file.
 *  Here you can configure Buttons assigns, IR codes, 
 *  RF24 codes & component pins.
 *  Also you can enable/disable serial
 */

/*
*  ------------------------------------
 *  RF24 Mesh Node
 *  ------------------------------------
 */

// This is the nodeID of this Arduino.
// WARNING! DONT FORGET TO SET UNIQUE NODE ID IN config.h FOR EACH NODE!
// If you are creating a new node add it to: "\library\HomeNetwork\homeNetworkNodes.h"
const uint16_t nodeID = nodeHomeControl;

//Hardware
const uint8_t homeNetworkCEPin = 8;
const uint8_t homeNetworkCSNPin = 9;

//Tweaks
const uint16_t homeNetworkCheckMessageDelay = 40; // How often to check for a new message, WARNING! The shorther the delay the less time for for other threads!

// Commands this node has to offer
const int32_t speakerPowerToggle = 1;
const int32_t speakerPowerOn = 2;
const int32_t speakerPowerOff = 3;
const int32_t speakerVolumeUp = 4;
const int32_t speakerVolumeDown = 5;
const int32_t speakerMuteToggle = 6;
const int32_t speakerMuteOn = 7;
const int32_t speakerMuteOff = 8;
const int32_t diningTableOn = 9;
const int32_t diningTableOff = 10;
const int32_t diningTableToggle = 11;

/*
*  ------------------------------------
 *  Keypad Button reservations
 *  ------------------------------------
 */
// NextBase
const uint8_t nBPowerButton = 4;
const uint8_t nBUpVolButton = 3;
const uint8_t nBDownVolButton = 2;
const uint8_t nBMuteButton = 1;
// Lights
const uint8_t lightMainButton = 8;
const uint8_t lightDiningTableButton = 7;
// PC swtich
const uint8_t pcPowerButton = 12;
/*
*  ------------------------------------
 *  IR Codes
 *  ------------------------------------
 */
// NEXTBASE IR codes
const unsigned long nBIRPower = 0xFFC23D;
const unsigned long nBIRMute = 0xFF02FD;
const unsigned long nBIRUpVolume = 0xFFF00F;
const unsigned long nBIRDownVolume = 0xFF708F;

/*
*  ------------------------------------
 *  433 MHz Switches codes
 *  ------------------------------------
 */
const uint8_t speakerUnit = 2;
const uint8_t lightDiningTable = 1;

/*
*  ------------------------------------
 *  Components pins
 *  ------------------------------------
 */

//940 nm IR LED with a resistor to pin 3
 
// PC Power pin pin
const int pcPowerPin = 7;

// 433 MHz switch transmitter pin
const int switch433TransmitterPin = 6;
