/*
 * ultrasonic.h
 *
 *  Created on: 2021. 8. 21.
 *      Author: WANG
 */

#ifndef SRC_COMMON_HW_INCLUDE_SONAR_H_
#define SRC_COMMON_HW_INCLUDE_SONAR_H_

#include "hw_def.h"

#define Ch1_PIN         (GPIOB->IDR & GPIO_PIN_1)         /* Timer2 ch1 pin: PA0 */
#define Ch1_POL_RISING  (TIM3->CCER &= ~TIM_CCER_CC4P)    /* Timer2 ch1: rising edge */
#define Ch1_POL_FALLING (TIM3->CCER |= TIM_CCER_CC4P)     /* Timer2 ch1: falling edge */

typedef struct
{
	bool		  wait_flag;
    uint8_t       state;
    uint32_t	  rising_time;
    uint32_t      falling_time;
    uint32_t	  duty_time;
    uint32_t      distance_cm;
    uint32_t      filter_distance_cm;
} sonar_tbl_t;

extern sonar_tbl_t sonar_tbl[HW_SONAR_MAX_CH];

bool     sonarInit(void);
bool	 measure(void);

#endif /* SRC_COMMON_HW_INCLUDE_SONAR_H_ */
