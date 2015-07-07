/********************************************************************************************
**文件说明:		红外遥控驱动文件
**版权归属:		EMO--E梦电子
**创 建 人:		whble
**版    本:		1.0V
**淘	宝:		http://taobao.xiangyunzone.com
**论    坛:		http://www.honeygeek.org/
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
**修改版本:		
********************************************************************************************/

/*********************************公共头文件************************************************/
#include "define.h"

/********************************************************************************************
**函数名称:		remote_control()
**函数功能:		红外遥控模式函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
void remote_control()
{  
    TR0=1;  															//定时器0 控制位
	while(1)
	{
	DisplayListChar(0, 0, " remote control ");
	DisplayListChar(0, 1, "                ");
	if(flag!=3)break; 
    if(pwm==1)hight_votage=22;
	if(pwm==2)hight_votage=8;
	if(pwm==0)hight_votage=15;
	if(date == 3)	   													//左急转弯
	{
		
		Motor_GoLeftFast();	
		DisplayListChar(0, 1, "   GoLeftFast   ");
	}
	else if(date == 4)	   												//前进
	{	
		
		Motor_GoHead();
		DisplayListChar(0, 1, "     GoHead     ");	
	}
	else if(date == 5)	   												//右急转弯
	{
		Motor_GoRightFast();
		DisplayListChar(0, 1, "  GoRightFast   ");	
	}
	else if(date == 6)	   												//左转
	{
		
		Motor_GoLeft();
		DisplayListChar(0, 1, "     GoLeft     ");	
	}
	else if(date == 7)	   												//停车
	{
	
		Motor_Stop();
		DisplayListChar(0, 1, "      Stop      ");	
	}
	else if(date == 8)	   												//右转
	{
		Motor_GoRight();
		DisplayListChar(0, 1, "     GoRight    ");	
	}
	else if(date == 10)	   												//倒车
	{

		Motor_GoBack();	
		DisplayListChar(0, 1, "     GoBack     ");
	}   

    }
}
//end remote_control
