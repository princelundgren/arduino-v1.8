/** 
 * Switches
 */

// Variables for switch pins
const int leftSwitchPin = 4;
const int rightSwitchPin = 5;

/** 
 * Relay / Lights
 */

// Ceiling lights relay/ceiling light pin
const int mainLightsPin = A0;

/** 
 * MESHNODE
 */
// This is the nodeID of this Arduino.
// WARNING! DONT FORGET TO SET UNIQUE NODE ID IN config.h FOR EACH NODE!
// If you are creating a new node add it to: "\library\HomeNetwork\homeNetworkNodes.h"
const uint16_t nodeID = nodeMainLights;

//Hardware
const uint8_t homeNetworkCEPin = 8;
const uint8_t homeNetworkCSNPin = 9;

//Tweaks
const uint16_t homeNetworkCheckMessageDelay = 40; // How often to check for a new message, WARNING! The shorther the delay the less time for for other threads!
