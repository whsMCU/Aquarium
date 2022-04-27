/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"

void lcdMain(uint8_t layer);
void sensorMain(void);
//void buttonMain(void);


void apInit(void)
{
	cliOpen(_DEF_UART1, 57600);
	menuSetCallBack(lcdMain);
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
    //lcdMain();
    menuMain();
  }
}

void sensorMain(void)
{
    Ds18b20_ManualConvert();
    Sonar_measure();
    tds_measure();
}

//void buttonMain(void)
//{
//	if(buttonGetPressed(USER_BTN)|buttonGetPressed(MENU_BTN)|buttonGetPressed(UP_BTN)|buttonGetPressed(DOWN_BTN)|buttonGetPressed(SEL_BTN))
//	{
//		ledOn(_DEF_LED1);
//	}
//	else
//	{
//		ledOff(_DEF_LED1);
//	}
//
//	if(buttonGetPressed(SEL_BTN))
//	{
//		gpioPinWrite(BUZZER, SET);
//	}
//	else
//	{
//		gpioPinWrite(BUZZER, RESET);
//	}
//}

void lcdMain(uint8_t layer)
{
  static bool blink = 0;

  if (lcdIsInit() != true)
  {
    return;
  }


  if (lcdDrawAvailable() == true)
  {
      lcdClearBuffer(black);
      lcdSetFont(LCD_FONT_HAN);
      lcdPrintf(0,16*0, green, "[풍경채 아쿠아리움]");

      lcdDrawRoundRect(70, 16*4, 52, 17, 5, white);
      lcdDrawFillRoundRect(71, 65, 50, 15, 5, red);
      lcdSetFont(LCD_FONT_07x10);
      lcdPrintf(75,70, white, "BUTTON");

      lcdSetFont(LCD_FONT_HAN);
      lcdPrintf(0,16*1, white, "물온도 : %3.1f 도" , ds18b20[0].Temperature);
      lcdPrintf(0,16*2, white, "물높이 : %3d cm" , sonar_tbl[0].filter_distance_cm/10);
      lcdPrintf(0,16*3, white, "TDS : %4.1f ppm" , tds_tbl[0].filter_tdsValue);
      //lcdDrawBufferImage(50, 20, 50, 50, TEST);

      lcdDrawFillRect( 0, 118, 10, 10, red);
      lcdDrawFillRect(10, 118, 10, 10, green);
      lcdDrawFillRect(20, 118, 10, 10, blue);
      blink = get_blink();
      draw_fan_status(0, 16*4, blink);

      lcdRequestDraw();
  }

}
