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
  ledInit();
  buttonInit();
  gpioInit();
}
