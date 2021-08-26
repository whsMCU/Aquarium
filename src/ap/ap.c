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

    Sonar_measure();

    LCD_XY(1, 1); LCD_PUTS((char *)"WTR_T : ");
    LCD_XY(8, 1); output_TEMP(ds18b20[0].Temperature*10);
    LCD_XY(13, 1); LCD_print_SC(223);
    LCD_XY(1, 2); LCD_PUTS((char *)"WTR_L : ");
    LCD_XY(9, 2); output_DISTANCE(sonar_tbl[0].filter_distance_cm);
    LCD_XY(15, 0); output_time_out(sonar_tbl[0].time_out_cnt);
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
    //lcdMain();
  }
}


void lcdMain(void)
{
  if (lcdIsInit() != true)
  {
    return;
  }


  if (lcdDrawAvailable() == true)
  {
      lcdClearBuffer(black);

      lcdPrintf(25,16*0, green, "[LCD 테스트]");

      lcdPrintf(0,16*1, white, "%d fps", lcdGetFps());
      lcdPrintf(0,16*2, white, "%d ms" , lcdGetFpsTime());
      lcdPrintf(0,16*3, white, "%d ms" , millis());

      lcdDrawFillRect( 0, 70, 10, 10, red);
      lcdDrawFillRect(10, 70, 10, 10, green);
      lcdDrawFillRect(20, 70, 10, 10, blue);

      lcdRequestDraw();
  }
}
