/*
 * hw_def.h
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"




#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_BUTTON
#define      HW_BUTTON_MAX_CH       1

#define _USE_HW_GPIO
#define      HW_GPIO_MAX_CH         8

#define _USE_HW_ONEWIRE
#define		 HW_ONEWIRE_MAX_CH      1

#define _USE_HW_DS18B20
#define		 HW_DS18B20_MAX_CH     			1
#define		 HW_DS18B20_GPIOX	  			GPIOB
#define      HW_DS18B20_PINX				GPIO_PIN_0
#define      HW_DS18B20_CONVERT_TIMEOUT_MS  5000

#endif /* SRC_HW_HW_DEF_H_ */
