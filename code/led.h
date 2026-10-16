#ifndef _LED_H_
#define _LED_H_

#include "zf_common_headfile.h"

#define LED_Left_1 		(D1 )//从左数第一个LED
#define LED_Left_2 		(A15)
#define LED_Left_3 		(A12)
#define LED_Left_4 		(A11)
#define LED_TIM                 (TIM_2)
#define LED_CH                  (TIM2_PIT )                                      // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用
#define LED_PRIORITY            (TIM2_IRQn)                                      // 对应周期中断的中断编号
void LED_On(void);
void LED_Off(void);
void LED_TIM_On(void);
void LED_TIM_Off(void);
void LED_Init(void);
void pit_handler (void);

#endif