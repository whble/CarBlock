/********************************************************************************************
**文件说明:		循线驱动文件
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
**函数名称:		Tracking_mode()
**函数功能:		循线子函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
void Tracking_mode()
{
	 
  DisplayListChar(0, 0, " Tracking  mode ");
  DisplayListChar(0, 1, "                ");
  while(1)				
  {

	if(flag!=2) break;										//判断模式是否跳出
	if(pwm==1)hight_votage=22;
	if(pwm==2)hight_votage=8;
	if(pwm==0)hight_votage=15;

   
	if(Inf1==1&&Inf2==1&&Inf3==1&&Inf4==1)					//全黑线时停止
  	{
	  Motor_GoLeft();						   
	  DisplayListChar(0, 1, "  All in line  ");
	}

	if(Inf1==0&&Inf2==0&&Inf3==0&&Inf4==0)  				//全白线时左转
	{
 	 Motor_GoLeftFast();
	 DisplayListChar(0, 1, " Looking line  ");
	}
 
	if((Inf1==0&&Inf2==1&&Inf3==1&&Inf4==0)|| 				//前进
	   (Inf1==0&&Inf2==0&&Inf3==1&&Inf4==0)||
	   (Inf1==0&&Inf2==1&&Inf3==0&&Inf4==0)	)
	{
 	 Motor_GoHead();
     DisplayListChar(0, 1, "     GoHead     ");
	}
	
	
	if(Inf1==0&&Inf2==0&&Inf3==0&&Inf4==1)					//左转 
	{
 	 Motor_GoLeftFast();
     DisplayListChar(0, 1, "   GoLeftFast   ");
	} 
	
	if(Inf1==1&&Inf2==0&&Inf3==0&&Inf4==0)					//右转
	{
 	 Motor_GoRightFast();
     DisplayListChar(0, 1, "  GoRightFast   ");
	}    
  }
}//end Tracking_mode
