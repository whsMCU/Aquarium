/*
 * onewire.h
 *
 *  Created on: 2021. 8. 16.
 *      Author: WANG
 */

#ifndef SRC_COMMON_HW_INCLUDE_ONEWIRE_H_
#define SRC_COMMON_HW_INCLUDE_ONEWIRE_H_

#include "hw_def.h"

#ifdef _USE_HW_ONEWIRE

#define ONEWIRE_MAX_CH		HW_ONEWIRE_MAX_CH

bool onewireInit(void);
bool reset(void);
uint16_t read_byte(void);
bool write_byte(char data);

#endif

#endif /* SRC_COMMON_HW_INCLUDE_ONEWIRE_H_ */
