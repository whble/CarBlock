/********************************************************************************************
**文件说明:		电机驱动头文件
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
#ifndef __CONTROL_H__
#define __CONTROL_H__

/*********************************函数申明**************************************************/
extern void Motor_Stop();
extern void Motor_GoHead();
extern void Motor_GoBack();
extern void Motor_GoLeft();
extern void Motor_GoLeftFast();
extern void Motor_GoRight();
extern void Motor_GoRightFast();

#endif