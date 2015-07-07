/********************************************************************************************
**文件说明:		舞蹈模式驱动文件
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
unsigned char hight_votage;
/********************************************************************************************
**函数名称:		void Dance_mode()
**函数功能:		舞蹈模式函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
void Dance_mode()
{
	 
  DisplayListChar(0, 0, "  Dance   mode  ");
  DisplayListChar(0, 1, "  Lalalala....  "); 
  Motor_Stop();
  delay_ms(500);
  TR0=1;
  hight_votage=15;
  while(1)				
  {

   if(flag!=6) break;													//判断模式是否跳出子函数

/**************************************************编排舞蹈动作*************************************/	  
   //开场动作
 	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	//舞蹈开始

 	Motor_GoLeft();
	send();
	delay_ms(600);
	Motor_GoRight();
	send();
	delay_ms(600);
 	Motor_GoLeftFast();
	send();
 	delay_ms(600);
 	Motor_GoRightFast();
	send();
	delay_ms(600);

	//舞蹈结束

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);
   }
}