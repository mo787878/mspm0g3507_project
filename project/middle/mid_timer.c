#include "mid_timer.h"
#include "hw_encoder.h"
#include "motor_control.h"
#include "sensor_deal.h"

void timer_init(void)
{
    //定时器中断
	NVIC_ClearPendingIRQ(TIMER_TICK_INST_INT_IRQN);
	NVIC_EnableIRQ(TIMER_TICK_INST_INT_IRQN);
	
	NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN );
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN );
}

void TIMER_TICK_INST_IRQHandler(void)
{
	//20ms归零中断触发
	if( DL_TimerA_getPendingInterrupt(TIMER_TICK_INST) == DL_TIMER_IIDX_ZERO )
	{
		//编码器更新
		encoder_value_up();

	}
}
//定时器的中断服务函数 已配置为0.5秒的周期
void TIMER_0_INST_IRQHandler(void)
{
	//如果产生了定时器中断
    switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://如果是0溢出中断
            deal_with_sensor();
		    Motor_Control();
            break;

        default://其他的定时器中断
            break;
    }
}