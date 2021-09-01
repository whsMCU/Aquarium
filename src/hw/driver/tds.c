/*
 * tds.c
 *
 *  Created on: 2021. 8. 28.
 *      Author: WANG
 */


#include "tds.h"

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;


tds_tbl_t tds_tbl[HW_TDS_MAX_CH];


bool tdsInit(void)
{
	bool ret = true;
	tds_tbl[0].aref = 3.3;
	tds_tbl[0].temperature = 25.0;
	tds_tbl[0].adcRange = 4096.0;
	tds_tbl[0].kValue = 1.0;

	  ADC_ChannelConfTypeDef sConfig = {0};

	  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	  */
	  hadc1.Instance = ADC1;
	  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	  hadc1.Init.ScanConvMode = ENABLE;
	  hadc1.Init.ContinuousConvMode = ENABLE;
	  hadc1.Init.DiscontinuousConvMode = DISABLE;
	  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hadc1.Init.NbrOfConversion = 1;
	  hadc1.Init.DMAContinuousRequests = ENABLE;
	  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_1;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	if (HAL_ADC_Start_DMA(&hadc1, &tds_tbl[0].analogValue, 1) != HAL_OK)
	{
		Error_Handler();
	}

	return ret;

}
bool tds_measure(void)
{
	bool ret = true;
	static int16_t tdsHistTab[11];
	static int tdsHistIdx = 0;
	static uint32_t tdsValueSum = 0;

	tds_tbl_t *tds = &tds_tbl[0];

	tds->voltage = tds->analogValue/tds->adcRange*tds->aref;
	tds->ecValue=(133.42*tds->voltage*tds->voltage*tds->voltage - 255.86*tds->voltage*tds->voltage + 857.39*tds->voltage)*tds->kValue;
	tds->ecValue25  =  tds->ecValue / (1.0+0.02*(tds->temperature-25.0));  //temperature compensation
	tds->tdsValue = tds->ecValue25 * TdsFactor;

	uint8_t indexplus1 = (tdsHistIdx + 1);
	if (indexplus1 == 11) indexplus1 = 0;
	tdsHistTab[tdsHistIdx] = tds->tdsValue;
	tdsValueSum += tdsHistTab[tdsHistIdx];
	tdsValueSum -= tdsHistTab[indexplus1];
	tdsHistIdx = indexplus1;
	tds->filter_tdsValue = tdsValueSum / 10;

	return ret;
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  if(adcHandle->Instance==ADC1)
	  {
	  /* USER CODE BEGIN ADC1_MspInit 0 */
		  /* DMA controller clock enable */
		  __HAL_RCC_DMA2_CLK_ENABLE();
	  /* USER CODE END ADC1_MspInit 0 */
	    /* ADC1 clock enable */
	    __HAL_RCC_ADC1_CLK_ENABLE();

	    __HAL_RCC_GPIOA_CLK_ENABLE();
	    /**ADC1 GPIO Configuration
	    PA1     ------> ADC1_IN1
	    */
	    GPIO_InitStruct.Pin = GPIO_PIN_1;
	    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	    /* ADC1 DMA Init */
	    /* ADC1 Init */
	    hdma_adc1.Instance = DMA2_Stream0;
	    hdma_adc1.Init.Channel = DMA_CHANNEL_0;
	    hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
	    hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
	    hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
	    hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	    hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	    hdma_adc1.Init.Mode = DMA_CIRCULAR;
	    hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
	    hdma_adc1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	    if (HAL_DMA_Init(&hdma_adc1) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    __HAL_LINKDMA(adcHandle,DMA_Handle,hdma_adc1);

	    /* ADC1 interrupt Init */
	    HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
	    HAL_NVIC_EnableIRQ(ADC_IRQn);

  /* USER CODE BEGIN ADC1_MspInit 1 */
    /* DMA2_Stream0_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  /* USER CODE END ADC1_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();

    /**ADC1 GPIO Configuration
    PA1     ------> ADC1_IN1
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);
    /* ADC1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(ADC_IRQn);
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }
}
