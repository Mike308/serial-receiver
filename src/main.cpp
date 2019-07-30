#include <Arduino.h>
#include "SerialReceiver.h"

SerialReceiver serialReceiver;
char buff[32];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  Serial.println("Serial Receiver tester");

}

void loop() {
  // put your main code here, to run repeatedly:
    serialReceiver.usartEvent(buff);
  
}

void serialEvent() {
  serialReceiver.isrHandler();
}