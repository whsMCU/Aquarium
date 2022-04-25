/*
 * button.c
 *
 *  Created on: 2021. 8. 14.
 *      Author: WANG
 */


#include "button.h"
#include "cli.h"


enum
{
	BUTTON_IDLE,
	BUTTON_Pressed,
	BUTTON_LONG_Pressed,
};

typedef struct
{
  GPIO_TypeDef *port;
  uint32_t      pin;
  uint32_t		pull;
  GPIO_PinState on_state;
  GPIO_PinState PinState;
  uint8_t		State;
  uint32_t 		debounceDelay;
  uint32_t		lastDebounceTime;
} button_tbl_t;


button_tbl_t button_tbl[BUTTON_MAX_CH] =
    {
        {GPIOA, GPIO_PIN_0, GPIO_PULLUP, GPIO_PIN_RESET, 0, BUTTON_IDLE, 10, 0},
		{GPIOB, GPIO_PIN_2, GPIO_NOPULL, GPIO_PIN_SET, 0, BUTTON_IDLE, 10, 0},
		{GPIOB, GPIO_PIN_10, GPIO_NOPULL, GPIO_PIN_SET, 0, BUTTON_IDLE, 10, 0},
		{GPIOB, GPIO_PIN_12, GPIO_NOPULL, GPIO_PIN_SET, 0, BUTTON_IDLE, 10, 0},
		{GPIOB, GPIO_PIN_13, GPIO_NOPULL, GPIO_PIN_SET, 0, BUTTON_IDLE, 10, 0},
    };


#ifdef _USE_HW_CLI
static void cliButton(cli_args_t *args);
#endif


bool buttonInit(void)
{
  bool ret = true;
  GPIO_InitTypeDef GPIO_InitStruct = {0};


  __HAL_RCC_GPIOA_CLK_ENABLE();


  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  for (int i=0; i<BUTTON_MAX_CH; i++)
  {
    GPIO_InitStruct.Pin = button_tbl[i].pin;
    GPIO_InitStruct.Pull = button_tbl[i].pull;
    HAL_GPIO_Init(button_tbl[i].port, &GPIO_InitStruct);
  }

#ifdef _USE_HW_CLI
  cliAdd("button", cliButton);
#endif

  return ret;
}

bool buttonGetPressed(uint8_t ch)
{
  bool ret = false;
  button_tbl_t *button;
  button = &button_tbl[ch];

  if (ch >= BUTTON_MAX_CH)
  {
    return false;
  }

  switch(button->State)
  {
  	  case BUTTON_IDLE:
  		  if(HAL_GPIO_ReadPin(button->port, button->pin) == button->on_state)
  		  {
  			  button->lastDebounceTime = millis();
  			  button->State = BUTTON_Pressed;
  		  }
  		  break;

  	  case BUTTON_Pressed:
		  if(HAL_GPIO_ReadPin(button->port, button->pin) == button->on_state)
		  {
			  if ((millis() - button->lastDebounceTime) > button->debounceDelay)
	  		  {
				  button->PinState = GPIO_PIN_SET;
				  ret = button->PinState;
	  		  }
		  }else
		  {
			  button->State = BUTTON_IDLE;
			  button->PinState = GPIO_PIN_RESET;
			  ret = button->PinState;
		  }
		  break;
  }
  return ret;
}

bool buttonMain(void)
{
	bool ret = false;
	button_tbl_t *button;

	for (int i=0; i<BUTTON_MAX_CH; i++)
	{
		button = &button_tbl[i];
	    if (i >= BUTTON_MAX_CH)
	    {
	    	return false;
	    }

	    switch(button->State)
	    {
	    	case BUTTON_IDLE:
	    		if(HAL_GPIO_ReadPin(button->port, button->pin) == button->on_state)
	    		{
	    			button->lastDebounceTime = millis();
	    			button->State = BUTTON_Pressed;
	    		}
	    		break;

	    	case BUTTON_Pressed:
	    		if(HAL_GPIO_ReadPin(button->port, button->pin) == button->on_state)
	    		{
	    			if ((millis() - button->lastDebounceTime) > button->debounceDelay)
	    			{
	    				button->PinState = GPIO_PIN_SET;
	    				ret = button->PinState;
	    			}
	    		}else
	    		{
	    			button->State = BUTTON_IDLE;
	    			button->PinState = GPIO_PIN_RESET;
	    			ret = button->PinState;
	    		}
	    		break;
	    }
	}
	  return ret;
}



#ifdef _USE_HW_CLI

void cliButton(cli_args_t *args)
{
  bool ret = false;


  if (args->argc == 1 && args->isStr(0, "show"))
  {
    while(cliKeepLoop())
    {
      for (int i=0; i<BUTTON_MAX_CH; i++)
      {
        cliPrintf("%d", buttonGetPressed(i));
      }
      cliPrintf("\n");

      delay(100);
    }

    ret = true;
  }


  if (ret != true)
  {
    cliPrintf("button show\n");
  }
}
#endif
