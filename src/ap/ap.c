/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"

extern ADC_HandleTypeDef hadc1;

void lcdMain(void);



void apInit(void)
{
	cliOpen(_DEF_UART1, 57600);
	//HAL_ADC_Start_DMA(&hadc1, &tds_tbl[0].rawdata, 1);
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
    //Ds18b20_ManualConvert();

    Sonar_measure();

    if(buttonGetPressed(_DEF_BUTTON1))
    {
    	ledOn(_DEF_LED1);
    }
    else
    {
    	ledOff(_DEF_LED1);
    }
    cliMain();
    lcdMain();
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
      lcdSetFont(LCD_FONT_HAN);
      lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움]");

      lcdPrintf(0,16*1, white, "%d fps", lcdGetFps());
      lcdPrintf(0,16*2, white, "%d ms" , lcdGetFpsTime());
      lcdPrintf(0,16*3, white, "%d ms" , millis());

      lcdPrintf(0,16*4, white, "물온도 : %3d 도" , (int32_t) ds18b20[0].Temperature);
      lcdPrintf(0,16*5, white, "물높이 : %3d cm" , sonar_tbl[0].filter_distance_cm/10);
      lcdPrintf(0,16*6, white, "TDS : %4d ppm" , tds_tbl[0].rawdata);

      lcdDrawFillRect( 0, 116, 10, 10, red);
      lcdDrawFillRect(10, 116, 10, 10, green);
      lcdDrawFillRect(20, 116, 10, 10, blue);

      lcdRequestDraw();
  }
}
