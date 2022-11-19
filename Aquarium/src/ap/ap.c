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
  button_obj_t btn_user;
  button_obj_t btn_left;
  button_obj_t btn_right;
  button_obj_t btn_enter;
  button_obj_t btn_exit;

  bool menu_run;

  uint32_t pre_time;
} menu_t;

enum Menu_List
{
  Auto,
  Supply_Valve,
  Discharge_Valve,
  Discharge_Pump,
  Heater,
  Setting
};

enum Mode
{
  Auto_Mode,
  Manual_Mode
};

enum Setting_List
{
  Water_Temp,
  Water_Level,
  Water_Quality
};

void menuInit(void);
void menuUpdate(void);
void menuRunApp(uint8_t index);

void sensorMain(void);

void AutoMain(void);
void AutoUpdate(void);
void SettingMain(void);
void SettingUpdate(void);

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
	Mode = Manual_Mode;
	sensor.setting_cnt = 3;
	sensor.setting_index = 0;
	sensor.setting = false;
	sensor.setting_mode = false;
	sensor.ds18b20_temp_setting = 25.0;
	sensor.water_level_setting = 30;
	sensor.water_tank_height  = 50;
	sensor.water_temp_deadband = 2;
	sensor.water_level_deadband = 5;
	sensor.water_quality_setting = 10.0;
	sensor.water_quality_deadband = 5;
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
	if(sensor.sonar_distance >= 50) sensor.sonar_distance = 50;
	sensor.water_level = sensor.water_tank_height - sensor.sonar_distance;

	sensor.water_quality = tds_tbl[0].filter_tdsValue;
}

void menuInit(void)
{
  menu.menu_cnt = 6;
  menu.menu_index = 0;
  buttonObjCreate(&menu.btn_user,  0, 50, 1000, 100);
  buttonObjCreate(&menu.btn_left,   1, 50, 1000, 100);
  buttonObjCreate(&menu.btn_right,  2, 50, 1000, 100);
  buttonObjCreate(&menu.btn_enter,  3, 50, 1000, 100);
  buttonObjCreate(&menu.btn_exit,   4, 50, 1000, 100);

  //buzzerSetVolume(1);
  //menuLoadInfo();
}

