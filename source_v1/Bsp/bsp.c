/*
********************************************************************************
*
*                                 bsp.c
*
* File          : bsp.c
* Version       : V1.0
* Author        : whble
* Mode          : Thumb2
* Toolchain     : 
* Description   : System init
									IO init
									Clock init
*                
* History       :	V1.0
* Date          : 2015-7-1 18:56:17
*******************************************************************************/

#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_iwdg.h"
#include "bsp.h"


__IO uint32_t TimingDelay;


typedef const struct {
    GPIO_TypeDef    *port;      //IO �˿�
    uint32_t        clk;        //IO ʱ��
    uint16_t        pin;        //IO ����
    uint8_t         state;      //IO �������״̬ 0)��� 1)���� 2)�������� 3)�������� 4)��©��� 5)�������
    uint8_t         id;         //IO id��
}PORT_INFO_t;


//�˿ڶ��� 
static PORT_INFO_t m_PortInfo[] = {
	//LED IO
    {GPIOC, RCC_APB2Periph_GPIOC,  GPIO_Pin_13,     0,     eLED_0},   
	//OLED IO
		{GPIOB, RCC_APB2Periph_GPIOB,  GPIO_Pin_0,   	  5,     eOLED_DC},
		{GPIOB, RCC_APB2Periph_GPIOB,  GPIO_Pin_1,  	  5,     eOLED_RST},
		{GPIOB, RCC_APB2Periph_GPIOB,  GPIO_Pin_10,  	  5,     eOLED_SDA},
		{GPIOB, RCC_APB2Periph_GPIOB,  GPIO_Pin_11,     5,     eOLED_SCL},
	//Driver IO
		{GPIOA, RCC_APB2Periph_GPIOA,  GPIO_Pin_4,   	  5,    eIN1},
		{GPIOA, RCC_APB2Periph_GPIOA,  GPIO_Pin_5,  	  5,    eIN2},
		{GPIOA, RCC_APB2Periph_GPIOA,  GPIO_Pin_6,  	  5,    eIN3},
		{GPIOA, RCC_APB2Periph_GPIOA,  GPIO_Pin_7,      5,    eIN4},
};

		

static uc16 m_PortCount = BSP_CONEOF(m_PortInfo);




/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    PORT_INFO_t *pPort = m_PortInfo;
    uint8_t i = 0;

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    for (i = 0; i < m_PortCount; i++, pPort++)
    {
        RCC_APB2PeriphClockCmd(pPort->clk, ENABLE);
        GPIO_InitStructure.GPIO_Pin = pPort->pin;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        
        if (pPort->state == 0) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        else if (pPort->state == 1) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        else if (pPort->state == 2) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
        else if (pPort->state == 3) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
        else if (pPort->state == 4) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
        else if (pPort->state == 5) GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
            
        GPIO_Init(pPort->port, &GPIO_InitStructure);
    }
}


/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
* Output         : None
* Return         : None
*******************************************************************************/
void Delay(volatile s32 nCount)
{
    for(; nCount != 0; nCount--);
}

/*******************************************************************************
* Function Name : IWDG_Init
* Description   : ���Ź���ʼ��
* Input         : 
* Output        : 
* Other         : 
* Date          : 2015-7-1 18:59:02
*******************************************************************************/
void IWDG_Init(void)
{
    IWDG_WriteAccessCmd( IWDG_WriteAccess_Enable );
    IWDG_SetPrescaler( IWDG_Prescaler_128);	//��С
    IWDG_SetReload(0x138 * 5);		//40KHz�ڲ�ʱ�� (1/40000 * 128 * 0x138 * 5= 5s )
    IWDG_WriteAccessCmd( IWDG_WriteAccess_Disable );
    IWDG_Enable();
    IWDG_ReloadCounter();
}

/*******************************************************************************
* Function Name : void IWDG_Clear(void)
* Description   : �忴�Ź�
* Input         : 
* Output        : 
* Other         : 
* Date          : 2014.04.13
*******************************************************************************/
void WDG_Clear(void)
{
    IWDG_ReloadCounter();
}

