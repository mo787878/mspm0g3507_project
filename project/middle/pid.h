#ifndef __PID_H
#define __PID_H

#include "ti_msp_dl_config.h"

// 函数声明
void Pid_Yaw(float Target);

// 外部变量声明
extern int Output_Yaw;
extern int result_angle; //灰度计算得到的角度线性偏移量
#endif