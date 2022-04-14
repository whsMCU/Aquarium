/*
 * gpio.c
 *
 *  Created on: 2021. 8. 14.
 *      Author: WANG
 */


#include "gpio.h"
#include "cli.h"


typedef struct
{
  GPIO_TypeDef *port;
  uint32_t      pin;
  uint8_t       mode;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
  bool          init_value;
} gpio_tbl_t;


const gpio_tbl_t gpio_tbl[GPIO_MAX_CH] =
    {
        {GPIOB, GPIO_PIN_9,  _DEF_INPUT_PULLUP, GPIO_PIN_RESET, GPIO_PIN_SET,   true},       // 0. SD CD
        {GPIOA, GPIO_PIN_2,  _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, _DEF_LOW},   // 1. LCD BKL
        {GPIOA, GPIO_PIN_3,  _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, _DEF_HIGH},  // 2. LCD CS
        {GPIOA, GPIO_PIN_4,  _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, _DEF_HIGH},  // 3. LCD DC
        {GPIOA, GPIO_PIN_15, _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, _DEF_HIGH},  // 4. MCP2515 CS
        {GPIOB, GPIO_PIN_2,  _DEF_INPUT_PULLUP, GPIO_PIN_RESET, GPIO_PIN_SET,   true},       // 5. MCP2515 INT
		{GPIOB, GPIO_PIN_0,	 _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, false},		 // 6. DS18B20 DATA
		{GPIOB, GPIO_PIN_1,  _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, false},		 // 7. SONAR_PIN
		{GPIOB, GPIO_PIN_14, _DEF_OUTPUT,       GPIO_PIN_SET,   GPIO_PIN_RESET, false},		 // 8. BUZZER
		{GPIOB, GPIO_PIN_3, _DEF_OUTPUT_PULLDOWN,       GPIO_PIN_RESET,   GPIO_PIN_SET, false},		 // 9. Relay1
		{GPIOB, GPIO_PIN_4, _DEF_OUTPUT_PULLDOWN,       GPIO_PIN_RESET,   GPIO_PIN_SET, false},		 // 10. Relay2
		{GPIOA, GPIO_PIN_11, _DEF_OUTPUT_PULLDOWN,       GPIO_PIN_RESET,   GPIO_PIN_SET, false},		 // 11. Relay3
		{GPIOA, GPIO_PIN_12, _DEF_OUTPUT_PULLDOWN,       GPIO_PIN_RESET,   GPIO_PIN_SET, false},		 // 12. Relay4
    };


#ifdef _USE_HW_CLI
static void cliGpio(cli_args_t *args);
#endif



bool gpioInit(void)
{
  bool ret = true;


  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  for (int i=0; i<GPIO_MAX_CH; i++)
  {
    gpioPinMode(i, gpio_tbl[i].mode);
    gpioPinWrite(i, gpio_tbl[i].init_value);
  }

#ifdef _USE_HW_CLI
  cliAdd("gpio", cliGpio);
#endif

  return ret;
}

bool gpioPinMode(uint8_t ch, uint8_t mode)
{
  bool ret = true;
  GPIO_InitTypeDef GPIO_InitStruct = {0};


  if (ch >= GPIO_MAX_CH)
  {
    return false;
  }

  switch(mode)
  {
    case _DEF_INPUT:
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      break;

    case _DEF_INPUT_PULLUP:
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      break;

    case _DEF_INPUT_PULLDOWN:
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      break;

    case _DEF_OUTPUT:
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      break;

    case _DEF_OUTPUT_PULLUP:
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      break;

    case _DEF_OUTPUT_PULLDOWN:
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      break;

    case _DEF_INPUT_AF_PP:
      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
      break;
  }

  GPIO_InitStruct.Pin = gpio_tbl[ch].pin;
  HAL_GPIO_Init(gpio_tbl[ch].port, &GPIO_InitStruct);

  return ret;
}

void gpioPinWrite(uint8_t ch, bool value)
{
  if (ch >= GPIO_MAX_CH)
  {
    return;
  }

  if (value)
  {
    HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].on_state);
  }
  else
  {
    HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].off_state);
  }
}

bool gpioPinRead(uint8_t ch)
{
  bool ret = false;

  if (ch >= GPIO_MAX_CH)
  {
    return false;
  }

  if (HAL_GPIO_ReadPin(gpio_tbl[ch].port, gpio_tbl[ch].pin) == gpio_tbl[ch].on_state)
  {
    ret = true;
  }

  return ret;
}

void gpioPinToggle(uint8_t ch)
{
  if (ch >= GPIO_MAX_CH)
  {
    return;
  }

  HAL_GPIO_TogglePin(gpio_tbl[ch].port, gpio_tbl[ch].pin);
}





#ifdef _USE_HW_CLI
void cliGpio(cli_args_t *args)
{
  bool ret = false;


  if (args->argc == 1 && args->isStr(0, "show") == true)
  {
    while(cliKeepLoop())
    {
      for (int i=0; i<GPIO_MAX_CH; i++)
      {
        cliPrintf("%d", gpioPinRead(i));
      }
      cliPrintf("\n");
      delay(100);
    }
    ret = true;
  }

  if (args->argc == 2 && args->isStr(0, "read") == true)
  {
    uint8_t ch;

    ch = (uint8_t)args->getData(1);

    while(cliKeepLoop())
    {
      cliPrintf("gpio read %d : %d\n", ch, gpioPinRead(ch));
      delay(100);
    }

    ret = true;
  }

  if (args->argc == 3 && args->isStr(0, "write") == true)
  {
    uint8_t ch;
    uint8_t data;

    ch   = (uint8_t)args->getData(1);
    data = (uint8_t)args->getData(2);

    gpioPinWrite(ch, data);

    cliPrintf("gpio write %d : %d\n", ch, data);
    ret = true;
  }

  if (ret != true)
  {
    cliPrintf("gpio show\n");
    cliPrintf("gpio read ch[0~%d]\n", GPIO_MAX_CH-1);
    cliPrintf("gpio write ch[0~%d] 0:1\n", GPIO_MAX_CH-1);
  }
}
#endif
