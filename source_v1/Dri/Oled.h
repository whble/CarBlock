/*
********************************************************************************
*
*                                 oled.h
*
* File          : oled.h
* Version       : v1.0
* Author        : whble
* Mode          : Thumb2
* Toolchain     : 
* Description   :                                
*                
* History       :
* Date          : 2015-7-14 16:52:19
*******************************************************************************/

#ifndef _OLED_H_
#define _OLED_H_


#include <stdint.h>
#include <stddef.h>
#include <bsp.h>
#include <bsp_tim.h>


#define X_WIDTH 128
#define Y_WIDTH 64

void OLED_Init(void);
void OLED_CLS(void);
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_P14x16Ch(unsigned char x,unsigned char y,unsigned char N);
void OLED_Fill(unsigned char dat);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_WrDat(unsigned char dat);

#endif

