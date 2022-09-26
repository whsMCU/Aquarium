/*
 * ap.h
 *
 *  Created on: Jan 23, 2021
 *      Author: WANG
 */

#ifndef SRC_AP_AP_H_
#define SRC_AP_AP_H_

#include "hw.h"

typedef struct
{
  float ds18b20_temp;
  uint32_t sonar_distance;
  uint32_t water_tank_height;
  uint32_t water_level;
  float water_quality;

  bool setting;
  bool setting_mode;
  uint8_t setting_cnt;
  uint8_t setting_index;

  float ds18b20_temp_setting;
  float water_temp_deadband;
  uint32_t water_level_setting;
  uint32_t water_level_deadband;
  float water_quality_setting;
  float water_quality_deadband;
} sensor_t;


void apInit(void);
void apMain(void);

#endif /* SRC_AP_AP_H_ */
