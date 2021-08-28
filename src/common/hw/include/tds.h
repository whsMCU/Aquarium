/*
 * tds.h
 *
 *  Created on: 2021. 8. 28.
 *      Author: WANG
 */

#ifndef SRC_COMMON_HW_INCLUDE_TDS_H_
#define SRC_COMMON_HW_INCLUDE_TDS_H_

#include "hw_def.h"

typedef struct
{
	uint32_t	  rawdata;
    uint32_t      voltage;
} tds_tbl_t;

extern tds_tbl_t tds_tbl[HW_TDS_MAX_CH];

bool     tdsInit(void);
bool	 tds_measure(void);

#endif /* SRC_COMMON_HW_INCLUDE_TDS_H_ */
