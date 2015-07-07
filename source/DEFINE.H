/********************************************************************************************
**文件说明:		常用定义头文件
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

#ifndef __DEFINE_H
#define __DEFINE_H

/*********************************数据类型**************************************************/
typedef unsigned char uchar;
typedef unsigned char uint;

/*********************************全局变量**************************************************/
extern unsigned char flag;
extern unsigned char date;
extern unsigned char pwm;
extern unsigned char wireless;
extern unsigned char tf;
extern unsigned char key_stime_counter;
extern uchar imeT_counter;
extern bit key_stime_ok;

/*********************************用户头文件**************************************************/
#include "reg52.h" 
#include "function.h"
#include "intrins.h"
#include "1602.h"
#include "ir.h"
#include "remote.h"
#include "control.h"
#include "dance.h"
#include "light_control.h"
#include "wireless.h"
#include "ultrasonic.h"

/************************************* NRF24L01端口定义 **************************************/
sbit 	MISO	=P3^1;			  						//spi从机输出，主机输入（spi输出）把自己当成从机
sbit 	MOSI	=P1^5;			  						//spi主机输出，从机输入（spi输入）把自己当成从机
sbit	SCK	    =P3^5;			  						//spiclk信号
sbit	CE	    =P3^6;			  						//无线收发模式选择
sbit	CSN		=P3^0;			  						//spi片选使能，低电平使能	（ss）
sbit	IRQ		=P1^4;			  					//中断输入


/************************************* 电机驱动端口定义 **************************************/
sbit IN1=P1^0; 
sbit IN2=P1^1;
sbit IN3=P1^2;
sbit IN4=P1^3;

/************************************* 定义舵机控制端口 **************************************/
sbit control_signal=P0^4;

/************************************* 定义红外接收口 ****************************************/
sbit IRIN=P3^2;

/************************************* 定义追光传感器 ****************************************/
sbit light_left=P1^6;
sbit light_right=P1^7;


/************************************* 红外传感从右到左 **************************************/
sbit Inf1=P0^0;
sbit Inf2=P0^1;
sbit Inf3=P0^2;
sbit Inf4=P0^3;

/************************************ 1602引脚定义 *******************************************/
sbit RS=P0^6;
sbit RW=P0^5;
sbit LCDEN=P0^7;
#define LCD P2

/*********************************** 超声波检测端口定义 **************************************/
sbit  Echo=P3^3;
sbit  Trig = P3^7;

#endif
