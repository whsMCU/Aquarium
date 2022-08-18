/*
 * hw.c
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */


#include "hw.h"


extern uint32_t _flash_tag_addr;
extern uint32_t __isr_vector_addr;


__attribute__((section(".tag"))) firm_tag_t firm_tag =
    {
        .magic_number = 0xAAAA5555,

        //-- fw info
        //
        .addr_tag = (uint32_t)&_flash_tag_addr,
        .addr_fw  = (uint32_t)&__isr_vector_addr,
        .size_tag = 1024,


        //-- tag info
        //
    };


__attribute__((section(".version"))) firm_version_t firm_ver =
    {
        "V220810R2",
        "Firmware"
    };


void hwInit(void)
{
  bspInit();

  rtcInit();
  resetInit();
  cliInit();
  ledInit();
  uartInit();
  spiInit();
  DWT_Delay_Init();
  buttonInit();
  gpioInit();
  flashInit();
  Ds18b20_Init();
  sonarInit();

  //LCD_INIT();
  lcdInit();
  tdsInit();

  if (sdInit() == true)
  {
    fatfsInit();
  }

  //menuInit();
}
