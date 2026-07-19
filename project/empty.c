#include "ti_msp_dl_config.h"
#include "hw_motor.h"
#include "string.h"
#include "hw_lcd.h"
#include "stdio.h"
#include "hw_encoder.h"
#include "mid_timer.h"
#include "bsp_gyro.h"
#include "delay.h"
#include "Uart.h"
#include "No_Mcu_Ganv_Grayscale_Sensor_Config.h"
#include "sensor_deal.h"



int main(void)
{
    SYSCFG_DL_init();
	
	jy61pInit();
	
	lcd_init();
	LCD_BLK_Clr();
	LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
	LCD_BLK_Set();
	
	//encoder_init();
	
	timer_init();
	
	No_MCU_Ganv_Sensor_Init(&sensor,white,black);

   //设置DMA搬运的起始地址
    DL_DMA_setSrcAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t) &ADC0->ULLMEM.MEMRES[0]);
    //设置DMA搬运的目的地址
    DL_DMA_setDestAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t) &ADC_VALUE[0]);
    //开启DMA
    DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);
    //开启ADC转换
    DL_ADC12_startConversion(ADC12_0_INST);	
	
		Tick_delay(100);
	
		while (1) 
		{
			Tick_delay(1);
		}
}