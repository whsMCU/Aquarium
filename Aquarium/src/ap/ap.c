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

  uint32_t pre_time;
} menu_t;

enum Menu_List
{
  Light,
  Fan,
  Pump,
  Heater,
  Setting
};

void menuInit(void);
void menuUpdate(void);
void menuRunApp(uint8_t index);

void sensorMain(void);

void cliBoot(cli_args_t *args);

uint8_t button_status;

menu_t menu;

void apInit(void)
{
	//cliOpen(_DEF_UART1, 57600);
	uartOpen(_DEF_UART1, 57600);
	//menuSetCallBack(lcdMain);
	cliAdd("boot", cliBoot);
	menuInit();
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
}

void menuInit(void)
{
  menu.menu_cnt = 5;
  menu.menu_index = 0;
  buttonObjCreate(&menu.btn_reset,  0, 50, 1000, 100);
  buttonObjCreate(&menu.btn_left,   1, 50, 1000, 100);
  buttonObjCreate(&menu.btn_right,  2, 50, 1000, 100);
  buttonObjCreate(&menu.btn_enter,  3, 50, 1000, 100);
  buttonObjCreate(&menu.btn_exit, 4, 50, 1000, 100);

//  menu.img[0] = lcdCreateImage(&menu_img,  0, 0, 64, 80);
//  menu.img[1] = lcdCreateImage(&menu_img, 64, 0, 64, 80);
//  menu.img[2] = lcdCreateImage(&menu_img,128, 0, 64, 80);

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


  if (buttonObjGetEvent(&menu.btn_left) & BUTTON_EVT_CLICKED)
  {
    //buzzerBeep(50);
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
    //buzzerBeep(50);
    menu.menu_index++;
    menu.menu_index %= menu.menu_cnt;

    menu.pre_time = millis();
  }

  if (buttonObjGetEvent(&menu.btn_enter) & BUTTON_EVT_CLICKED)
  {
    //buzzerBeep(50);
    menuRunApp(menu.menu_index);
  }

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

	lcdDrawRoundRect(0, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5,5+110, white, "FAN");

	lcdDrawRoundRect(0+40, 0+110,  35, 17, 5, white);
	lcdDrawFillRoundRect(1+40, 1+110, 33, 15, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+40,5+110, white, "PUMP");

	for (int i=0; i<menu.menu_cnt; i++)
	{
	  if (menu.menu_index == Fan)
	  {
		lcdDrawFillRoundRect(1, 1+110, 33, 15, 5, blue);
	  }
	  if (menu.menu_index == Pump)
	  {
		lcdDrawFillRoundRect(1+40, 1+110, 33, 15, 5, blue);
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
    	//settingMain();
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
