/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "clock_init.h"
#include "led.h"
#include "debug_uart5.h"
#include "key.h"
#include "usb2uart.h"
#include "stm32f7xx_it.h"
#include "commandProcess.h"
#include "dataFrame.h"
#include "dataFrame.h"
/**
  * @brief  The application entry point.
  * @retval int
  */

/* SDRAM Memory */
// MAX ADDRESS IS 0XC1FF FFFF
#define SDRAMSIZE 0xffff
//u8 sdramMemory[SDRAMSIZE] __attribute__((at(0XC0000000)));

int main(void)
{
	u8 *p = NULL;
	u16 len=0;
	//	u8 test[] = "hello";
	//	u8 len;
	//	u8 i;
	//	u8 *p1;
	//	u8 test1[] = {0xff,0xfd,0x0C,0x00,0x93,0x05,0x02,0x11,0x05,0x12,0x11,0x22,0x33,0x44,0xaa,0xbb};
	/* MCU Configuration--------------------------------------------------------*/
	CacheEnalble();
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	SystemClock_Config();
	/* Initialize all configured peripherals */
	MTi_630_Init(115200);		// ADD A POWER CONTROLLER SWITCH
	LED_Init();
	SDRAM_FMC_Init();
	USB2UART_Init(2000000);
	DXLMotor_Init(2000000);

	/* Note: MTi630 must initialize at last!!! */
//	IWDG_Init(IWDG_PRESCALER_64,500); 	//��Ƶ��Ϊ64,����ֵΪ500,���ʱ��Ϊ1s	

  while (1)
  {
			getMti630Data(&p,&len);
			USB2UART_SendData(p,len);
			HAL_Delay(100);
	  Data_Receive();
	  Data_Send();
  }
}





