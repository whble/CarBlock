/********************************************************************************************
**文件说明:		主程序文件
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

/*********************************全局变量************************************************/
unsigned char code myname[] =     {" Hi,I'm WALL.E! "};
unsigned char code madeby[] =     {"Made By ZengYun!"};
unsigned char code begin[] =      {" OK,Let's Begin "};
unsigned char code selectmode[] = {"  Select  Mode  "};
unsigned char code clean[] =      {"                "};
unsigned char flag=0;
unsigned char date=0;
unsigned char pwm=0;
unsigned char wireless=0;
unsigned char IRCOM[7];
uchar uart1temp;
unsigned char b;

/********************************************************************************************
**函数名称:		uart()
**函数功能:		串口初始化函数，为wifi小车提供
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
// void uart()
// {
// 	TCLK=1;
// 	RCLK=1;
// 	
// 	TH2=0xFF;      //9600bps  11.0592MHz的时钟频率
// 	TL2=0xD9;	   //11.0592 TL2为DC  12M为D9
// 	RCAP2H=0xFF;   //方式1和方式3的波特率＝fosc/(32-(65535-(RCAP2H,RCAP2L))
// 	RCAP2L=0xD9;
// 	
// 	//******************串口设置**************************************************//
// 	SCON=0x50;     //SM0  SM1  SM2  REN  TB8 RB8  TI RI
// 	PCON=0x00;     //TMOD=0; 
// 	TR2=1;
// 	ES=1;
// 	EA=1;
// 	ET2=1;
// }

/********************************************************************************************
**函数名称:		main()
**函数功能:		主函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
main()
{
/****************************************************************************************************************/
    IE = 0x81;                						//允许总中断中断,使能 INT0 外部中断 ,使能 INT1 外部中断
    TCON = 0x01;									// INT0 外部中断 , INT1 外部中断,触发方式为脉冲负边沿触发       
	TMOD=0x11;    									//定时器T0/T1工作方式为	模式一
	IP=0X01;         								//外部中断0为高级优先级 
	ET0=1; 											//开启定时器0中断
    TH0=0xff; 										//设置初始值
    TL0=0x9c; 										//定时0.1mS 
	
    hight_votage=15;  								//舵机信号初始值，1.5ms根据教程舵机角度为0 
	
	delay_20_us();                  				//I/O口初始化
	
    delay1(10);                						//延时
	
	//uart();										//wifi串口初始化
    lcd_init();										//1602液晶初始化
    init_NRF24L01();								//初始化NRF24L01 
	ReadDataLCD();									//液晶测试用句无意义
	
	DisplayListChar(0, 0, clean);   				//清除屏幕                              
    DisplayListChar(0, 0, myname);					//显示作品名称
    DisplayListChar(0, 1, madeby);					//显示作者名字
	delay1(1000);					
    DisplayListChar(0, 1, begin);					//启动完成，进入系统
	delay1(1000);
	DisplayListChar(0, 1, selectmode);				//提示选择模式
	
/****************************************************************************************************************/
   while(1)											//主循环
   { 
	   if(flag==1)									//模式选择
	   {
		Motor_Stop();
		delay1(200);
		DisplayListChar(0, 0, myname);
		DisplayListChar(0, 1, selectmode);
	   }
	   if(flag==2)									//循迹模式
	   {
		//TR0=0;
		Motor_Stop();
		delay1(100);
		Tracking_mode();
	   }
	   if(flag==3)									//遥控模式
	   {
	   // TR0=0;
		Motor_Stop();
		delay1(100);
		remote_control();
	   }
		if(flag==4)									//追光模式
	   {
	    // TR0=0;
		Motor_Stop();
		delay1(100);
		light_control();
	   }
		if(flag==5)									//超声波模式
	   {
	    //	TR0=0;
		Motor_Stop();
		DisplayListChar(0, 0, "Ultrasonic  mode");
		DisplayListChar(0, 1, "WeiKongKeChuang!");
		delay1(100);
		Ultrasonic_mode();
	   }
		if(flag==6)									//舞蹈模式
	   {
	    // TR0=0;
		Motor_Stop();
		delay1(100);
		Dance_mode();
	   }
/****************************************************************************************************************/
	   
		//舵机控制	控制前请按9号键开启舵机
		if(pwm==1)hight_votage=22;	 				//左边
		if(pwm==2)hight_votage=8;	 				//右边
		if(pwm==0)hight_votage=15;	 				//中间
	    //主从模式传输电机状态
		if(wireless==1){
				DisplayListChar(0, 1, "  come in     ");
				receive();
			} 

   };//end while

}//end main


