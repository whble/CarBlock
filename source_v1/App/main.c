/*
********************************************************************************
*
*                                 main.c
*
* File          : main.c
* Version       : v1.0
* Author        : whble
* Mode          : Thumb2
* Toolchain     : 
* Description   :                                
*                
* History       :
* Date          : 2015-7-16 15:24:34
*******************************************************************************/ 

/***************************************************
 *  INCLUDES
 */ 
#include "string.h"

#include "BSP.h"
#include "BSP_tim.h"

#include "broad.h"

#include "oled.h"
#include "car.h"

/***************************************************
 * TYPEDEFS
 */

/***************************************************
 * GLOBAL VARIABLES
 */

/***************************************************
 * EXTERNAL VARIABLES
 */

/***************************************************
 * EXTERNAL FUNCTIONS
 */

/***************************************************
 * LOCAL VARIABLES
 */
int  iconut=0;

/*******************************************************************************
* Function Name : TIM3_CallBackHandler(void)
* Description   : 定时器3回调函数
* Input         : 
* Output        : 
* Other         : 
* Date          : 2015-7-1 19:02:00
*******************************************************************************/
void TIM3_CallBackHandler(void)
{
    IO_TOGGLE(eLED_0);
}
/*******************************************************************************
* Function Name : SysTick_CallBackHandler(void)
* Description   : 系统滴答时钟回调
* Input         : 
* Output        : 
* Other         : 
* Date          : 2015-7-1 19:02:26
*******************************************************************************/
void SysTick_CallBackHandler(void)
{

		Delay_ms(1000);
	  IO_TOGGLE(eLED_0);
	
}
/*******************************************************************************
* Function Name : main(void)
* Description   : 入口主函数
* Input         : 
* Output        : 
* Other         : 
* Date          : 
*******************************************************************************/
int main(void)
{  
		uint8_t i;
		BSP_Init();
	  SysTickInit(1000);
		
		//BSP_TimOpen(TIM_3, 7200, 10000, TIM3_CallBackHandler);
		IWDG_Init();
		OLED_Init();
		OLED_P14x16Ch(36,0,0); 
	  OLED_P14x16Ch(50,0,1);	
	  OLED_P14x16Ch(64,0,2);	
	  OLED_P14x16Ch(78,0,3); 
	  OLED_P8x16Str(8,2,"www.dzmxj.com");   
    OLED_P6x8Str(0,4,"---------------------");
    OLED_P6x8Str(25,7,__DATE__);
		GoHead();
		while(1)
		{
			for(i=0;i<4;i++)
			{
				OLED_P14x16Ch(60,5,i);
				Delay_ms(500);
			}
			if(i==4)i=0;
			WDG_Clear();
		}
}