/*******************************************************************************
* Function Name :void SysTickInit(void)
* Description   :ϵͳ��ʱ��ʱ������
* Input         :
* Output        :
* Other         :ʱ��Ϊ1ms
* Date          :2011.11.03  12:59:13
*******************************************************************************/
void SysTickInit(int divice)
{
    RCC_ClocksTypeDef rccClk = {0};
    
    RCC_GetClocksFreq(&rccClk);
    
    SysTick_Config(rccClk.HCLK_Frequency / divice);			//uCOSʱ��1ms
}



void Delay_ms(__IO uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0);
}


/*******************************************************************************
* Function Name :void SysTick_Handler(void)
* Description   :ϵͳ��ʱ�ж�
* Input         :
* Output        :
* Other         :
* Date          :2015-7-1 18:46:33
*******************************************************************************/
void SysTick_Handler(void)
{
	 if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}
/*******************************************************************************
* Function Name :void InterruptOrder(void)
* Description   :�ж����������ȼ�
* Input         :
* Output        :
* Other         :
* Date          :2015-7-1 18:46:41
*******************************************************************************/
void NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4);//���ȼ�����  ȫΪ��ռʽ���ȼ�
}

/*******************************************************************************
* Function Name :void SystemConfig(void)
* Description   :ϵͳ��ʼ��
* Input         :
* Output        :
* Other         :
* Date          :2015-7-1 18:46:46
*******************************************************************************/
void BSP_Init(void)
{
    NVIC_Configuration();	//�ж����ȼ�����
    GPIO_Configuration();	//
}


/*******************************************************************************
* Function Name : void BSP_GpioSet(u32 n)
* Description   : IO �ø�
* Input         : 
* Output        : 
* Other         : 
* Date          : 2015-7-1 18:46:54
*******************************************************************************/
void BSP_GpioSet(int n)
{
    if (n < 0) return;
    if (n >= eGPIO_MAX_COUNT) return;
    
    m_PortInfo[n].port->BSRR = m_PortInfo[n].pin;
}


/*******************************************************************************
* Function Name : void BSP_GpioReset(u32 n)
* Description   : IO �õ�
* Input         : 
* Output        : 
* Other         : 
* Date          : 2013.07.21
*******************************************************************************/
void BSP_GpioReset(int n)
{
    if (n < 0) return;
    if (n >= eGPIO_MAX_COUNT) return;
    
    m_PortInfo[n].port->BRR = m_PortInfo[n].pin;
}

/*******************************************************************************
* Function Name : void BSP_GpioToggle(int n)
* Description   : IO ��ƽ��ת
* Input         : 
* Output        : 
* Other         : 
* Date          : 2014.10.11
*******************************************************************************/
void BSP_GpioToggle(int n)
{
    if (n < 0) return;
    if (n >= eGPIO_MAX_COUNT) return;
    
    m_PortInfo[n].port->ODR ^= m_PortInfo[n].pin;
}


/*******************************************************************************
* Function Name : int32_t BSP_GpioRead(int32_t n)
* Description   : ��GPIO
* Input         : 
* Output        : ���󷵻� -1
* Other         : 
* Date          : 2013.12.29
*******************************************************************************/
int32_t BSP_GpioRead(int32_t n)
{
    if (n < 0) return -1;
    if (n >= eGPIO_MAX_COUNT) return -1;

    return GPIO_ReadInputDataBit(m_PortInfo[n].port, m_PortInfo[n].pin);
}

/*******************************************************************************
* Function Name : void BSP_PortWrite(int32_t n, int32_t value)
* Description   : �˿�д����
* Input         : 
* Output        : 
* Other         : 
* Date          : 2014.03.25
*******************************************************************************/
void BSP_PortWrite(int32_t n, int32_t value)
{
    if (n < 0) return;
    if (n >= eGPIO_MAX_COUNT) return;

    m_PortInfo[n].port->BSRR = value | ((value ^ 0xFF) << 16); 
}

/*******************************************************************************
* Function Name : void BSP_SystemReset(void)
* Description   : ϵͳ��λ
* Input         : 
* Output        : 
* Other         : 
* Date          : 2014.08.25
*******************************************************************************/
void BSP_SystemReset(void)
{
    NVIC_SystemReset();
}


