#ifndef _hw_motor_H_
#define _hw_motor_H_

#include "ti_msp_dl_config.h"

#define MOTOR_PWM_MAX 9999

void set_motor_speed_status(int motor,int speed_value,int speed_status);

#endif