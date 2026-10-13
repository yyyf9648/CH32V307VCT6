#include "key.h"
#include "zf_common_headfile.h"

#define KEY_A0                  (D8 )                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A1                  (B12)                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A2                  (B14)                                           // 使用的外部中断输入引脚 如果修改 需要同步对应修改外部中断编号与 isr.c 中的调用
#define KEY_A0_EXTI               (EXTI9_5_IRQn)                                  // 对应外部中断的中断编号
#define KEY_A1_EXTI               (EXTI15_10_IRQn)                                  // 对应外部中断的中断编号
#define KEY_A2_EXTI               (EXTI15_10_IRQn)                                // 对应外部中断的中断编号

int KEY0_num=1;
int KEY1_num=1;
int KEY2_num=1;
int KEY_Flag=0;

void KEY_Show_num(void)
{
    uint8 a0 = gpio_get_level(KEY_A0);
    uint8 a1 = gpio_get_level(KEY_A1);
    uint8 a2 = gpio_get_level(KEY_A2); 
    uint8 code = (a2 << 2) | (a1 << 1) | a0;
    tft180_show_int(0,20,code,3);
}


// char* get_key_name(int a)
// {
//         switch(a)
//     {
//         case 0: return "KEY1"; // 输入7
//         case 1: return "M";    // 输入6
//         case 2: return "L";    // 输入5
//         case 3: return "KEY2"; // 输入4
//         case 4: return "D";    // 输入3
//         case 5: return "U";    // 输入2
//         case 6: return "R";    // 输入1
//         case 7: return "None"; // 无按键按下
//         default:    return "ERROR";
//     }

// }

void KEY_Init(void)
{
    exti_init(KEY_A0, EXTI_TRIGGER_FALLING);                                       // 初始化 KEY1 为外部中断输入 上升沿触发
    exti_init(KEY_A1, EXTI_TRIGGER_FALLING);                                      // 初始化 KEY2 为外部中断输入 下降沿触发
    exti_init(KEY_A2, EXTI_TRIGGER_FALLING);                                         // 初始化 KEY3 为外部中断输入 双边沿触发
  
}

// int key_flag=0;
// uint8 key_code=0b111;
// void get_key_change(void)
// {
//     if(get_key_code()!=0b111)
//     {
//         key_flag=1;
//         key_code = get_key_code();
//     }
// }
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     KEY1 的按键外部中断处理函数 这个函数将在 KEY1 引脚对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key1_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key0_exti_handler (void)
{
    // 按键变化
    KEY_Flag=1;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     KEY2 的按键外部中断处理函数 这个函数将在 KEY2 引脚对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key2_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key1_exti_handler (void)
{
    KEY_Flag=1;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     KEY3 的按键外部中断处理函数 这个函数将在 KEY3 引脚对应的外部中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     key3_exti_handler();
//-------------------------------------------------------------------------------------------------------------------
void key2_exti_handler (void)
{
    KEY_Flag=1;
}
