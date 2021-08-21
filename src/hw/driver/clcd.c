/*
 * clcd.c
 *
 *  Created on: 2021. 8. 19.
 *      Author: WANG
 */


#include "clcd.h"
#include "user_delay.h"

uint32_t Data_pin[4] = {GPIO_PIN_15, GPIO_PIN_14, GPIO_PIN_13, GPIO_PIN_12};  // MSBFIRST
// RS-B7, R/W-B9, EN-B8, D4-B12, D5-B13, D6-B14, D7-B15

char digit10000(uint16_t v) {return '0' + v / 10000;}
char digit1000(uint16_t v) {return '0' + v / 1000 - (v/10000) * 10;}
char digit100(uint16_t v) {return '0' + v / 100 - (v/1000) * 10;}
char digit10(uint16_t v) {return '0' + v / 10 - (v/100) * 10;}
char digit1(uint16_t v) {return '0' + v - (v/10) * 10;}

void EN_PULSE(void)
{
	EN_H;
	DWT_Delay_us(50);//250
	EN_L;
	DWT_Delay_us(50);
}

void write_4bit(uint8_t data)
{
	GPIOB->BSRR = 0xF0000000|((data&0x0F)<<12);
	EN_PULSE();
}

uint8_t LCD_readCMD(void) {
	//GPIOB->CRH = (GPIOB->CRH & 0x0000FFFF)|(0x44440000);
	RS_L;
    RW_H;
	EN_H;
	DWT_Delay_us(1);
	uint16_t temp_H = (GPIOB->IDR & 0xF000)>>8;
	EN_L;
	DWT_Delay_us(1);
	EN_H;
	DWT_Delay_us(1);
	uint16_t temp_L = (GPIOB->IDR & 0xF000)>>12;
	EN_L;
	RW_L;
  uint8_t temp = temp_H|temp_L;

  //GPIOB->CRH = (GPIOB->CRH & 0x0000FFFF)|(0x22220000);

	return temp;
}

void LCD_CMD(char cmd) {
  RS_L;
	//while(LCD_readCMD() == 0x80)
	write_4bit(cmd>>4);
	//while(LCD_readCMD() == 0x80)
	write_4bit(cmd);
}

void LCD_DATA(char data) {
  RS_H;
	//while(LCD_readCMD() == 0x80)
	write_4bit(data>>4);
	//while(LCD_readCMD() == 0x80)
	write_4bit(data);
}

void LCD_print(uint8_t data) {
	data += '0';
  RS_H;
	//while(LCD_readCMD() == 0x80)
	write_4bit(data>>4);
	//while(LCD_readCMD() == 0x80)
	write_4bit(data);
}

void LCD_print_SC(uint8_t data) {
  RS_H;
	//while(LCD_readCMD() == 0x80)
	write_4bit(data>>4);
	//while(LCD_readCMD() == 0x80)
	write_4bit(data);
}

void Set_Cursor(void) {
	LCD_CMD(0x0F);
}

void Clear_Cursor(void)
{
	LCD_CMD(0x0C);
}

void LCD_INIT(void)
{
   HAL_Delay(100);
   LCD_CMD(0x03); HAL_Delay(45);// 4 bits, 2 line, 5x8 font
   LCD_CMD(0x03); HAL_Delay(45);
   LCD_CMD(0x03); HAL_Delay(45);
   LCD_CMD(0x02); HAL_Delay(100);
   LCD_CMD(0x28);//4bit mode, 5x8Dot, 2Line
   LCD_CMD(0x0C);//Display on
   LCD_CMD(0x06);//font direction left
   LCD_CMD(0x01);//Display Clear
   HAL_Delay(100);
}

void LCD_XY(char x, char y) {
  if     (y==0) LCD_CMD(0x80 + x);
  else if(y==1) LCD_CMD(0xC0 + x);
  else if(y==2) LCD_CMD(0x94 + x);
  else if(y==3) LCD_CMD(0xD4 + x);
}

void LCD_CLEAR(void) { LCD_CMD(0x01); HAL_Delay(3); }

void LCD_PUTS(char *str) { while(*str) LCD_DATA(*str++); }

void LCDprintInt16(int16_t v) {
  uint16_t unit;
  char line[7]; // = "      ";
  if (v < 0 ) {
    unit = -v;
    line[0] = '-';
  } else {
    unit = v;
    line[0] = ' ';
  }
  line[1] = digit10000(unit);
  line[2] = digit1000(unit);
  line[3] = digit100(unit);
  line[4] = digit10(unit);
  line[5] = digit1(unit);
  line[6] = 0;
  LCD_PUTS(line);
}
void lcdprint_uint32(uint32_t v) {
  static char line[14] = "-.---.---.---";
  //                      0 2 4 6 8   12
  line[0]  = '0' + v  / 1000000000;
  line[2]  = '0' + v  / 100000000 - (v/1000000000) * 10;
  line[3]  = '0' + v  / 10000000  - (v/100000000)  * 10;
  line[4]  = '0' + v  / 1000000   - (v/10000000)   * 10;
  line[6]  = '0' + v  / 100000    - (v/1000000)    * 10;
  line[7]  = '0' + v  / 10000     - (v/100000)     * 10;
  line[8]  = '0' + v  / 1000      - (v/10000)      * 10;
  line[10]  = '0' + v  / 100       - (v/1000)       * 10;
  line[11] = '0' + v  / 10        - (v/100)        * 10;
  line[12] = '0' + v              - (v/10)         * 10;
  LCD_PUTS(line);
}

void output_TEMP(float temp)
{
	static char line[5] = "---.-";
    //                     01234
	if(temp < 0)
	{
		line[0] = '-';
	}else
	{
		line[0] = ' ';
	}

	line[1] = digit100(temp);
	line[2] = digit10(temp);
    line[4] = digit1(temp);
	LCD_PUTS(line);
}

void output_DISTANCE(uint16_t temp)
{
	static char line[7] = "---.-cm";
    //                     01234

	line[0] = digit1000(temp);
	line[1] = digit100(temp);
	line[2] = digit10(temp);
    line[4] = digit1(temp);
	LCD_PUTS(line);
}


