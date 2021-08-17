/*
 * hw.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "hw.h"





void hwInit(void)
{
  bspInit();

//  cliInit();
  DWT_Delay_Init();
  ledInit();
  buttonInit();
  gpioInit();
  Ds18b20_Init();
}
