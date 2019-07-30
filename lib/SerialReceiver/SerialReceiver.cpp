#include "SerialReceiver.h"

SerialReceiver::SerialReceiver() {}

void SerialReceiver::isrHandler() {
  while (Serial.available() > 0) {
    uint8_t tmpHead;
    char data;
    tmpHead = (rxHead + 1) & RX_MASK;
    data = (char)Serial.read();
    if (tmpHead == rxTail) {
    } else {
      switch (data) {
      case 0:
      case 10:
        break;
      case 13:
        line++;
      default:
        rxHead = tmpHead;
        rxBuff[tmpHead] = data;
      }
    }
  }
}

char SerialReceiver::getChar() {
    if (rxHead == rxTail) return 0;
    rxTail = (rxTail + 1) & RX_MASK;
    return rxBuff[rxTail];
}

void SerialReceiver::getString(char *str) {
    char c;
    if (line) {
        while (c = getChar()) {
            if (13 == c || c < 0) break;
            *str++ = c;
        }
        *str = 0;
        line--;
    }
}

void SerialReceiver::usartEvent(char *rxString) {
    if (line) {
        getString(rxString);
        Serial.print("RX: ");
        Serial.println(rxString);
    }
}

void SerialReceiver::setOnReceiveCallback(void (*callback)(char * rxStr)) {

}

