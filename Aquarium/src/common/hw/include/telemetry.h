/*
 * telemetry.h
 *
 *  Created on: 2020. 12. 26.
 *      Author: WANG
 */

#ifndef SRC_COMMON_CORE_TELEMETRY_H_
#define SRC_COMMON_CORE_TELEMETRY_H_

#include "hw_def.h"

#define TX_BUFFER_SIZE 128

void TX_CHR(char ch);
void TX2_CHR(char ch);
int fputc(int ch, FILE *f);
///////////////////////////////////////////////////////////
void SerialCom(void);
void evaluateCommand(void);
void SendTelemetry(void);
void s_struct(uint8_t *cb,uint8_t siz);
void SerialSerialize(uint8_t port,uint8_t a);
void UartSendData(uint8_t port);

typedef enum serialState_t {
  IDLE,
  HEADER_START,
  HEADER_M,
  HEADER_ARROW,
  HEADER_SIZE,
  HEADER_CMD,
} serialState_t;

#define MSP_IDENT                100   //out message         multitype + multiwii version + protocol version + capability variable
#define MSP_STATUS               101   //out message         cycletime & errors_count & sensor present & box activation & current setting number
#define MSP_DATA								 102

////////////////////////////////////////////////////////////////////////////////

#define MSP_SET_RELAY            200   //in message          8 rc chan
#define MSP_SET_BOOT             201   //in message          8 rc chan


#define MSP_EEPROM_WRITE         250   //in message          no param

#define MSP_DEBUGMSG             253   //out message         debug string buffer
#define MSP_DEBUG                254   //out message         debug1,debug2,debug3,debug4
////////////////////////////////////////////////////////////////////////////////////////////////
#define TELEMERY_ERROR            1
#define TELEMERY_ARMED_MODE       2
#define TELEMERY_HEADFREE_MODE    3
#define TELEMERY_CYCLE_TIME       4
#define TELEMERY_BAT_VOLT         5
#define TELEMERY_TEMPERATURE      6
#define TELEMERY_ANGLE_ROLL       7
#define TELEMERY_ANGLE_PITCH      8
#define TELEMERY_ANGLE_YAW        9
#define TELEMERY_HEADING          10
#define TELEMERY_ACC_ROLL         11
#define TELEMERY_ACC_PITCH        12
#define TELEMERY_ACC_YAW          13
#define TELEMERY_GYRO_ROLL        14
#define TELEMERY_GYRO_PITCH       15
#define TELEMERY_GYRO_YAW         16
#define TELEMERY_MAG_ROLL         17
#define TELEMERY_MAG_PITCH        18
#define TELEMERY_MAG_YAW          19
#define TELEMERY_ARMD_TIME        20
#define TELEMERY_BARO_EST         21
#define TELEMERY_PID_RP_P         22
#define TELEMERY_PID_RP_I         23
#define TELEMERY_PID_RP_D         24
#define TELEMERY_PID_Y_P          25
#define TELEMERY_PID_Y_I          26
#define TELEMERY_PID_Y_D          27
#define TELEMERY_NUM_SATS         28
#define TELEMERY_FIX_TYPE         29
#define TELEMERY_GPS_LAT          30
#define TELEMERY_GPS_LON          31
#define TELEMERY_RADIO_ROLL       32
#define TELEMERY_RADIO_PITCH      33
#define TELEMERY_RADIO_YAW        34
#define TELEMERY_RADIO_THROTTLE   35
#define TELEMERY_RADIO_GEAR       36
#define TELEMERY_RADIO_AUX1       37
#define TELEMERY_MOTOR_1          38
#define TELEMERY_MOTOR_2          39
#define TELEMERY_MOTOR_3          40
#define TELEMERY_MOTOR_4          41

#define TELEMERY_PIDSET_RP_P      50
#define TELEMERY_PIDSET_RP_I      51
#define TELEMERY_PIDSET_RP_D      52
#define TELEMERY_PIDSET_Y_P       53
#define TELEMERY_PIDSET_Y_I       54
#define TELEMERY_PIDSET_Y_D       55
#define TELEMERY_PID_SAVE         56

#endif /* SRC_COMMON_CORE_TELEMETRY_H_ */
