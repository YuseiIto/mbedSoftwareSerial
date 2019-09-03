#include <mbed.h>
#define UART_DELAY 97//101Max,92 Min(104 in theory)

Serial pc(USBTX,USBRX);
DigitalOut RX(D4);
DigitalOut TX(D5);

int main() {

  // put your setup code here, to run once:
  TX=1;
  pc.baud(230400);
  pc.printf("Boot");

  while(1) {
      put your main code here, to run repeatedly:
      TX=0;//START
      wait_us(UART_DELAY);

      TX=1;//DB0
      wait_us(UART_DELAY);

      TX=0;//DB1
      wait_us(UART_DELAY);

      TX=0;//DB2
      wait_us(UART_DELAY);

      TX=0;//DB3
      wait_us(UART_DELAY);

      TX=0;//DB4
      wait_us(UART_DELAY);

      TX=0;//DB5
      wait_us(UART_DELAY);

      TX=1;//DB6
      wait_us(UART_DELAY);

      TX=0;//DB7
      wait_us(UART_DELAY);

     TX=1;//Stop
    wait(1);

  }
}
