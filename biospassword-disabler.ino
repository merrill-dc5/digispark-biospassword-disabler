#include "DigiKeyboard.h"

long wait_bios_ms = 30000;
char bios_password[]= "YOUR_BIOS_PASSWORD";

long wait_windows_ms = 120000;
char windows_password[]= "YOUR_WINDOWS_PASSWORD";

void setup() {
  // use built-in led(pin no. is 1) 
  pinMode(1, true);

  // turn on built-in led
  digitalWrite(1,HIGH);

  // initialize usb connection
  DigiKeyboard.update();

  // wait prompt of bios password
  DigiKeyboard.delay(wait_bios_ms);

  // to prevent missing first input
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);

  // input password and hit enter
  DigiKeyboard.print(bios_password);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // wait starting up of windows
  DigiKeyboard.delay(wait_windows_ms);

  // to prevent missing first input
  DigiKeyboard.sendKeyStroke(0);

  // to show prompt
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  
  // input password and hit enter
  DigiKeyboard.print(windows_password);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // turn on built-in led
  digitalWrite(1,LOW);
}

void loop() {
  // do nothing
}