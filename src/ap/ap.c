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
	LCD_CLEAR();
	LCD_XY(6, 0); LCD_PUTS((char *)"AQUARIUM");
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

    Ds18b20_ManualConvert();

    LCD_XY(1, 1); LCD_PUTS((char *)"Water_Temp : ");
    LCD_XY(13, 1); output_TEMP(ds18b20[0].Temperature*10);
    LCD_XY(18, 1); LCD_print_SC(223);
    LCD_XY(4, 3); LCD_PUTS((char *)"I LOVE YUJIN");
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
