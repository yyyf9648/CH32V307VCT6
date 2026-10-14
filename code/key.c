#include "key.h"
#include "zf_common_headfile.h"

#define KEY_A0                  (D8 )                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A1                  (B12)                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A2                  (B14)                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A0_EXTI               (EXTI9_5_IRQn)                                  // 对应外部中断的中断编号
#define KEY_A1_EXTI               (EXTI15_10_IRQn)                                  // 对应外部中断的中断编号
#define KEY_A2_EXTI               (EXTI15_10_IRQn)                                // 对应外部中断的中断编号

#define KEY_TIM                  (TIM_6 )                                      // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用
#define KEY_CH                  (TIM6_PIT )                                      // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用
#define KEY_PRIORITY            (TIM6_IRQn)                                      // 对应周期中断的中断编号

int KEY0_num=1;
int KEY1_num=1;
int KEY2_num=1;
int KEY_Flag=0;
volatile int KEY_Num=7;
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键状态获取函数
// 参数说明     void
// 返回参数     void
// 使用示例     KEY_Get_num();
//-------------------------------------------------------------------------------------------------------------------
uint8 KEY_Get_num(void)
{
    uint8 a0 = gpio_get_level(KEY_A0);
    uint8 a1 = gpio_get_level(KEY_A1);
    uint8 a2 = gpio_get_level(KEY_A2); 
    uint8 code = (a2 << 2) | (a1 << 1) | a0;
    return code;
}
//         case 0: return "KEY1"; // 输入7
//         case 1: return "M";    // 输入6
//         case 2: return "L";    // 输入5
//         case 3: return "KEY2"; // 输入4
//         case 4: return "D";    // 输入3
//         case 5: return "U";    // 输入2
//         case 6: return "R";    // 输入1
//         case 7: return "None"; // 无按键按下
//         default:    return "ERROR";
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键初始化函数，按键外部中断和消抖定时器的初始化
// 参数说明     void
// 返回参数     void
// 使用示例     KEY_Get_num();
//-------------------------------------------------------------------------------------------------------------------
void KEY_Init(void)
{
    exti_init(KEY_A0, EXTI_TRIGGER_FALLING);                                      // 初始化 KEY1 为外部中断输入 下降沿触发
    exti_init(KEY_A1, EXTI_TRIGGER_FALLING);                                      // 初始化 KEY2 为外部中断输入 下降沿触发
    exti_init(KEY_A2, EXTI_TRIGGER_FALLING);                                      // 初始化 KEY3 为外部中断输入 下降沿触发
  
    interrupt_set_priority(KEY_A0_EXTI, (1<<5) | 1);                             // 设置 KEY1 对应外部中断的中断抢占优先级0，子优先级1
    interrupt_set_priority(KEY_A1_EXTI, (1<<5) | 2);                             // 设置 KEY3 对应外部中断的中断抢占优先级0，子优先级1
    interrupt_set_priority(KEY_A2_EXTI, (1<<5) | 3);                             // 设置 KEY4 对应外部中断的中断抢占优先级0，子优先级1

    pit_ms_init(KEY_CH, 50);                                                    // 初始化  为周期中断 10ms 周期
    interrupt_set_priority(KEY_PRIORITY, 1);                                    // 设置 PIT1 对周期中断的中断优先级为 0
    pit_disable(KEY_CH);                                   
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键外部中断处理函数 这个函数将在对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key1_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key0_exti_handler (void)
{
    if(KEY_Flag==0)
    {
        KEY_Flag=1;
        
        pit_enable(KEY_CH);
        timer_start(KEY_TIM);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键外部中断处理函数 这个函数将在对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key2_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key1_exti_handler (void)
{
    if(KEY_Flag==0)
    {
        KEY_Flag=1;
        
        pit_enable(KEY_CH);
        timer_start(KEY_TIM);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键外部中断处理函数 这个函数将在对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key2_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key2_exti_handler (void)
{
    if(KEY_Flag==0)
    {
        KEY_Flag=1;
        
        pit_enable(KEY_CH);
        timer_start(KEY_TIM);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     按键消抖
// 参数说明     void
// 返回参数     void
// 使用示例     key_timer_handler();
//-------------------------------------------------------------------------------------------------------------------
void key_timer_handler(void)
{
    KEY_Num=KEY_Get_num();
    if(KEY_Get_num()!=7)
    {
        KEY_Flag=2;
    }
    else 
    {
        KEY_Flag=0;
    }
    timer_stop(KEY_TIM);
    timer_clear(KEY_TIM);
    pit_disable(KEY_CH);                                   
}