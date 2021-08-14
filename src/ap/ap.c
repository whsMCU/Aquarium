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


  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      //ledToggle(_DEF_LED1);
    }

    if(buttonGetPressed(_DEF_BUTTON1))
    {
    	ledToggle(_DEF_LED1);
    }

//    cliMain();
  }
}
