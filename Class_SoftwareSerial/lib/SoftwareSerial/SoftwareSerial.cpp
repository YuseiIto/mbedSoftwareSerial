#include "SoftwareSerial.h"

SoftwareSerial::SoftwareSerial(PinName _tx,PinName _rx):tx(_tx),rx(_rx){
reCalcDelay();
setTX(1);
}

SoftwareSerial::~SoftwareSerial(){

}

__INLINE void SoftwareSerial::setTX(uint8_t i){
tx=i;
}

void SoftwareSerial::reCalcDelay(){
pin_delay=mesureTime();
uart_delay=(uint8_t)(1000000/baudrate)-pin_delay;
}

void SoftwareSerial::write(uint8_t buf){
    setTX(0);//START
    wait_us(uart_delay);

    for(uint16_t i=0;i<8;i++){
      setTX((buf&(0x01<<i))>>i);
      wait_us(uart_delay);   
    }

    setTX(1);
    wait_us(uart_delay);
}

uint8_t SoftwareSerial::mesureTime(){
    setTX(1);//START
    t.reset();
    t.start();
    setTX(0);
    t.stop();
    return t.read_us();
}


void SoftwareSerial::baud(uint16_t _baudrate){
baudrate=_baudrate;
reCalcDelay();
}


