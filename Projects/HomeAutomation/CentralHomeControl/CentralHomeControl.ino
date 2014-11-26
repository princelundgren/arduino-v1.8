/*
 *  This Sketch is to make a "universal home control".
 *  Controlling PC, lights, speaker & other home electronics
 *  Hardware needed:
 *  - 940 nm IR LED with a resistor to pin 3
 *  - NPN transistor for PC Power switch
 *  - 433 MHz transmitter
 *
 * WARNING: Don't use Digital Pin 10 even if its not used, its reserved by SPI library!
 */

// Needed libraries & config
#include <ChibiOS_AVR.h>
#include <Wire.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <CIRremote.h>
#include <Keypad.h>
#include "config.h" // config file

// Mutex for atomic access to data.
MUTEX_DECL(dataMutex);

// Data to share
volatile unsigned int dataX = 0;
volatile unsigned int dataY = 0;

// 64 byte stack beyond task switch and interrupt needs.
static WORKING_AREA(waThread1, 64);
// 128 byte stack beyond task switch and interrupt needs.
static WORKING_AREA(waThread2, 128);

//------------------------------------------------------------------------------
void setup() {
  // Enable Serial
  Serial.begin(9600);
  // Wait for USB Serial.
  while (!Serial) {
  }

  // Read any input
  delay(200);
  while (Serial.read() >= 0) {
  }

  // PC Power switch setup
  pcPowerSetup();

  Serial.println(F("Starting RTOS & threads"));
  chBegin(mainThread);
  // chBegin never returns, main thread continues with mainThread()
  while(1);
}

//------------------------------------------------------------------------------
// main thread runs at NORMALPRIO
void mainThread() {

  // start blink thread
  chThdCreateStatic(waThread1, sizeof(waThread1),
  NORMALPRIO + 2, Thread1, NULL);

  // start print thread
  chThdCreateStatic(waThread2, sizeof(waThread2),
  NORMALPRIO + 1, Thread2, NULL);
}

//------------------------------------------------------------------------------
void loop(){
  // not used
} 





