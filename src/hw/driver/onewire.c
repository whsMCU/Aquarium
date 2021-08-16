/*
 * onewire.c
 *
 *  Created on: 2021. 8. 16.
 *      Author: WANG
 */

#include "onewire.h"
#include "user_delay.h"
#include "gpio.h"

bool onewireInit(void)
{
	bool ret = true;
	return ret;
}
bool reset(void)
{
	bool ret = false;
	gpioPinWrite(DS18B20_DATA, GPIO_PIN_RESET);
	gpioPinMode(DS18B20_DATA, _DEF_OUTPUT);

	DWT_Delay_us(500);

	gpioPinWrite(DS18B20_DATA, GPIO_PIN_SET);
	gpioPinMode(DS18B20_DATA, _DEF_INPUT);
	DWT_Delay_us(50);

	ret = gpioPinRead(DS18B20_DATA);

	DWT_Delay_us(500);

	gpioPinMode(DS18B20_DATA, _DEF_OUTPUT);

	return ret;
}
uint16_t read_byte(void)
{
	uint16_t data = 0x00;
	uint8_t i;
	for(i=0; i<8; i++)
	{
		gpioPinWrite(DS18B20_DATA, GPIO_PIN_RESET);
		DWT_Delay_us(2);

		gpioPinMode(DS18B20_DATA, _DEF_INPUT);
		DWT_Delay_us(10);

		if(gpioPinRead(DS18B20_DATA) == 0x01)
		{
			data |= 1<<i;
		}

		DWT_Delay_us(55);
		gpioPinWrite(DS18B20_DATA, GPIO_PIN_SET);
		gpioPinMode(DS18B20_DATA, _DEF_OUTPUT);
		DWT_Delay_us(2);
	}
	return data;
}
bool write_byte(char data)
{
	bool ret = false;
	uint8_t i;

	for(i=0; i<8; i++)
	{
		if(data & (1<<i))
		{
			gpioPinWrite(DS18B20_DATA, GPIO_PIN_RESET);
			DWT_Delay_us(2);
			gpioPinWrite(DS18B20_DATA, GPIO_PIN_SET);
		}
		else
		{
			gpioPinWrite(DS18B20_DATA, GPIO_PIN_RESET);
		}
		DWT_Delay_us(60);
	}
	gpioPinWrite(DS18B20_DATA, GPIO_PIN_SET);

	return ret;
}
