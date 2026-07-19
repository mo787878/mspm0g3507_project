#include "PID.h"
#include "delay.h"

// 偏航角PID参数
int Kp_Yaw = 10;  // 比例系数
int Ki_Yaw = 0;   // 积分系数
int Kd_Yaw = 50;   // 微分系数

int Yaw_Now_Correct;      // 当前偏航角校正值
int Integral_Yaw = 0;     // 积分项累加器
int Err_Yaw = 0;          // 当前误差
int LastErr_Yaw = 0;      // 上一次误差
int Output_Yaw = 0;       // PID输出
int result_angle = 0;     // 角度结果
int max = 100;            // 输出限幅最大值

#define INTEGRAL_MAX 5    // 积分上限
#define INTEGRAL_MIN -5   // 积分下限

/**
  * @brief  偏航角PID控制
  * @param  Target: 目标角度
  */
void Pid_Yaw(float Target)
{
    Yaw_Now_Correct = result_angle;
    Err_Yaw = Target - Yaw_Now_Correct;
    
    // 积分项处理
    Integral_Yaw += Err_Yaw;
    if (Integral_Yaw > INTEGRAL_MAX) Integral_Yaw = INTEGRAL_MAX;
    if (Integral_Yaw < INTEGRAL_MIN) Integral_Yaw = INTEGRAL_MIN;
    
    // PID计算
    Output_Yaw = ((Kp_Yaw * Err_Yaw) /1024) + 
                 ((Kd_Yaw * (Err_Yaw - LastErr_Yaw)) /1024) + 
                 ((Ki_Yaw * Integral_Yaw) /1024);
    
    LastErr_Yaw = Err_Yaw;
    
    // 输出限幅
    if (Output_Yaw > max) Output_Yaw = max;
    if (Output_Yaw < -max) Output_Yaw = -max;
}