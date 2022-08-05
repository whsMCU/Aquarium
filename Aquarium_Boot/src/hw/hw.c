/*
 * hw.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "hw.h"


__attribute__((section(".version"))) firm_version_t boot_ver =
    {
        "B210211R1",
        "Bootloader"
    };



void hwInit(void)
{
  bspInit();

  DWT_Delay_Init();

  rtcInit();
  resetInit();
  cliInit();
  ledInit();
  uartInit();
  buttonInit();
  flashInit();
  ymodemInit();
}
