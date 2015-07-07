/********************************************************************************************
**文件说明:		追光驱动文件
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
#include "define.h"


/********************************************************************************************
**函数名称:		light_control()
**函数功能:		追光函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
 void light_control()
  {
	while(1)
	{
	DisplayListChar(0, 0, " light  control ");
	DisplayListChar(0, 1, "                ");

	if(flag!=4)break;                      							//判断是否跳出追光程序
	if(pwm==1)hight_votage=22;
	if(pwm==2)hight_votage=8;
	if(pwm==0)hight_votage=15;
	if(light_left==0&&light_right==0)      							//追光前进	  
	{
	Motor_GoHead();	
	DisplayListChar(0, 1, "  light gohead  ");	
	}
	if(light_left==1&&light_right==0)	   							//追光右转
	{
	Motor_GoRightFast();	
	DisplayListChar(0, 1, "  light goright ");	   
	}
	if(light_left==0&&light_right==1)	   							//追光左转
	{
	Motor_GoLeftFast();	
	DisplayListChar(0, 1, "  light goleft  ");	   
	}
	if(light_left==1&&light_right==1)     							//追光停止	  
	{
	Motor_Stop();	
	DisplayListChar(0, 1, "  light  stop   ");	
	}	
   }
}//end light_control