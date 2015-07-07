/********************************************************************************************
**文件说明:		1602驱动头文件
**版权归属:		EMO--E梦电子
**创 建 人:		whble
**版    本:		1.0V
**网    站:		http://taobao.xiangyunzone.com
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
**修改版本:
********************************************************************************************/
#ifndef _1602_H
#define _1602_H

/*********************************函数申明**************************************************/
extern void lcd_init();
extern void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);
extern void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);
extern void WriteCommandLCD(unsigned char WCLCD,BuysC);
extern unsigned char ReadDataLCD(void);
extern unsigned char ReadStatusLCD(void);
extern void WriteDataLCD(unsigned char WDLCD);
#endif