#include <mbed.h>
#define UART_DELAY 97//101Max,92 Min(104 in theory)
Serial pc(USBTX,USBRX);
DigitalOut RX(D4);
DigitalOut TX(D5);

Timer t;

int main() {

  // put your setup code here, to run once:
  TX=1;
  pc.baud(230400);
  pc.printf("Boot");
  
  while(1) {
    TX=1;//START
    t.reset();
    t.start();
    TX=0;//START
    t.stop();
    pc.printf("Time:%d useconds.\n",t.read_us());
    wait_ms(300);
  }
}
