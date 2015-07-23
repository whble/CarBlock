/*
********************************************************************************
*
*                                car.h
*
* File          : car.h
* Version       : vesion
* Author        : whble
* Mode          : Thumb2
* Toolchain     : 
* Description   :                                
*                
* History       :
* Date          : 
*******************************************************************************/
#ifndef _CAR_H
#define _CAR_H


#include <stdint.h>
#include <stddef.h>
#include <bsp.h>
#include <bsp_tim.h>

#ifdef __cplusplus
extern "C"
{
#endif

void GoHead(void);
void GoBack(void);
void TurnRight(void);
void TurnLeft(void);
void Stop(void);
	
	
	

#ifdef __cplusplus
}
#endif

#endif /* XX_H */
