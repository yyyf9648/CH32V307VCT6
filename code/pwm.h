#ifndef _PWM_H_
#define _PWM_H_

#include "zf_common_headfile.h"
extern uint8 pwm_speed;
extern uint8 pwm_p ;
extern float pwm_i ;
extern float pwm_d ;

void PWM_Init(void);
void PWM_Refresh(void);

#endif