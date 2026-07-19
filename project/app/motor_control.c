#include "motor_control.h"
#include "stdlib.h"

// 参数定义
#define VMAX 90                              // 最大速度
#define VMIN 40								 // 最小速度
int K_V=33;	

// 全局变量声明
int SpeedL;                    // 左轮速度
int SpeedR;                    // 右轮速度
int Speed_Set = 0;             // 基准速度
float Tarangle = 0;            // 目标角度

int pwmR;
int pwmL;

/**
 * @brief 电机控制主函数，实现差速控制和PID调节
 */
void Motor_Control(void)
{
    extern int result_angle;      // 角度偏移量
    extern unsigned char Digtal;  // 数字量
	
    // 根据角度偏移量计算
    Pid_Yaw(Tarangle);
	
		//速度线性控制
    Speed_Set = VMAX - K_V * abs(result_angle)/1024;
	
    // 丢线检测和保护机制
    if (!(Digtal & 0x01)) {  // 检查第0位（丢线）
        Speed_Set = VMIN;
        Output_Yaw = 60;  // 急转
    } 
    else if (!(Digtal & 0x80)) {  // 检查第7位（丢线）
        Speed_Set = VMIN;
        Output_Yaw = -60;   // 急转
    }
    else if (Speed_Set < VMIN) {  // 正常情况下的速度下限保护
        Speed_Set = VMIN;
    }
    
    // 差速控制：根据Yaw输出调整左右轮速度
    SpeedR = (int)(Speed_Set + Output_Yaw);
    SpeedL = (int)(Speed_Set - Output_Yaw);

    // 设置电机PWM
	set_motor_speed_status(1,SpeedL,1);
	set_motor_speed_status(2,SpeedR,1);
}