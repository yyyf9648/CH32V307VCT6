#include "led.h"
#include "zf_common_headfile.h"


void LED_On(void)
{
    gpio_set_level(LED_Left_1,1);
    gpio_set_level(LED_Left_2,1);
    gpio_set_level(LED_Left_3,1);
    gpio_set_level(LED_Left_4,1);
}

void LED_Off(void)
{
    gpio_set_level(LED_Left_1,0);
    gpio_set_level(LED_Left_2,0);
    gpio_set_level(LED_Left_3,0);
    gpio_set_level(LED_Left_4,0);
}

void LED_TIM_On(void)
{
    pit_enable(LED_CH);
}

void LED_TIM_Off(void)
{
    gpio_set_level(LED_Left_1,0);
    gpio_set_level(LED_Left_2,0);
    gpio_set_level(LED_Left_3,0);
    gpio_set_level(LED_Left_4,0);
    pit_disable(LED_CH);
}

void LED_Init(void)
{
    gpio_init(LED_Left_1, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_2, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_3, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_Left_4, GPO, 0, GPO_PUSH_PULL);

    pit_ms_init(LED_CH, 1000);                                                  // 初始化 PIT_CH0 为周期中断 1000ms 周期
    interrupt_set_priority(LED_PRIORITY, 0);                                    // 设置 PIT1 对周期中断的中断优先级为 0
     pit_disable(LED_CH);
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

