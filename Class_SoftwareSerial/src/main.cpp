#include <mbed.h>
#include "SoftwareSerial.h"

Serial pc(USBTX,USBRX);
SoftwareSerial ss(D5,D4);

int main() {

  // put your setup code here, to run once:
  pc.baud(230400);
  pc.printf("Boot");

ss.baud(9600);

  while(1) {
      //put your main code here, to run repeatedly:
  
ss.write('A');
wait(1);

pc.printf("pin:%d\tuart:%d\t\n",ss.pin_delay,ss.uart_delay);
  }
}
