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
	cliOpen(_DEF_UART1, 57600);
	LCD_CLEAR();
	LCD_XY(6, 0); LCD_PUTS((char *)"AQUARIUM");
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 1000)
    {
      pre_time = millis();

    }
    Ds18b20_ManualConvert();

    measure();

    LCD_XY(1, 1); LCD_PUTS((char *)"WTR_T : ");
    LCD_XY(8, 1); output_TEMP(ds18b20[0].Temperature*10);
    LCD_XY(13, 1); LCD_print_SC(223);
    LCD_XY(1, 2); LCD_PUTS((char *)"WTR_L : ");
    LCD_XY(9, 2); output_DISTANCE(sonar_tbl[0].filter_distance_cm);
    LCD_XY(4, 3); LCD_PUTS((char *)"I LOVE YUJIN");
    //LCD_CMD(0x18);

    if(buttonGetPressed(_DEF_BUTTON1))
    {
    	ledOn(_DEF_LED1);
    }
    else
    {
    	ledOff(_DEF_LED1);
    }

    cliMain();
  }
}
