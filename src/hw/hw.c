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

  cliInit();
  ledInit();
  uartInit();
  spiInit();
  DWT_Delay_Init();
  buttonInit();
  gpioInit();
  Ds18b20_Init();
  sonarInit();
  LCD_INIT();
  lcdInit();
}