void menuUpdate(void)
{
  buttonObjClearAndUpdate(&menu.btn_user);
  buttonObjClearAndUpdate(&menu.btn_left);
  buttonObjClearAndUpdate(&menu.btn_right);
  buttonObjClearAndUpdate(&menu.btn_enter);
  buttonObjClearAndUpdate(&menu.btn_exit);

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

  }

  static bool blink = 0;

  if (lcdDrawAvailable() == true)
  {
    lcdClearBuffer(black);

    lcdDrawVLine((lcdGetWidth()/2)+20, 16, (lcdGetHeight()/2), pink);
    lcdDrawHLine(0, 16*1, lcdGetWidth(), pink);
    lcdDrawHLine(0, 16*2, lcdGetWidth(), pink);
    lcdDrawHLine(0, 16*3, lcdGetWidth(), pink);
    lcdDrawHLine(0, 16*4, lcdGetWidth(), pink);
    lcdDrawHLine(0, 16*5, lcdGetWidth(), pink);

    lcdSetFont(LCD_FONT_HAN);
    lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움!]");

    lcdSetFont(LCD_FONT_HAN);
    lcdPrintf(0,16*1, white, "   현재값    세팅값");

    lcdSetFont(LCD_FONT_HAN);
    lcdPrintf(0,16*2, white, "온도: %3.1f도" , sensor.ds18b20_temp);
    lcdPrintf(0,16*3, white, "높이:%3dcm" , sensor.water_level);
    lcdPrintf(0,16*4, white, "TDS: %4.1fppm" , sensor.water_quality);

    lcdPrintf((lcdGetWidth()/2)+20,16*2, white, " %3.1f도" , sensor.ds18b20_temp_setting);
    lcdPrintf((lcdGetWidth()/2)+20,16*3, white, " %3dcm" , sensor.water_level_setting);
    lcdPrintf((lcdGetWidth()/2)+20,16*4, white, "%4.1fppm" , sensor.water_quality_setting);
    //lcdDrawBufferImage(50, 20, 50, 50, TEST);
    if(Mode == Auto_Mode)
    {
		lcdPrintf(40, 16*5, white, "MODE : AUTO");
    }else
    {
    	lcdPrintf(40, 16*5, white, "MODE : MANUAL");
    }

    blink = get_blink();
    draw_fan_status(0, 16*5, blink);

    lcdDrawRoundRect(0, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2,5+112, white, "ATO");

    lcdDrawRoundRect(0+26, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+26, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+26,5+112, white, "S_V");

	lcdDrawRoundRect(0+52, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+52, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+52,5+112, white, "D_V");

	lcdDrawRoundRect(0+78, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+78, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+78,5+112, white, "PP");

	lcdDrawRoundRect(0+104, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+104, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+104,5+110, white, "HTR");

	lcdDrawRoundRect(0+130, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+130, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+130,5+110, white, "SET");

	for (int i=0; i<menu.menu_cnt; i++)
	{
		if (menu.menu_index == Auto)
		{
			lcdDrawFillRoundRect(1, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(2,5+112, white, "ATO");
		}
		if (menu.menu_index == Supply_Valve)
		{
			lcdDrawFillRoundRect(1+26, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(2+26,5+112, white, "S_V");
		}
		if (menu.menu_index == Discharge_Valve)
		{
			lcdDrawFillRoundRect(1+52, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(2+52,5+112, white, "D_V");
		}
		if (menu.menu_index == Discharge_Pump)
		{
			lcdDrawFillRoundRect(1+78, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(5+78,5+112, white, "PP");
		}
		if (menu.menu_index == Heater)
		{
			lcdDrawFillRoundRect(1+104, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(2+104,5+110, white, "HTR");
		}
		if (menu.menu_index == Setting)
		{
			lcdDrawFillRoundRect(1+130, 1+112, 23, 14, 5, blue);
			lcdSetFont(LCD_FONT_07x10);
			lcdPrintf(2+130,5+110, white, "SET");
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
  		Mode = Auto_Mode;
  	    AutoMain();
  	    Mode = Manual_Mode;
  	  break;
    case Supply_Valve:
    	Mode = Manual_Mode;
    	gpioPinToggle(Relay1);
      break;
    case Discharge_Valve:
    	Mode = Manual_Mode;
    	gpioPinToggle(Relay2);
      break;
    case Discharge_Pump:
    	Mode = Manual_Mode;
    	gpioPinToggle(Relay3);
      break;
    case Heater:
    	Mode = Manual_Mode;
    	gpioPinToggle(Relay4);
      break;
    case Setting:
    	Mode = Manual_Mode;
    	sensor.setting_mode = true;
    	//gpioPinToggle(BUZZER);
    	SettingMain();
      break;

    default:
    	Mode = Manual_Mode;
    	is_run = false;
      break;
  }

  if (is_run == true)
  {
	buttonObjInit(&menu.btn_user);
    buttonObjInit(&menu.btn_left);
    buttonObjInit(&menu.btn_right);
    buttonObjInit(&menu.btn_enter);
    buttonObjInit(&menu.btn_exit);
  }
}

void AutoMain(void)
{
  uint32_t pre_time;
  button_obj_t btn_exit;

  buttonObjCreate(&btn_exit,  4, 50, 1000, 100);

  pre_time = millis();
  while(1)
  {
	buttonObjClearAndUpdate(&btn_exit);

    if (buttonObjGetEvent(&btn_exit) & BUTTON_EVT_CLICKED)
    {
      break;
    }
	if (millis()-pre_time >= 1000)
	{
	  pre_time = millis();

	}
	sensorMain();

	if(sensor.ds18b20_temp < sensor.ds18b20_temp_setting - sensor.water_temp_deadband)
	{
		gpioPinWrite(Relay4, true); // HTR ON
	}else if(sensor.ds18b20_temp > sensor.ds18b20_temp_setting)
	{
		gpioPinWrite(Relay4, false);  // HTR OFF
	}

	if(sensor.water_level < sensor.water_level_setting - sensor.water_level_deadband)
	{
		gpioPinWrite(Relay1, true); // Supply_VALVE Open
	}else if(sensor.water_level > sensor.water_level_setting)
	{
		gpioPinWrite(Relay1, false);  // Supply_VALVE Close
	}

	if(sensor.water_quality < sensor.water_quality_setting - sensor.water_quality_deadband)
	{
		gpioPinWrite(Relay3, false);  // PUMP OFF
		gpioPinWrite(Relay2, false);  // Discharge_VALVE Close
	}else if(sensor.water_quality > sensor.water_quality_setting)
	{
		gpioPinWrite(Relay3, true); // PUMP ON
		gpioPinWrite(Relay2, true);  // Discharge_VALVE Open
	}
	AutoUpdate();
	SerialCom();
  }
  gpioPinWrite(Relay1, false);
  gpioPinWrite(Relay2, false);
  gpioPinWrite(Relay3, false);
  gpioPinWrite(Relay4, false);

}

void AutoUpdate(void)
{
  static bool blink = 0;

  if (lcdDrawAvailable() == true)
  {
	lcdClearBuffer(black);

	lcdDrawVLine((lcdGetWidth()/2)+20, 16, (lcdGetHeight()/2), pink);
	lcdDrawHLine(0, 16*1, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*2, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*3, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*4, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*5, lcdGetWidth(), pink);

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움!]");

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*1, white, "   현재값    세팅값");

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*2, white, "온도: %3.1f도" , sensor.ds18b20_temp);
	lcdPrintf(0,16*3, white, "높이:%3dcm" , sensor.water_level);
	lcdPrintf(0,16*4, white, "TDS: %4.1fppm" , sensor.water_quality);

	lcdPrintf((lcdGetWidth()/2)+20,16*2, white, " %3.1f도" , sensor.ds18b20_temp_setting);
	lcdPrintf((lcdGetWidth()/2)+20,16*3, white, " %3dcm" , sensor.water_level_setting);
	lcdPrintf((lcdGetWidth()/2)+20,16*4, white, "%4.1fppm" , sensor.water_quality_setting);
	//lcdDrawBufferImage(50, 20, 50, 50, TEST);
	if(Mode == Auto_Mode)
	{
		lcdPrintf(40, 16*5, white, "MODE : AUTO");
	}else
	{
		lcdPrintf(40, 16*5, white, "MODE : MANUAL");
	}

	blink = get_blink();
	draw_fan_status(0, 16*5, blink);

	lcdDrawRoundRect(0, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2,5+112, white, "ATO");

	lcdDrawRoundRect(0+26, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+26, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+26,5+112, white, "S_V");

	lcdDrawRoundRect(0+52, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+52, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+52,5+112, white, "D_V");

	lcdDrawRoundRect(0+78, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+78, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+78,5+112, white, "PP");

	lcdDrawRoundRect(0+104, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+104, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+104,5+110, white, "HTR");

	lcdDrawRoundRect(0+130, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+130, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+130,5+110, white, "SET");

	lcdRequestDraw();
	}
}

void SettingMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
	if (sensor.setting_mode == false)
	{
	  break;
	}
	if (millis()-pre_time >= 1000)
	{
	  pre_time = millis();

	}
	sensorMain();
	SettingUpdate();
	SerialCom();
  }
}

