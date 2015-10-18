// Here you can give each node we will be communicating with a name.
// We only have 5 talk/listen pipes,
// so we can only have 5 nodes in this network

//***********************Global Message types**************************************************************
// 'Message type' is packet within the header of a message, it is read by
// the receiver to understand what type of packet it is

// Types every node can use for each other:
#define HOME_TYPE_COMMAND 'C'
#define HOME_TYPE_COMMAND_FAST 'D'
#define HOME_TYPE_CONFIRMATION 'O'

#define HOME_TYPE_QUESTION 'Q'
#define HOME_TYPE_QUESTION_FAST 'S'
#define HOME_TYPE_RESPONSE 'R'

//***********************Main Room Lights************************************************************
// This is the base node, this node cannot have children! (ie. node 10,20,30,40 and 50 will not work!)
#define HOME_MAINLIGHTS_ID 00

// Command
#define HOME_MAINLIGHTS_CMD_MAINLIGHTS_TOGGLE 1
#define HOME_MAINLIGHTS_CMD_MAINLIGHTS_ON 2
#define HOME_MAINLIGHTS_CMD_MAINLIGHTS_OFF 3
// Question
#define HOME_MAINLIGHTS_QSN_MAINLIGHTS_STATUS 1

//***********************Home Control************************************************************
//First child of Main Room Lights node
#define HOME_HOMECONTROL_ID 01

// Command(message type: typeCommand)
// Starts from 17 because buttons use 1-16
#define HOME_HOMECONTROL_CMD_PC_ON 17

//***********************433MHz************************************************************
// First child of Home Control
#define HOME_RF433MHZ_ID 011

// Question
#define HOME_RF433MHZ_QSN_PAINTINGLIGHTS_STATUS 1

// Command
#define HOME_RF433MHZ_CMD_PAINTINGLIGHTS_ON 1
#define HOME_RF433MHZ_CMD_PAINTINGLIGHTS_OFF 2
#define HOME_RF433MHZ_CMD_PAINTINGLIGHTS_TOGGLE 3

//***********************Bed Switch************************************************************
//Second child of Home Control
#define HOME_WEBSERVER_ID 021

// Command
#define HOME_WEBSERVER_CMD_MONITOR_DISABLE 1
#define HOME_WEBSERVER_CMD_MONITOR_ENABLE 2
#define HOME_WEBSERVER_CMD_SPOTIFY_CHILL 3
#define HOME_WEBSERVER_CMD_SPOTIFY_DINNER 4
#define HOME_WEBSERVER_CMD_SPOTIFY_WORKOUT 5
#define HOME_WEBSERVER_CMD_SPOTIFY_WORK 6

//***********************Speaker************************************************************
//Third child of Home Control
#define HOME_SPEAKER_ID 031

// Command
#define HOME_SPEAKER_CMD_POWER_TOGGLE 1
#define HOME_SPEAKER_CMD_POWER_ON 2
#define HOME_SPEAKER_CMD_POWER_OFF 3
#define HOME_SPEAKER_CMD_VOLUME_UP 4
#define HOME_SPEAKER_CMD_VOLUME_DOWN 5
#define HOME_SPEAKER_CMD_MUTE_TOGGLE 6
#define HOME_SPEAKER_CMD_MUTE_ON 7
#define HOME_SPEAKER_CMD_MUTE_OFF 8
#define HOME_SPEAKER_CMD_MODE_TOGGLE 9
#define HOME_SPEAKER_CMD_MODE_PC 10
#define HOME_SPEAKER_CMD_MODE_LINEIN 11

//***********************Bed Switch************************************************************
//Second child of Main Room Lights
#define HOME_BEDSWITCH_ID 02

//***********************Example Sketches like ToggleMainLights or AskMainLightsStatus************************************************************
#define HOME_TEST_ID 05

// Command(message type: typeCommand)
#define HOME_TEST_CMD 1
// Question
#define HOME_TEST_STATUS 1
//***********************Other Nodes****************************************************************************
//static const uint16_t nodeNAS = 02;
//static const uint16_t nodeRaspberryPi = 03;
//static const uint16_t nodeVoiceRecog = 04;
//static const uint16_t nodePC = 02;

//***********************homeNetworkExampleServer****************************************************
//static const uint16_t nodeExampleA = 041; // Used for example/testing. This node is second child of centralHomeControl-node
//static const uint16_t nodeExampleB = 051; // Used for example/testing. This node is third child of centralHomeControl-node

// Commands to offer
//static const int32_t cmdExampleAskCommand = 12345;
//static const int32_t cmdExampleResponseData = 67890;
