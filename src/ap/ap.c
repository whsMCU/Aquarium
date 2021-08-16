/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"



void lcdMain(void);



void apInit(void)
{
//  cliOpen(_DEF_UART1, 57600);
}

void apMain(void)
{
  uint32_t pre_time;
  uint8_t MSB, LSB;


  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      //ledToggle(_DEF_LED1);
    }

    if(!reset())
    {
    	write_byte(0xCC);  // skip ROM
    	write_byte(0x44);  // convert temperature
    	DWT_Delay_us(750);

    	reset();
    	write_byte(0xCC);     // skip ROM

    	write_byte(0xBE);     // read scratchpad

    	LSB = read_byte();
    	MSB = read_byte();
    }
    DWT_Delay_us(500);

    if(buttonGetPressed(_DEF_BUTTON1))
    {
    	ledOn(_DEF_LED1);
    }
    else
    {
    	ledOff(_DEF_LED1);
    }

//    cliMain();
  }
}
