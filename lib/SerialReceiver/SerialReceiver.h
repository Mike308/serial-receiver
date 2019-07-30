#include <Arduino.h>

#define RX_BUFF_SIZE 32
#define RX_MASK RX_BUFF_SIZE - 1


class SerialReceiver {
    public:
        SerialReceiver();
        void setOnReceiveCallback(void (*callback)(char * rxStr));
        void usartEvent(char * rxStr);
        void isrHandler();
        void getString(char *str);

    private:
        void (*rxCallback)(char * str);
        uint8_t rxHead;
        uint8_t rxTail;
        uint8_t line;
        char rxBuff[RX_BUFF_SIZE];
        char getChar();
};

