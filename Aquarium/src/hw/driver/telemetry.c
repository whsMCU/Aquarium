/*
 * telemery.c
 *
 *  Created on: 2020. 12. 26.
 *      Author: WANG
 */


#include "telemetry.h"
#include "uart.h"
#include "led.h"
#include "ds18b20.h"
#include "sonar.h"
#include "tds.h"

int8_t Relay[4];


char Buf[128];

static volatile uint8_t serialHeadTX[UART_MAX_CH],serialTailTX[UART_MAX_CH];
static uint8_t serialBufferTX[TX_BUFFER_SIZE][UART_MAX_CH];
static uint8_t serialBufTx_0[TX_BUFFER_SIZE];
static uint8_t serialBufTx_1[TX_BUFFER_SIZE];
static volatile uint8_t serialHead_0, serialHead_1;
static uint8_t CURRENTPORT=0;

volatile unsigned char command=0;
volatile unsigned char m = 0;
int MSP_TRIM[3]={0, 0, 0};

uint8_t telemetry_loop_counter = 0;
uint16_t time=0, time1=0, aftertime=0;
uint16_t debug[4]={0,0,0,0};

uint8_t GPS_virtual=0;

////////////////////////////////////////////

uint8_t rx1_buffer[1];
uint8_t rx2_buffer[1];

//////////// MSP //////////////////
#define INBUF_SIZE 128
typedef struct mspPortState_t {
	//    serialPort_t *port;
	uint8_t checksum;
	uint8_t indRX;
	uint8_t inBuf[INBUF_SIZE];
	uint8_t cmdMSP;
	uint8_t offset;
	uint8_t dataSize;
	serialState_t c_state;
} mspPortState_t;

static mspPortState_t ports[2];
static mspPortState_t *currentPortState = &ports[0];

static void serialize8(uint8_t a);
static void serialize16(int16_t a);
static void serialize32(uint32_t a);
static uint8_t read8(void);
static uint16_t read16(void);
static uint32_t read32(void);
static void headSerial(uint8_t err, uint8_t s, uint8_t cmdMSP);
static void headSerialSend(uint8_t s, uint8_t cmdMSP);
static void headSerialResponse(uint8_t err, uint8_t s);
static void headSerialReply(uint8_t s);
static void headSerialError(uint8_t s);
static void tailSerialReply(void);
static void s_struct_partial(uint8_t *cb,uint8_t siz);
//static void s_struct(uint8_t *cb,uint8_t siz);


void serialize8(uint8_t a)
{
	SerialSerialize(CURRENTPORT,a);
	currentPortState->checksum ^= (a & 0xFF);
}

void serialize16(int16_t a)
{
	serialize8((a   ) & 0xFF);
	serialize8((a>>8) & 0xFF);
}

void serialize32(uint32_t a)
{
	serialize8((a    ) & 0xFF);
	serialize8((a>> 8) & 0xFF);
	serialize8((a>>16) & 0xFF);
	serialize8((a>>24) & 0xFF);
}

uint8_t read8(void)
{
	return currentPortState->inBuf[currentPortState->indRX++] & 0xff;
}

uint16_t read16(void)
{
	uint16_t t = read8();
	t += (uint16_t)read8() << 8;
	return t;
}

uint32_t read32(void)
{
	uint32_t t = read16();
	t += (uint32_t)read16() << 16;
	return t;
}

void headSerial(uint8_t err, uint8_t s, uint8_t cmdMSP)
{
	serialize8('$');
	serialize8('M');
	serialize8(err ? '!' : '>');
	currentPortState->checksum = 0;               // start calculating a new checksum
	serialize8(s);
	serialize8(cmdMSP);
}

void headSerialSend(uint8_t s, uint8_t cmdMSP)
{
	headSerial(0, s, cmdMSP);
}

void headSerialResponse(uint8_t err, uint8_t s)
{
	serialize8('$');
	serialize8('M');
	serialize8(err ? '!' : '>');
	currentPortState->checksum = 0;               // start calculating a new checksum
	serialize8(s);
	serialize8(currentPortState->cmdMSP);
}

void headSerialReply(uint8_t s)
{
	headSerialResponse(0, s);
}

void headSerialError(uint8_t s)
{
	headSerialResponse(1, s);
}

