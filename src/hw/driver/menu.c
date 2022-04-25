/*
 * munu.c
 *
 *  Created on: 2022. 4. 14.
 *      Author: 왕학승
 */


#include "menu.h"
#include "button.h"
#include "lcd.h"

#ifdef _USE_HW_MENU

#define MENU_NAME_MAX 256
#define MENU_LIST_MAX 32


typedef struct
{
	char menu_str[MENU_NAME_MAX];
	void (*menu_func)(menu_args_t *);
} menu_func_t;

typedef struct
{
	uint8_t node;
	uint8_t main;
	uint8_t layer;
	uint8_t menu_count;
	menu_func_t menu_list[MENU_LIST_MAX];
	menu_args_t menu_args;
	void (*callback)(void);
} menu_t;

menu_t menu_node;

static bool menuUpdate(menu_t *p_cli);
static void menu_strToUpper(char *str);

static int32_t  menuArgsGetData(uint8_t index);
static float    menuArgsGetFloat(uint8_t index);
static char    *menuArgsGetStr(uint8_t index);
static bool     menuArgsIsStr(uint8_t index, char *p_str);

void menu_manual(menu_args_t *args);

void menuSetCallBack(void (*callback)(void))
{
	menu_node.callback = callback;
}

bool menuInit(void)
{
	menu_node.node = 1;
	menu_node.main = 0;
	menu_node.layer = 0;
	menu_node.menu_count = 0;
	menu_node.menu_args.getData  = menuArgsGetData;
	menu_node.menu_args.getFloat = menuArgsGetFloat;
	menu_node.menu_args.getStr   = menuArgsGetStr;
	menu_node.menu_args.isStr    = menuArgsIsStr;

	menu_node.callback = NULL;

	menuAdd("manual", 0, menu_manual);

	return true;
}

bool menuMain(void)
{
  if (menu_node.node == 0)
  {
    return false;
  }

  if (menu_node.node >= 1)
  {
    menuUpdate(&menu_node);
  }

  return true;
}

bool menuUpdate(menu_t *p_menu)
{
  bool ret = false;

  if(p_menu->callback != NULL)
  {
	  (*p_menu->callback)();
  }

  return ret;
}

void menu_strToUpper(char *str)
{
  uint16_t i;
  uint8_t  str_ch;

  for (i=0; i<MENU_NAME_MAX; i++)
  {
    str_ch = str[i];

    if (str_ch == 0)
    {
      break;
    }

    if ((str_ch >= 'a') && (str_ch <= 'z'))
    {
      str_ch = str_ch - 'a' + 'A';
    }
    str[i] = str_ch;
  }

  if (i == MENU_NAME_MAX)
  {
    str[i-1] = 0;
  }
}


int32_t menuArgsGetData(uint8_t index)
{
  int32_t ret = 0;
  menu_t *p_menu = &menu_node;


  if (index >= p_menu->menu_args.argc)
  {
    return 0;
  }

  ret = (int32_t)strtoul((const char * ) p_menu->menu_args.argv[index], (char **)NULL, (int) 0);

  return ret;
}

float menuArgsGetFloat(uint8_t index)
{
  float ret = 0.0;
  menu_t *p_menu = &menu_node;


  if (index >= p_menu->menu_args.argc)
  {
    return 0;
  }

  ret = (float)strtof((const char * ) p_menu->menu_args.argv[index], (char **)NULL);

  return ret;
}

char *menuArgsGetStr(uint8_t index)
{
  char *ret = NULL;
  menu_t *p_menu = &menu_node;


  if (index >= p_menu->menu_args.argc)
  {
    return 0;
  }

  ret = p_menu->menu_args.argv[index];

  return ret;
}

bool menuArgsIsStr(uint8_t index, char *p_str)
{
  bool ret = false;
  menu_t *p_menu = &menu_node;


  if (index >= p_menu->menu_args.argc)
  {
    return 0;
  }

  if(strcmp(p_str, p_menu->menu_args.argv[index]) == 0)
  {
    ret = true;
  }

  return ret;
}

bool menuAdd(const char *menu_str, uint8_t layer, void (*p_func)(menu_args_t *))
{
  bool ret = true;
  menu_t *p_menu = &menu_node;
  uint16_t index;

  if (p_menu->menu_count >= MENU_LIST_MAX)
  {
    return false;
  }

  index = p_menu->menu_count;
  p_menu->layer = layer;

  strcpy(p_menu->menu_list[index].menu_str, menu_str);
  p_menu->menu_list[index].menu_func = p_func;

  menu_strToUpper(p_menu->menu_list[index].menu_str);

  p_menu->menu_count++;

  return ret;
}

void menu_manual(menu_args_t *args)
{
	menu_t *p_menu = &menu_node;

}



#endif
