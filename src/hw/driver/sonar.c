/*
 * ultrasonic.c
 *
 *  Created on: 2021. 8. 21.
 *      Author: WANG
 */

#include <sonar.h>
#include "gpio.h"
#include "user_delay.h"

TIM_HandleTypeDef htim3;




sonar_tbl_t sonar_tbl[HW_SONAR_MAX_CH] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

bool sonarInit(void)
{
	bool ret = false;

	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_IC_InitTypeDef sConfigIC = {0};

	  htim3.Instance = TIM3;
	  htim3.Init.Prescaler = 100-1;
	  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim3.Init.Period = 65535;
	  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_IC_Init(&htim3) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	  sConfigIC.ICFilter = 0;
	  if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, TIM_CHANNEL_4) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_4);

	return ret;
}

bool Sonar_measure(void)
{
	bool ret = false;
	static uint32_t pre_time;

	static int16_t sonarHistTab[11];
	static int sonarHistIdx = 0;
	static uint32_t sonarDistanceSum = 0;

	switch(sonar_tbl[0].state)
	{
		case 0:
			gpioPinMode(SONAR_DATA, _DEF_OUTPUT);
			gpioPinWrite(SONAR_DATA, GPIO_PIN_SET);
			DWT_Delay_us(5);
			gpioPinWrite(SONAR_DATA, GPIO_PIN_RESET);
			gpioPinMode(SONAR_DATA, _DEF_INPUT_AF_PP);
			sonar_tbl[0].wait_flag = true;
			sonar_tbl[0].state++;
			pre_time = millis();
			break;

		case 1:
			if(sonar_tbl[0].wait_flag == false)
			{
				if(sonar_tbl[0].falling_time > sonar_tbl[0].rising_time)
				{
					sonar_tbl[0].duty_time = sonar_tbl[0].falling_time - sonar_tbl[0].rising_time;
				}
				else if(sonar_tbl[0].falling_time < sonar_tbl[0].rising_time)
				{
					sonar_tbl[0].duty_time = 65536 - sonar_tbl[0].rising_time + sonar_tbl[0].falling_time;
				}

				sonar_tbl[0].distance_cm = (sonar_tbl[0].duty_time * 10) * 0.0172;

				uint8_t indexplus1 = (sonarHistIdx + 1);
				if (indexplus1 == 11) indexplus1 = 0;
				sonarHistTab[sonarHistIdx] = sonar_tbl[0].distance_cm;
				sonarDistanceSum += sonarHistTab[sonarHistIdx];
				sonarDistanceSum -= sonarHistTab[indexplus1];
				sonarHistIdx = indexplus1;
				sonar_tbl[0].filter_distance_cm = sonarDistanceSum / 10;

				sonar_tbl[0].state = 0;
				ret = true;
			}
			else
			{
				if(millis()-pre_time >= 25)
				{
					sonar_tbl[0].time_out_cnt++;
					sonar_tbl[0].wait_flag = false;
					sonar_tbl[0].state = 0;
					ret = false;
				}
			}
			break;
	}
	return ret;
}


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PB1     ------> TIM3_CH4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /**TIM3 GPIO Configuration
    PB1     ------> TIM3_CH4
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_1);

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4 && htim->Instance == TIM3 && sonar_tbl[0].wait_flag == true)
	{
		if(Ch1_PIN) //(TIM3->CCER & TIM_CCER_CC4P) == 0
		{  // Timer2 Ch1 pin(PA0) is High
			TIM3->CCR4 = 0;
			sonar_tbl[0].rising_time = TIM3->CCR4; // read capture data
			Ch1_POL_FALLING;  // to falling edge
		}
		else
		{   // Timer2 Ch1 pin(PA0) is Low
			sonar_tbl[0].falling_time = TIM3->CCR4; // read capture data
			Ch1_POL_RISING;   // to rising edge
			sonar_tbl[0].wait_flag = false;
		}
	}
}

