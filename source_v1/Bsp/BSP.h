/*
********************************************************************************
*
*                                 bsp.h
*
* File          : bsp.h
* Version       : V1.0
* Author        : whq
* Mode          : Thumb2
* Toolchain     : 
* Description   : BSPӲ����ʼ��
*                
* History       :
* Date          : 2013.07.21
*******************************************************************************/


#ifndef _BSP_H_
#define _BSP_H_


#include <stdint.h>
#include <stddef.h>

/******************************ϵͳ����****************************************/

typedef enum {
	//led io_id
	eLED_0,
	//oled io_id
	eOLED_DC,
	eOLED_RST,
	eOLED_SDA,
	eOLED_SCL,
	//driver io_id
	eIN1,
	eIN2,
	eIN3,
	eIN4,
	eGPIO_MAX_COUNT,
}GPIO_ENUM_t;



/******************************�궨��******************************************/

//LED��
#define LED_OFF(a)              BSP_GpioSet(a)
//LED��
#define LED_ON(a)               BSP_GpioReset(a)


//IO�ø�
#define IO_SET(a)               BSP_GpioSet(a)
//IO�õ�
#define IO_RESET(a)             BSP_GpioReset(a)
//��IO���ϵĵ�ƽ
#define IO_READ(a)              BSP_GpioRead(a)
//IO��ƽ��ת
#define IO_TOGGLE(a)            BSP_GpioToggle(a)


#define BSP_CONEOF(a)           ((sizeof(a)) / (sizeof(*a)))



/******************************************************************************/


void Delay(volatile int32_t nCount);
void IWDG_Init(void);
void SysTickInit(int divide);
void WDG_Clear(void);
void BSP_Init(void);

void BSP_GpioSet(int32_t n);
void BSP_GpioReset(int32_t n);
int32_t BSP_GpioRead(int32_t n);
void BSP_GpioToggle(int n);

void BSP_PortWrite(int32_t n, int32_t value);
void BSP_SystemReset(void);

void Delay_ms(uint32_t nTime);

#endif
/******************************END*********************************************/

