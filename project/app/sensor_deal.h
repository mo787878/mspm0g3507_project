#ifndef __SENSOR_DEAL_H_
#define __SENSOR_DEAL_H_

#include "ti_msp_dl_config.h"
#include "No_Mcu_Ganv_Grayscale_Sensor_Config.h"
#include "PID.h"

extern unsigned short Anolog[8];
extern unsigned short white[8];
extern unsigned short black[8];
extern unsigned short Normal[8];
extern unsigned char rx_buff[256];
extern No_MCU_Sensor sensor;              // 传感器数据结构体
extern unsigned char Digtal;

int32_t CalculateNormalizedValue(unsigned short Normal[8],uint8_t field);
void deal_with_sensor(void);

#endif