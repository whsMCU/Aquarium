/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"

void lcdMain(uint8_t layer);
void sensorMain(void);

void cliBoot(cli_args_t *args);

uint8_t button_status;


void apInit(void)
{
	//cliOpen(_DEF_UART1, 57600);
	uartOpen(_DEF_UART1, 57600);
	menuSetCallBack(lcdMain);
	cliAdd("boot", cliBoot);
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
    //cliMain();
    menuMain();
    SerialCom();
  }
}

void sensorMain(void)
{
    Ds18b20_ManualConvert();
    Sonar_measure();
    tds_measure();
}

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
      lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움!]");

      lcdSetFont(LCD_FONT_HAN);
      lcdPrintf(0,16*1, white, "물온도 : %3.1f 도" , ds18b20[0].Temperature);
      lcdPrintf(0,16*2, white, "물높이 : %3d cm" , sonar_tbl[0].filter_distance_cm/10);
      lcdPrintf(0,16*3, white, "TDS : %4.1f ppm" , tds_tbl[0].filter_tdsValue);
      //lcdDrawBufferImage(50, 20, 50, 50, TEST);

      blink = get_blink();
      draw_fan_status(0, 16*4, blink);

      switch(buttonMain())
      {
      	case(USER_BTN):
  				{
  					gpioPinWrite(BUZZER, true);
  				}
      	break;

      	case(MENU_BTN):
  				{
  					gpioPinWrite(Relay1, true);
  				}
      	break;

      	case(UP_BTN):
  				{
  					gpioPinWrite(Relay2, true);
  				}
      	break;

      	case(DOWN_BTN):
  				{
  					gpioPinWrite(Relay3, true);
  				}
      	break;

      	case(SEL_BTN):
  				{
  					gpioPinWrite(Relay4, true);
  				}
      	break;

      	default:
      	{
          lcdDrawRoundRect(0, 0+110,  35, 17, 5, white);
          lcdDrawFillRoundRect(1, 1+110, 33, 15, 5, red);
          lcdSetFont(LCD_FONT_07x10);
          lcdPrintf(5,5+110, white, "FAN");

          lcdDrawRoundRect(0+40, 0+110,  35, 17, 5, white);
          lcdDrawFillRoundRect(1+40, 1+110, 33, 15, 5, red);
          lcdSetFont(LCD_FONT_07x10);
          lcdPrintf(5+40,5+110, white, "PUMP");
//      		gpioPinWrite(BUZZER, false);
//      		gpioPinWrite(Relay1, false);
//      		gpioPinWrite(Relay2, false);
//      		gpioPinWrite(Relay3, false);
//      		gpioPinWrite(Relay4, false);
      	}

      }

      lcdRequestDraw();
  }

}

void cliBoot(cli_args_t *args)
{
  bool ret = false;


  if (args->argc == 1 && args->isStr(0, "info") == true)
  {
    firm_version_t *p_boot_ver = (firm_version_t *)(FLASH_ADDR_BOOT_VER);


    cliPrintf("boot ver   : %s\n", p_boot_ver->version);
    cliPrintf("boot name  : %s\n", p_boot_ver->name);
    cliPrintf("boot param : 0x%X\n", rtcBackupRegRead(0));

    ret = true;
  }

  if (args->argc == 1 && args->isStr(0, "jump_boot") == true)
  {
    resetToBoot(0);
    ret = true;
  }

  if (args->argc == 1 && args->isStr(0, "jump_fw") == true)
  {
    rtcBackupRegWrite(0, 0);
    ret = true;
  }

  if (ret != true)
  {
    cliPrintf("boot info\n");
  }
}
