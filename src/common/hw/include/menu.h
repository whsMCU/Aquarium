/*
 * menu.h
 *
 *  Created on: 2022. 4. 14.
 *      Author: 왕학승
 */

#ifndef SRC_COMMON_HW_INCLUDE_MENU_H_
#define SRC_COMMON_HW_INCLUDE_MENU_H_

#include "hw_def.h"

#ifdef _USE_HW_MENU

typedef struct
{
  uint16_t   argc;
  char     **argv;

  int32_t  (*getData)(uint8_t index);
  float    (*getFloat)(uint8_t index);
  char    *(*getStr)(uint8_t index);
  bool     (*isStr)(uint8_t index, char *p_str);
} menu_args_t;

bool menuInit(void);
bool menuMain(void);
bool menuAdd(const char *menu_str, uint8_t layer, void (*p_func)(menu_args_t *));
void menuSetCallBack(void (*callback)(void));

#endif

#endif /* SRC_COMMON_HW_INCLUDE_MENU_H_ */
