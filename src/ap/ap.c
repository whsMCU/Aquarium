/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"

void lcdMain(void);
void sensorMain(void);
void buttonMain(void);

void apInit(void)
{
	cliOpen(_DEF_UART1, 57600);
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

    sensorMain();
    buttonMain();

    cliMain();
    lcdMain();
  }
}

void sensorMain(void)
{
    Ds18b20_ManualConvert();
    Sonar_measure();
    tds_measure();
}

void buttonMain(void)
{
	if(buttonGetPressed(USER_BTN)|buttonGetPressed(MENU_BTN)|buttonGetPressed(UP_BTN)|buttonGetPressed(DOWN_BTN)|buttonGetPressed(SEL_BTN))
	{
		ledOn(_DEF_LED1);
	}
	else
	{
		ledOff(_DEF_LED1);
	}

	if(buttonGetPressed(SEL_BTN))
	{
		gpioPinWrite(BUZZER, SET);
	}
	else
	{
		gpioPinWrite(BUZZER, RESET);
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

      lcdDrawRoundRect(70, 16*1, 52, 17, 5, white);
      lcdDrawFillRoundRect(71, 17, 50, 15, 5, red);
      lcdSetFont(LCD_FONT_07x10);
      lcdPrintf(75,21, white, "BUTTON");

      lcdSetFont(LCD_FONT_HAN);
      lcdPrintf(0,16*4, white, "물온도 : %3.1f 도" , ds18b20[0].Temperature);
      lcdPrintf(0,16*5, white, "물높이 : %3d cm" , sonar_tbl[0].filter_distance_cm/10);
      lcdPrintf(0,16*6, white, "TDS : %4.1f ppm" , tds_tbl[0].filter_tdsValue);

      lcdDrawFillRect( 0, 118, 10, 10, red);
      lcdDrawFillRect(10, 118, 10, 10, green);
      lcdDrawFillRect(20, 118, 10, 10, blue);

      lcdRequestDraw();
  }
}
