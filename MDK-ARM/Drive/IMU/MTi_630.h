#ifndef __MTI_630_H
#define __MTI_630_H

#include "config.h"


/** @defgroup IMU MTi630DataReceiveReg
  * @{
  */
#define IMU_RECEIVE_SWITCH   0x01
#define IMU_RECEIVE_STATUS   0x02

#define DISABLE_IMU_RECEIVE  0x00
#define ENABLE_IMU_RECEIVE   0x01

#define IMU_RECEIVE_COMPLETE 0x02
#define IMU_RECEIVE_READY    0x00     
/**
  * @}
  */


/** @defgroup IMU BUFFER SIZE
  * @{
  */
#define MTi_630_RXBUFFSIZE 65
/**
  * @}
  */
	
/** @defgroup checkSumComplement Status
  * @{
  */
#define VALID   1
#define INVALID 0
/**
  * @}
  */
	
/** @defgroup Buffer definition
* @{
*/
#define MTI630_BUFFER0   0
#define MTI630_BUFFER1   1
/**
  * @}
  */
	

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart2;
extern __align(4) u8 MTi_630_aRxBuffer0[MTi_630_RXBUFFSIZE] __attribute__((at(0XC0000000)));
extern __align(4) u8 MTi_630_aRxBuffer1[MTi_630_RXBUFFSIZE] __attribute__((at(0XC0000100)));
extern u8*  MTi_630_aRxBuffer;


/*
MTi630DataReceiveReg
---------------------------------------------------------------------------------
|    7    |    6    |    5    |    4    |    3    |    2    |    1    |    0    |
---------------------------------------------------------------------------------
| RESEVER | RESEVER | RESEVER | RESEVER | RESEVER | RESEVER | REV_STA |  SWITCH |
---------------------------------------------------------------------------------
SWITCH:
0:Disable MTi_630 receiver
1:Enable  MTi_630 receiver

REV_STA:
0:MTi_630 data is receiving
1:MTi_630 data receive completely
*/
extern __IO u8 MTi630DataReceiveReg;


extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;

/* Function declaration --------------------------------------------------------*/

/* Initialization and functions  ****************************/
void MTi_630_Init(u32 baud);

/* IMU operation functions *****************************************************/
void MTi_630_SendData(u8 *databuf, u8 len);
u8   getMti630Data(u8** pdata, u16* len);

/* Other operation functions */
u8 copySrcBufferToDesMem(u8* SrcBuffer,u8* DesMem,u16 Len);


#endif
