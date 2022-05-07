/*
 * button.h
 *
 *  Created on: 2021. 8. 14.
 *      Author: WANG
 */

#ifndef SRC_COMMON_HW_INCLUDE_BUTTON_H_
#define SRC_COMMON_HW_INCLUDE_BUTTON_H_

#include "hw_def.h"


#ifdef _USE_HW_BUTTON

#define BUTTON_MAX_CH         HW_BUTTON_MAX_CH

enum
{
	USER_BTN = 0b00000001,
	MENU_BTN = 0b00000010,
	UP_BTN   = 0b00000100,
	DOWN_BTN = 0b00001000,
	SEL_BTN  = 0b00010000,
};




bool buttonInit(void);
bool buttonGetPressed(uint8_t ch);
uint8_t buttonMain(void);


#endif

#endif /* SRC_COMMON_HW_INCLUDE_BUTTON_H_ */