/********************************************************************************************
**函数名称:		void IR_IN(void) interrupt 0 
**函数功能:		红外外部中断服务函数
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/


void IR_IN(void) interrupt 0 	 					//外部中断服务程序
{
  int m=0;
  unsigned char j,k,N=0;
     EX0 = 0;   
	 delay(15);
	 if (IRIN==1) 
     { EX0 =1;
	   return;
	  }                     						//确认IR信号出现
  while (!IRIN)             						//等IR变为高电平，跳过9ms的前导低电平信号。
    {delay(1);}

  for (j=0;j<4;j++)         						//收集四组数据
  { 
   for (k=0;k<8;k++)        						//每组数据有8位
   {
   while (IRIN)             						//等 IR 变为低电平，跳过4.5ms的前导高电平信号。
     {delay(1);}
    while (!IRIN)           						//等 IR 变为高电平
     {delay(1);}
     while (IRIN)           						//计算IR高电平时长
      {
    delay(1);
    N++;           
    if (N>=30)
	 { EX0=1;
	 return;}                  						//0.14ms计数过长自动离开。
      }                        						//高电平计数完毕                
     IRCOM[j]=IRCOM[j] >> 1;                  		//数据最高位补“0”
     if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  		//数据最高位补“1”
     N=0;
  }//end for k
 }//end for j
   
   if (IRCOM[2]!=~IRCOM[3])
   { EX0=1;
     return; }

   IRCOM[5]=IRCOM[2] & 0x0F;     					//取键码的低四位
   IRCOM[6]=IRCOM[2] >> 4;       					//右移4次，高四位变为低四位

   if(IRCOM[5]>9)
    { IRCOM[5]=IRCOM[5]+0x37;}
   else
	  IRCOM[5]=IRCOM[5]+0x30;

   if(IRCOM[6]>9)
    { IRCOM[6]=IRCOM[6]+0x37;}
   else
	  IRCOM[6]=IRCOM[6]+0x30;


/*************红外遥控数据编码********/	 
	 switch(IRCOM[2])
	 {
	 case 0x45: pwm=1;  break;
     case 0x46: pwm=0;  break;
	 case 0x47: pwm=2;  break;
	 
	 case 0x44: date=3;  break;	   					//快速左转
	 case 0x40: date=4;  break;	   					//前进
	 case 0x43: date=5;  break;	   					//快速右转
	 
	 case 0x07: date=6;  break;	   					//左转
	 case 0x15: date=7;  break;	   					//停止
	 case 0x09: date=8;  break;	   					//右转
    
	 case 0x16: date=9; flag=1; break;
	 case 0x19: date=10; break;	   					//后退
	 case 0x0d: wireless=11; break;					//无线模式开关控制

	 case 0x0c: date=12; flag=2; break;
	 case 0x18: date=13; flag=3;break;
	 case 0x5e: date=14; flag=4;break;

	 case 0x08: date=15; flag=5; break;
	 case 0x1c: date=16; flag=6;break;	 
     case 0x5a: date=17; break;

	 case 0x42: flag=7;wireless=0; break;
	 case 0x52: flag=7;wireless=1; break;
	 case 0x4a: date=20;TR0=!TR0; break;
	 
	 }

    EX0 = 1; 
} 


/********************************************************************************************
**函数名称:		void uartReceive_1(void) interrupt 4 
**函数功能:		串口接收中断服务函数，用于wifi功能
**输入参数:		none
**输出参数:		none
**返 回 值:		none
**创 建 人:		whble
**创建日期:		2013-7-25
*********************************************************************************************
**修 改 人:
**修改说明:
********************************************************************************************/
// void uartReceive_1(void) interrupt 4   				//串口接收中断服务函数，用于wifi功能
// {
// 	if(RI==1)
// 	{
// 		RI=0;
// 		uart1temp=SBUF;
// 		switch(uart1temp)
// 		{
// 			case 0x34:								//前进
// 				IN1=1;IN2=0;IN3=1;IN4=0;
// 				break;
// 			case 0x32:								//后退
// 				IN1=0;IN2=1;IN3=0;IN4=1;
// 				break;	
// 			case 0x31:								//右转
// 				IN1=0;IN2=0;IN3=1;IN4=0;
// 				break;
// 			case 0x33:								//左转
// 				IN1=1;IN2=0;IN3=0;IN4=0;
// 				break;
// 			case 0x30:								//停止
// 				IN1=0;IN2=0;IN3=0;IN4=0;
// 				break;		
// 		}		
// 	}
// 		
// }