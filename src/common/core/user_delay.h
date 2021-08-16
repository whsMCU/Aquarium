/*
 * user_delay.h
 *
 *  Created on: 2021. 8. 16.
 *      Author: WANG
 */

#ifndef SRC_COMMON_CORE_USER_DELAY_H_
#define SRC_COMMON_CORE_USER_DELAY_H_

#include "hw_def.h"

uint32_t DWT_Delay_Init(void);

/**
 * @brief  This function provides a delay (in microseconds)
 * @param  microseconds: delay in microseconds
 */
__STATIC_INLINE void DWT_Delay_us(volatile uint32_t microseconds)
{
  uint32_t clk_cycle_start = DWT->CYCCNT;

  /* Go to number of cycles for system */
  microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);

  /* Delay till end */
  while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}

#endif /* SRC_COMMON_CORE_USER_DELAY_H_ */
