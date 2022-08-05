/*
 * tds.h
 *
 *  Created on: 2021. 8. 28.
 *      Author: WANG
 */

#ifndef SRC_COMMON_HW_INCLUDE_TDS_H_
#define SRC_COMMON_HW_INCLUDE_TDS_H_

#include "hw_def.h"

#define TdsFactor 0.5  // tds = ec / 2

typedef struct
{
	uint8_t		aref;
	float		kValue;
	float		temperature;
	float		adcRange;
	uint32_t	analogValue;
	float   	voltage;
	float 		ecValue;
	float		ecValue25;
	float		tdsValue;
	float		filter_tdsValue;
} tds_tbl_t;

extern tds_tbl_t tds_tbl[HW_TDS_MAX_CH];

bool     tdsInit(void);
bool	 tds_measure(void);

#endif /* SRC_COMMON_HW_INCLUDE_TDS_H_ */
