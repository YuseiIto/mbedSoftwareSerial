#include "mbed.h"

class SoftwareSerial{

private:
DigitalOut tx;
InterruptIn rx;
Timer t;


uint16_t baudrate=9600;//bps

uint8_t mesureTime();

__INLINE void setTX(uint8_t i);
void reCalcDelay();


public: 
SoftwareSerial(PinName tx,PinName rx);
~SoftwareSerial();


uint8_t pin_delay=0;//us
uint8_t uart_delay=0;//us


void baud(uint16_t _baudrate);
void write(uint8_t buf);
};
