/*
 * ap.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "ap.h"

typedef struct
{
  //image_t img[3];
  uint8_t menu_cnt;
  uint8_t menu_index;
  button_obj_t btn_reset;
  button_obj_t btn_left;
  button_obj_t btn_right;
  button_obj_t btn_enter;
  button_obj_t btn_exit;

  bool menu_run;

  uint32_t pre_time;
} menu_t;

typedef struct
{
  float ds18b20_temp;
  uint32_t sonar_distance;
  float tds_quality;
  float ds18b20_temp_setting;
  uint32_t sonar_distance_setting;
  float tds_quality_setting;
} sensor_t;

enum Menu_List
{
  Auto,
  Light,
  Fan,
  Pump,
  Heater,
  Setting
};

enum Mode
{
  Auto_Mode,
  Menual_Mode
};

void menuInit(void);
void menuUpdate(void);
void menuRunApp(uint8_t index);

void sensorMain(void);

void AutoMain(void);
void SettingMain(void);

void cliBoot(cli_args_t *args);

bool Mode;

menu_t menu;
sensor_t sensor;

void apInit(void)
{
	//cliOpen(_DEF_UART1, 57600);
	uartOpen(_DEF_UART1, 57600);
	//menuSetCallBack(lcdMain);
	cliAdd("boot", cliBoot);
	menuInit();
	Mode = Menual_Mode;
	sensor.ds18b20_temp_setting = 25.0;
	sensor.sonar_distance_setting = 30;
	sensor.tds_quality_setting = 10.0;
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
    menuUpdate();
    SerialCom();
  }
}

void sensorMain(void)
{
    Ds18b20_ManualConvert();
    Sonar_measure();
    tds_measure();
    sensor.ds18b20_temp = ds18b20[0].Temperature;
	sensor.sonar_distance = sonar_tbl[0].filter_distance_cm/10;
	sensor.tds_quality = tds_tbl[0].filter_tdsValue;
}

void menuInit(void)
{
  menu.menu_cnt = 6;
  menu.menu_index = 0;
  menu.menu_run = false;
  buttonObjCreate(&menu.btn_reset,  0, 50, 1000, 100);
  buttonObjCreate(&menu.btn_left,   1, 50, 1000, 100);
  buttonObjCreate(&menu.btn_right,  2, 50, 1000, 100);
  buttonObjCreate(&menu.btn_enter,  3, 50, 1000, 100);
  buttonObjCreate(&menu.btn_exit,   4, 50, 1000, 100);

  //buzzerSetVolume(1);
  //menuLoadInfo();
}

void menuUpdate(void)
{
  buttonObjClearAndUpdate(&menu.btn_reset);
  buttonObjClearAndUpdate(&menu.btn_left);
  buttonObjClearAndUpdate(&menu.btn_right);
  buttonObjClearAndUpdate(&menu.btn_enter);
  buttonObjClearAndUpdate(&menu.btn_exit);

  if(menu.menu_run == false)
  {
	  if (buttonObjGetEvent(&menu.btn_enter) & BUTTON_EVT_CLICKED)
	  {
		menu.menu_run = true;
	  }
  }

  static bool blink = 0;

  if (lcdDrawAvailable() == true)
  {
    lcdClearBuffer(black);
    lcdSetFont(LCD_FONT_HAN);
    lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움!]");

    lcdSetFont(LCD_FONT_HAN);
    lcdPrintf(0,16*1, white, "물온도 : %3.1f 도" , sensor.ds18b20_temp);
    lcdPrintf(0,16*2, white, "물높이 : %3d cm" , sensor.sonar_distance);
    lcdPrintf(0,16*3, white, "TDS : %4.1f ppm" , sensor.tds_quality);
    //lcdDrawBufferImage(50, 20, 50, 50, TEST);

    blink = get_blink();
    draw_fan_status(0, 16*4, blink);

    lcdDrawRoundRect(0, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2,5+110, white, "Light");

	lcdDrawRoundRect(0+40, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1+40, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+40,5+110, white, "FAN");

	lcdDrawRoundRect(0+80, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1+80, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+80,5+110, white, "PUMP");

	lcdDrawRoundRect(0+120, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1+120, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+120,5+110, white, "HTR");

	if(menu.menu_run == true)
	{
	  if (buttonObjGetEvent(&menu.btn_left) & BUTTON_EVT_CLICKED)
	  {
		if (menu.menu_index > 0)
		{
		  menu.menu_index--;
		}
		else
		{
		  menu.menu_index = menu.menu_cnt - 1;
		}
		menu.pre_time = millis();
	  }
	  if (buttonObjGetEvent(&menu.btn_right) & BUTTON_EVT_CLICKED)
	  {
		menu.menu_index++;
		menu.menu_index %= menu.menu_cnt;

		menu.pre_time = millis();
	  }
	  if (buttonObjGetEvent(&menu.btn_enter) & BUTTON_EVT_CLICKED)
	  {
		menuRunApp(menu.menu_index);
	  }
	  if (buttonObjGetEvent(&menu.btn_exit) & BUTTON_EVT_CLICKED)
	  {
		menu.menu_run = false;
	  }
		for (int i=0; i<menu.menu_cnt; i++)
		{
			if (menu.menu_index == Light)
			{
				lcdDrawFillRoundRect(1, 1+110, 33, 15, 5, blue);
				lcdSetFont(LCD_FONT_07x10);
				lcdPrintf(2,5+110, white, "Light");
			}
			if (menu.menu_index == Fan)
			{
				lcdDrawFillRoundRect(1+40, 1+110, 33, 15, 5, blue);
				lcdSetFont(LCD_FONT_07x10);
				lcdPrintf(5+40,5+110, white, "FAN");
			}
			if (menu.menu_index == Pump)
			{
				lcdDrawFillRoundRect(1+80, 1+110, 33, 15, 5, blue);
				lcdSetFont(LCD_FONT_07x10);
				lcdPrintf(5+80,5+110, white, "PUMP");
			}
			if (menu.menu_index == Heater)
			{
				lcdDrawFillRoundRect(1+120, 1+110, 33, 15, 5, blue);
				lcdSetFont(LCD_FONT_07x10);
				lcdPrintf(5+120,5+110, white, "HTR");
			}
		}

	}
	lcdRequestDraw();
	}
}

void menuRunApp(uint8_t index)
{
  bool is_run = true;

  switch(index)
  {
  	case Auto:
  	    AutoMain();
  	  break;
    case Light:
    	gpioPinToggle(Relay1);
      break;
    case Fan:
    	gpioPinToggle(Relay2);
      break;
    case Pump:
    	gpioPinToggle(Relay3);
      break;
    case Heater:
    	gpioPinToggle(Relay4);
      break;
    case Setting:
    	gpioPinToggle(BUZZER);
    	SettingMain();
      break;

    default:
      is_run = false;
      break;
  }

  if (is_run == true)
  {
	buttonObjInit(&menu.btn_reset);
    buttonObjInit(&menu.btn_left);
    buttonObjInit(&menu.btn_right);
    buttonObjInit(&menu.btn_enter);
    buttonObjInit(&menu.btn_exit);
  }
}

void AutoMain(void)
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
	menuUpdate();
	SerialCom();
  }

}

void SettingMain(void)
{

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
