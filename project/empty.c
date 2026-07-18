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

int main(void)
{
    SYSCFG_DL_init();
	jy61pInit();
//	lcd_init();
//	LCD_BLK_Clr();
//	LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
//	LCD_BLK_Set();
//	
//	encoder_init();
//	
//	timer_init();
	
	char disp_buff1[30] = {0};
	char disp_buff2[30] = {0};
	
//	set_motor_speed_status(1,5000,1);
//	set_motor_speed_status(2,5000,1);
    
	while (1) 
	{   
		int data = (int)get_angle();
		sprintf((char *)disp_buff1,"angle= %d\r\n",data);
		uart0_send_string((char *)disp_buff1);
		delay_cycles_ms(100);
		
//		sprintf(disp_buff1,"%d ",get_encoder_1_value());
//	    
//		sprintf(disp_buff2,"%d ",get_encoder_2_value());
//	   
//		
//		LCD_ShowString(0,50,(const unsigned char *)disp_buff1,WHITE,BLUE,32,0);
//					 
//	    LCD_ShowString(0,0,(const unsigned char *)disp_buff2,WHITE,BLUE,32,0);
//        
//	    sprintf(disp_buff1,"%d ",5000);
//	    
//		sprintf(disp_buff2,"%d ",(int)get_angle());
//	   
//		LCD_ShowString(0,0,(const unsigned char *)disp_buff1,WHITE,BLUE,32,0);
//					 
//	    LCD_ShowString(0,50,(const unsigned char *)disp_buff2,WHITE,BLUE,32,0);
//	    
//		delay_cycles(CPUCLK_FREQ / 1000 * 20);
    }
	
}
//unsigned short Anolog[8]={0};
////unsigned short white[8]={1600,1600,1600,1600,1600,1600,1600,1600};
////unsigned short black[8]={300,300,300,300,300,300,300,300};
//unsigned short white[8]={102,102,102,102,102,102,102,102};
//unsigned short black[8]={94,94,94,94,94,94,94,94};
//unsigned short Normal[8];
//unsigned char rx_buff[256]={0};
///********************************************No_Mcu_Demo*******************************************/
///*****************芯片型号 MSPM0G3507 主频80Mhz ***************************************************/
///*****************引脚 AD0:PB0 AD1:PB1 AD2:PB2  !!!严格按照该顺序接线，接反或接错都会导致数据错误*****/
///*****************OUT PA27*************************************************************************/
///*****************串口 Tx PA10 Rx PA11 ************************************************************/
///*****************传感器供电需要5V电压稳定供电，否则可能无法正常使用***************************/
///*****************保证单片机和传感器共地，如果不共地无法正常使用***********************************/
///********************************************No_Mcu_Demo*******************************************/

////初始化

//No_MCU_Sensor sensor;
//unsigned char Digtal;
//int main(void)
//{
//    SYSCFG_DL_init();
//	

//		No_MCU_Ganv_Sensor_Init(&sensor,white,black);

//   //设置DMA搬运的起始地址
//    DL_DMA_setSrcAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t) &ADC0->ULLMEM.MEMRES[0]);
//    //设置DMA搬运的目的地址
//    DL_DMA_setDestAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t) &ADC_VALUE[0]);
//    //开启DMA
//    DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);
//    //开启ADC转换
//    DL_ADC12_startConversion(ADC12_0_INST);	
//	
//		Tick_delay(100);
//	
//		while (1) {
//			//无时基传感器常规任务，包含模拟量，数字量，归一化量
//			No_Mcu_Ganv_Sensor_Task_Without_tick(&sensor);
//			//获取传感器数字量结果(只有当有黑白值传入进去了之后才会有这个值！！)
//			Digtal=Get_Digtal_For_User(&sensor);			
//		    sprintf((char *)rx_buff,"Digtal %d-%d-%d-%d-%d-%d-%d-%d\r\n",(Digtal>>0)&0x01,(Digtal>>1)&0x01,(Digtal>>2)&0x01,(Digtal>>3)&0x01,(Digtal>>4)&0x01,(Digtal>>5)&0x01,(Digtal>>6)&0x01,(Digtal>>7)&0x01);
//			uart0_send_string((char *)rx_buff);
//			memset(rx_buff,0,256);
//			
//			//获取传感器模拟量结果(有黑白值初始化后返回1 没有返回 0)
//			if(Get_Anolog_Value(&sensor,Anolog)){
//			sprintf((char *)rx_buff,"Anolog %d-%d-%d-%d-%d-%d-%d-%d\r\n",Anolog[0],Anolog[1],Anolog[2],Anolog[3],Anolog[4],Anolog[5],Anolog[6],Anolog[7]);
//			uart0_send_string((char *)rx_buff);
//			memset(rx_buff,0,256);
//			}
//			
//			//获取传感器归一化结果(只有当有黑白值传入进去了之后才会有这个值！！有黑白值初始化后返回1 没有返回 0)
//			if(Get_Normalize_For_User(&sensor,Normal)){
//			sprintf((char *)rx_buff,"Normalize %d-%d-%d-%d-%d-%d-%d-%d\r\n",Normal[0],Normal[1],Normal[2],Normal[3],Normal[4],Normal[5],Normal[6],Normal[7]);
//			uart0_send_string((char *)rx_buff);
//			memset(rx_buff,0,256);
//			}
//			Tick_delay(1);
//		}
//}