void tailSerialReply(void)
{
	SerialSerialize(CURRENTPORT,currentPortState->checksum);
	UartSendData(CURRENTPORT);
	//serialize8(currentPortState->checksum);
}

void s_struct_partial(uint8_t *cb,uint8_t siz)
{
	while(siz--) serialize8(*cb++);
}

void s_struct(uint8_t *cb,uint8_t siz)
{
	headSerialReply(siz);
	s_struct_partial(cb,siz);
	tailSerialReply();
}
///////////////////////////////////////////////////

void SerialCom(void)
{
	uint8_t c;

	currentPortState = &ports[_DEF_UART1];
	CURRENTPORT = _DEF_UART1;
	while(uartAvailable(CURRENTPORT) > 0)
	{
		c = uartRead(CURRENTPORT);
		if (currentPortState->c_state == IDLE)
		{
			currentPortState->c_state = (c=='$') ? HEADER_START : IDLE;
		} else if (currentPortState->c_state == HEADER_START)
		{
			currentPortState->c_state = (c=='M') ? HEADER_M : IDLE;
		} else if (currentPortState->c_state == HEADER_M)
		{
			currentPortState->c_state = (c=='<') ? HEADER_ARROW : IDLE;
		} else if (currentPortState->c_state == HEADER_ARROW)
		{
			if (c > INBUF_SIZE)
			{  // now we are expecting the payload size
				currentPortState->c_state = IDLE;
				continue;
			}
			currentPortState->dataSize = c;
			currentPortState->offset = 0;
			currentPortState->indRX = 0;
			currentPortState->checksum = 0;
			currentPortState->checksum ^= c;
			currentPortState->c_state = HEADER_SIZE;
		} else if (currentPortState->c_state == HEADER_SIZE)
		{
			currentPortState->cmdMSP = c;
			currentPortState->checksum ^= c;
			currentPortState->c_state = HEADER_CMD;
		} else if (currentPortState->c_state == HEADER_CMD && currentPortState->offset < currentPortState->dataSize)
		{
			currentPortState->checksum ^= c;
			currentPortState->inBuf[currentPortState->offset++] = c;
		} else if (currentPortState->c_state == HEADER_CMD && currentPortState->offset >= currentPortState->dataSize)
		{
			if (currentPortState->checksum == c)
			{
				evaluateCommand();
			}
			currentPortState->c_state = IDLE;
		}
	}
}

void evaluateCommand(void)
{
	uint8_t i=0;

	switch(currentPortState->cmdMSP)
	{
		case MSP_DATA:
		{
			struct {
				float water_temp;
				uint32_t water_level;
				float water_tds;
			} data;
			data.water_temp = (float)ds18b20[0].Temperature;
			data.water_level = (uint32_t)sonar_tbl[0].filter_distance_cm/10;
			data.water_tds = (float)tds_tbl[0].filter_tdsValue;
			s_struct((uint8_t*)&data,12);
			break;
		}
		case MSP_SET_RELAY:
			Relay[0] = read8();
			Relay[1] = read8();
			Relay[2] = read8();
			Relay[3] = read8();
			break;

		default:
			//headSerialError();
			//tailSerialReply();
			break;
	}

}

void SerialSerialize(uint8_t port,uint8_t a) {
	uint8_t t = serialHeadTX[port];
	if (++t >= TX_BUFFER_SIZE) t = 0;
	serialBufferTX[t][port] = a;
	serialHeadTX[port] = t;
}

void UartSendData(uint8_t port)
{
	uint8_t t = serialTailTX[port];
	switch(port){
		case _DEF_UART1:
			while (serialHeadTX[port] != t)
			{
				if (++t >= TX_BUFFER_SIZE) t = 0;
				serialBufTx_0[serialHead_0++] = serialBufferTX[t][port];
			}
			serialTailTX[port] = t;
			uartWriteIT(_DEF_UART1, serialBufTx_0, serialHead_0);
			serialHead_0 = 0;
			break;

		case _DEF_UART2:
			while (serialHeadTX[port] != t)
			{
				if (++t >= TX_BUFFER_SIZE) t = 0;
				serialBufTx_1[serialHead_1++] = serialBufferTX[t][port];
			}
			serialTailTX[port] = t;
			uartWriteIT(_DEF_UART2, serialBufTx_1, serialHead_1);
			serialHead_1 = 0;
			break;
	}
}
