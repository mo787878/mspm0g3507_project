#include "hw_encoder.h"

volatile int encoder_1_value_temp = 0;
volatile int encoder_1_value = 0;
volatile int encoder_2_value_temp = 0;
volatile int encoder_2_value = 0;

void encoder_init(void)
{
	//清除GPIOB中断标志
	NVIC_ClearPendingIRQ(GPIO_ENCODER_INT_IRQN);
	//使能GPIOB中断
	NVIC_EnableIRQ(GPIO_ENCODER_INT_IRQN);
}
//更新编码器数据
void encoder_value_up(void)
{
	encoder_1_value = encoder_1_value_temp;
	encoder_2_value = encoder_2_value_temp;
	encoder_1_value_temp = 0;
	encoder_2_value_temp = 0;
}
//获取编码器数据
int get_encoder_1_value(void)
{
	return encoder_1_value;
}
int get_encoder_2_value(void)
{
	return encoder_2_value;
}

void GROUP1_IRQHandler(void)
{
	uint32_t gpio_status;
	
    gpio_status = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_A1_PIN | GPIO_ENCODER_PIN_A2_PIN);

    if((gpio_status & GPIO_ENCODER_PIN_A1_PIN) == GPIO_ENCODER_PIN_A1_PIN)
	{
		//如果在A1相上升沿下，B1相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B1_PIN))
		{
			encoder_1_value_temp--;
		}
		else
		{
			encoder_1_value_temp++;
		}
	}
	//编码器B相上升沿触发
	else if((gpio_status & GPIO_ENCODER_PIN_A2_PIN)==GPIO_ENCODER_PIN_A2_PIN)
	{
		//如果在A2相上升沿下，B2相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B2_PIN))
		{
			encoder_2_value_temp++;
		}
		else
		{
			encoder_2_value_temp--;
		}
	}
    DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A1_PIN|GPIO_ENCODER_PIN_A2_PIN);

}
/*void GROUP1_IRQHandler(void)//Group1的中断服务函数
{    
	//判断是否是A1相引脚的中断被触发
	 if( DL_GPIO_getRawInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A1_PIN) == GPIO_ENCODER_PIN_A1_PIN)
	 {   
		 if(DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B1_PIN) == 0)
		 {
			 encoder_1_value_temp--;
		 }
		 else
		 {
			 encoder_1_value_temp++;
		 }
	 }
	  //判断是否是B1相引脚的中断被触发
	if( DL_GPIO_getRawInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B1_PIN) == GPIO_ENCODER_PIN_B1_PIN)
	 {   
		 if(DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A1_PIN) == 0)
		 {
			 encoder_1_value_temp++;
		 }
		 else
		 {
			 encoder_1_value_temp--;
		 }
	 }
	 
	//判断是否是A2相引脚的中断被触发
	 if( DL_GPIO_getRawInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A2_PIN) == GPIO_ENCODER_PIN_A2_PIN)
	 {   
		 if(DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B2_PIN) == 0)
		 {
			 encoder_2_value_temp++;
		 }
		 else
		 {
			 encoder_2_value_temp--;
		 }
	 }
	 
	 //判断是否是B2相引脚的中断被触发
	if( DL_GPIO_getRawInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B2_PIN) == GPIO_ENCODER_PIN_B2_PIN)
	 {   
		 if(DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A2_PIN) == 0)
		 {
			 encoder_2_value_temp--;
		 }
		 else
		 {
			 encoder_2_value_temp++;
		 }
	 } 
    DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A1_PIN);
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A2_PIN);
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B1_PIN);
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B2_PIN);
	
}
*/