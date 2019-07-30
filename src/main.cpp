#include <Arduino.h>
#include "SerialReceiver.h"

void rxCallBack(char *str);

SerialReceiver serialReceiver;
char buff[32];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  Serial.println("Serial Receiver tester");
  serialReceiver.setOnReceiveCallback(&rxCallBack);
}

void loop() {
  // put your main code here, to run repeatedly:
    serialReceiver.usartEvent(buff);

}

void rxCallBack(char *str) {
  Serial.print("Rx: ");
  Serial.println(str);
}

void serialEvent() {
  serialReceiver.isrHandler();
}