void SettingUpdate(void)
{
  buttonObjClearAndUpdate(&menu.btn_left);
  buttonObjClearAndUpdate(&menu.btn_right);
  buttonObjClearAndUpdate(&menu.btn_enter);
  buttonObjClearAndUpdate(&menu.btn_exit);

  if (buttonObjGetEvent(&menu.btn_left) & BUTTON_EVT_CLICKED)
  	  {
  		  if (sensor.setting != true)
  		  {
  			if (sensor.setting_index > 0)
  			{
  				sensor.setting_index--;
  			}
  			else
  			{
  				sensor.setting_index = sensor.setting_cnt - 1;
  			}
  		  }else
  		  {
  			  if (sensor.setting_index == Water_Temp)
  			  {
  				  sensor.ds18b20_temp_setting -= 1;
  			  }
  			  if (sensor.setting_index == Water_Level)
  			  {
  				  sensor.water_level_setting -= 1;
  			  }
  			  if (sensor.setting_index == Water_Quality)
  			  {
  				  sensor.water_quality_setting -= 1;
  			  }
  		  }
  	  }
  	  if (buttonObjGetEvent(&menu.btn_right) & BUTTON_EVT_CLICKED)
  	  {
  		  if (sensor.setting != true)
  		  {
  			sensor.setting_index++;
  			sensor.setting_index %= sensor.setting_cnt;
  		  }else
  		  {
  			  if (sensor.setting_index == Water_Temp)
  			  {
  				  sensor.ds18b20_temp_setting += 1;
  			  }
  			  if (sensor.setting_index == Water_Level)
  			  {
  				  sensor.water_level_setting += 1;
  			  }
  			  if (sensor.setting_index == Water_Quality)
  			  {
  				  sensor.water_quality_setting += 1;
  			  }
  		  }
  	  }
  	  if (buttonObjGetEvent(&menu.btn_enter) & BUTTON_EVT_CLICKED)
  	  {
  		sensor.setting = !sensor.setting;
  	  }
  	  if (buttonObjGetEvent(&menu.btn_exit) & BUTTON_EVT_CLICKED)
  	  {
  		sensor.setting = false;
  		sensor.setting_mode = false;
  	  }

  static bool blink = 0;

  if (lcdDrawAvailable() == true)
  {
	lcdClearBuffer(black);

	lcdDrawVLine((lcdGetWidth()/2)+20, 16, (lcdGetHeight()/2), pink);
	lcdDrawHLine(0, 16*1, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*2, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*3, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*4, lcdGetWidth(), pink);
	lcdDrawHLine(0, 16*5, lcdGetWidth(), pink);

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*0, green, "[삼둥이 아쿠아리움!]");

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*1, white, "   현재값    세팅값");

	lcdSetFont(LCD_FONT_HAN);
	lcdPrintf(0,16*2, white, "온도: %3.1f도" , sensor.ds18b20_temp);
	lcdPrintf(0,16*3, white, "높이:%3dcm" , sensor.water_level);
	lcdPrintf(0,16*4, white, "TDS: %4.1fppm" , sensor.water_quality);

	lcdPrintf((lcdGetWidth()/2)+20,16*2, white, " %3.1f도" , sensor.ds18b20_temp_setting);
	lcdPrintf((lcdGetWidth()/2)+20,16*3, white, " %3dcm" , sensor.water_level_setting);
	lcdPrintf((lcdGetWidth()/2)+20,16*4, white, "%4.1fppm" , sensor.water_quality_setting);
	//lcdDrawBufferImage(50, 20, 50, 50, TEST);
	if(Mode == Auto_Mode)
	{
		lcdPrintf(40, 16*5, white, "MODE : AUTO");
	}else
	{
		lcdPrintf(40, 16*5, white, "MODE : Manual");
	}

	blink = get_blink();
	draw_fan_status(0, 16*5, blink);

	lcdDrawRoundRect(0, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2,5+112, white, "ATO");

	lcdDrawRoundRect(0+26, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+26, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+26,5+112, white, "S_V");

	lcdDrawRoundRect(0+52, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+52, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+52,5+112, white, "D_V");

	lcdDrawRoundRect(0+78, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+78, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(5+78,5+112, white, "PP");

	lcdDrawRoundRect(0+104, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+104, 1+112, 23, 14, 5, red);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+104,5+110, white, "HTR");

	lcdDrawRoundRect(0+130, 0+112,  25, 16, 5, white);
	lcdDrawFillRoundRect(1+130, 1+112, 23, 14, 5, blue);
	lcdSetFont(LCD_FONT_07x10);
	lcdPrintf(2+130,5+110, white, "SET");

	for (int i=0; i<sensor.setting_cnt; i++)
	{
		if (sensor.setting_index == Water_Temp)
		{
			lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*2)+1, 60, 15, 5, blue);
			if(sensor.setting == true)
			{
				lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*2)+1, 60, 15, 5, red);
			}
			lcdSetFont(LCD_FONT_HAN);
			lcdPrintf((lcdGetWidth()/2)+20,16*2, white, " %3.1f도" , sensor.ds18b20_temp_setting);
		}
		if (sensor.setting_index == Water_Level)
		{
			lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*3)+1, 60, 15, 5, blue);
			if(sensor.setting == true)
			{
				lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*3)+1, 60, 15, 5, red);
			}
			lcdSetFont(LCD_FONT_HAN);
			lcdPrintf((lcdGetWidth()/2)+20,16*3, white, " %3dcm" , sensor.water_level_setting);
		}
		if (sensor.setting_index == Water_Quality)
		{
			lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*4)+1, 60, 15, 5, blue);
			if(sensor.setting == true)
			{
				lcdDrawFillRoundRect((lcdGetWidth()/2)+20, (16*4)+1, 60, 15, 5, red);
			}
			lcdSetFont(LCD_FONT_HAN);
			lcdPrintf((lcdGetWidth()/2)+20,16*4, white, "%4.1fppm" , sensor.water_quality_setting);
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
