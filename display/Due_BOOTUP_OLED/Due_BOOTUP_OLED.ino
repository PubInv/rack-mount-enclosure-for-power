#define PROG_NAME "Due_BOOTUP_OLED"
// Author: Forrest Lee Erickson
// Date: 20250402
// A PMD BootUp, Similar to Do Nothing but Serial Splash, LCD Test, LCD Splash, DFPlayer Test, DFPlayer Splash, BootButton Test for stuck key. Loop() has only non blocking code.
// https://github.com/PubInv/krake/issues/158
// Hardware: Control V1.2

// Customized this by changing these defines

#define VERSION " V0.0.1 "
#define MODEL_NAME "Model: Due_BOOTUP_OLED"
#define DEVICE_UNDER_TEST "SN: 00001"  //A Serial Number
#define LICENSE "GNU Affero General Public License, version 3 "
#define ORIGIN "LB"

#define BAUDRATE 115200  //Serial port

#include <Wire.h>

// Some PMD Hardware
// Pins for switches and LEDs and more
#define BOOT_BUTTON 0
//FLE const int LED_BUILTIN = 2;


void splashserial(void) {
  //Serial splash
  Serial.println(F("==================================="));
  Serial.print(PROG_NAME);
  Serial.println(VERSION);
  Serial.println(MODEL_NAME);
  Serial.println(DEVICE_UNDER_TEST);
  Serial.print(F("Compiled at: "));
  Serial.println(F(__DATE__ " " __TIME__));  //compile date that is used for a unique identifier
  Serial.println(LICENSE);
  Serial.println(F("==================================="));
  Serial.println();
}


// The Setup

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  //Make built in LED low at end of setup.

  Serial.begin(BAUDRATE);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB
  }
  splashserial();

  Wire.begin();
  initOLED();
  splashOLED();
  digitalWrite(LED_BUILTIN, LOW);  //Make built in LED low at end of setup.
}
//end setup()

void loop() {

  //  wink();  // Heart beat aka activity indicator LED function.

}  //end loop()
