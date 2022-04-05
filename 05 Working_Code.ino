/*
* LED 8x8 DotMarix using Arduino
* Created by TheCircuit
*/

#include <LedControl.h>

int DIN = 12; 
int CS =  11;
int CLK = 10; 

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,2);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
    byte a[8] = {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C}; //Smily
    printByte(a);
    delay(1000);
    byte b[8] = {0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66}; // letter H
    printByte(b);
    delay(1000);
    byte c[8] = {0x62,0x66,0x6C,0x78,0x78,0x6C,0x66,0x63}; // letter K
    printByte(c);
    delay(1000);
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
