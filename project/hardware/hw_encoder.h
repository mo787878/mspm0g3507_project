#ifndef _HW_ENCODER_H_
#define _HW_ENCODER_H_

#include "ti_msp_dl_config.h"

void encoder_init(void);
int get_encoder_1_value(void);
int get_encoder_2_value(void);
void encoder_value_up(void);

#endif