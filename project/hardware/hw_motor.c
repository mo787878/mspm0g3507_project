#include "hw_motor.h"


//设置电机1速度
static void set_motor_1_speed(int speed_value)
{ 
  int speed = speed_value;
  if(speed > MOTOR_PWM_MAX)
  {
	  speed = MOTOR_PWM_MAX;
  }
  if(speed < 0)
  {
	  speed = 0;
  }
  DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,speed,GPIO_PWM_MOTOR_C0_IDX);
}
//设置电机2速度
static void set_motor_2_speed(int speed_value)
{
  int speed = speed_value;
  if(speed > MOTOR_PWM_MAX)
  {
	  speed = MOTOR_PWM_MAX;
  }
  if(speed < 0)
  {
	  speed = 0;
  }
  DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,speed,GPIO_PWM_MOTOR_C1_IDX);
}
//设置电机状态,0代表反转（车向后）,1代表正转（车向前），2代表制动，3代表停止
static void set_motor_1_status(int speed_status)
{
	if(speed_status == 0)
	{
		DL_GPIO_clearPins(motor_AIN1_PORT,motor_AIN1_PIN );
		DL_GPIO_setPins(motor_AIN2_PORT,motor_AIN2_PIN );
	}
	if(speed_status == 1)
	{
		DL_GPIO_clearPins(motor_AIN2_PORT,motor_AIN2_PIN );
		DL_GPIO_setPins(motor_AIN1_PORT,motor_AIN1_PIN );
	}
	if(speed_status == 2)
	{
		DL_GPIO_setPins(motor_AIN1_PORT,motor_AIN1_PIN );
		DL_GPIO_setPins(motor_AIN2_PORT,motor_AIN2_PIN );
	}
	if(speed_status == 3)
	{
		DL_GPIO_clearPins(motor_AIN1_PORT,motor_AIN1_PIN );
		DL_GPIO_clearPins(motor_AIN2_PORT,motor_AIN2_PIN );
		set_motor_1_speed(0);
	}
}
static void set_motor_2_status(int speed_status)
{
	if(speed_status == 0)
	{
		DL_GPIO_clearPins(motor_BIN1_PORT,motor_BIN1_PIN );
		DL_GPIO_setPins(motor_BIN2_PORT,motor_BIN2_PIN );
	}
	if(speed_status == 1)
	{
		DL_GPIO_clearPins(motor_BIN2_PORT,motor_BIN2_PIN );
		DL_GPIO_setPins(motor_BIN1_PORT,motor_BIN1_PIN );
	}
	if(speed_status == 2)
	{
		DL_GPIO_setPins(motor_BIN1_PORT,motor_BIN1_PIN );
		DL_GPIO_setPins(motor_BIN2_PORT,motor_BIN2_PIN );
	}
	if(speed_status == 3)
	{
		DL_GPIO_clearPins(motor_BIN1_PORT,motor_BIN1_PIN );
		DL_GPIO_clearPins(motor_BIN2_PORT,motor_BIN2_PIN );
		set_motor_2_speed(0);
	}
}
//控制电机的旋转速度与方向
void set_motor_speed_status(int motor,int speed_value,int speed_status)
{
	if(motor == 1)
	{
		set_motor_1_speed(speed_value);
		set_motor_1_status(speed_status);	
	}
	
	if(motor == 2)
	{
		set_motor_2_speed(speed_value);
	    set_motor_2_status(speed_status);
	}
}