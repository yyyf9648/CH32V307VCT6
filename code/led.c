#include "led.h"
#include "zf_common_headfile.h"

#define LED_Left_1 		(D1 )//从左数第一个LED
#define LED_Left_2 		(A15)
#define LED_Left_3 		(A12)
#define LED_Left_4 		(A11)

#define LED_CH                  (TIM2_PIT )                                      // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用
#define LED_PRIORITY            (TIM2_IRQn)                                      // 对应周期中断的中断编号


void LED_Init(void)
{
    gpio_init(LED_Left_1, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_2, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_3, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_4, GPO, 0, GPO_PUSH_PULL);

    pit_ms_init(LED_CH, 1000);                                                  // 初始化 PIT_CH0 为周期中断 1000ms 周期
    interrupt_set_priority(LED_PRIORITY, 0);                                    // 设置 PIT1 对周期中断的中断优先级为 0

}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PIT 的周期中断处理函数 这个函数将在 PIT 对应的定时器中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     pit_handler();
//-------------------------------------------------------------------------------------------------------------------
void pit_handler (void)
{
    gpio_toggle_level(LED_Left_1);
    gpio_toggle_level(LED_Left_2);
    gpio_toggle_level(LED_Left_3);
    gpio_toggle_level(LED_Left_4);                                         // 周期中断触发 
}

