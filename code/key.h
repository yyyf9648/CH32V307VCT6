#ifndef _KEY_H_
#define _KEY_H_

#include "zf_common_headfile.h"
extern volatile int KEY_Num;

uint8 KEY_Get_num(void);
void KEY_Init(void);
void key0_exti_handler (void);
void key1_exti_handler (void);
void key2_exti_handler (void);
void key_timer_handler(void);
#endif