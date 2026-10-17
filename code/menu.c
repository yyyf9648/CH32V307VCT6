#include "menu.h"
#include "zf_common_headfile.h"
#include "key.h"
#include "led.h"
#include "buzzer.h"
#include "pwm.h"

int             menu_level = 0;
int             menu_index = 0;
int         menu_index_max = 3;//光标最多到第4行

int             menu_level1_n = 0;
int             menu_level2_n = 0;
int             menu_task     = 0;

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     在最后一页实现功能
// 参数说明     void
// 返回参数     void
// 使用示例     MENU_Func();
//-------------------------------------------------------------------------------------------------------------------
void MENU_Func(void)
{
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==0) {//on
        LED_On();
    }
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==1) {//off
        LED_Off();
    }
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==2) {//start TIM
        LED_TIM_On();
    }
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==3) {//close TIM
        LED_TIM_Off();
    }
    if (menu_level1_n==1&&menu_level2_n==2&&menu_index==0) {//start music1
        BUZZER_Music1_On();
    }
    if (menu_level1_n==1&&menu_level2_n==2&&menu_index==1) {//start music2
        BUZZER_Music2_On();
    }
    if (menu_level1_n==2&&menu_level2_n==1&&menu_index==0) {//speed+5
        pwm_speed=pwm_speed+5;
    }
    if (menu_level1_n==2&&menu_level2_n==1&&menu_index==1) {//speed-5
        pwm_speed=pwm_speed-5;
    }
    if (menu_level1_n==2&&menu_level2_n==2&&menu_index==0) {//p+1
        pwm_p=pwm_p+1;
    }
    if (menu_level1_n==2&&menu_level2_n==2&&menu_index==1) {//p-1
        pwm_p=pwm_p-1;
    }
    if (menu_level1_n==2&&menu_level2_n==3&&menu_index==0) {//i+0.01
        pwm_i=pwm_i+0.01;
    }
    if (menu_level1_n==2&&menu_level2_n==3&&menu_index==1) {//i-0.01
        pwm_i=pwm_i-0.01;
    }
    if (menu_level1_n==2&&menu_level2_n==4&&menu_index==0) {//d+0.1
        pwm_d=pwm_d+0.1;
    }
    if (menu_level1_n==2&&menu_level2_n==4&&menu_index==1) {//d-0.1
        pwm_d=pwm_d-0.1;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     读取当前页面和索引，显示菜单
// 参数说明     void
// 返回参数     void
// 使用示例     MENE_ShowTFT();
//-------------------------------------------------------------------------------------------------------------------
void MENE_ShowTFT(void)
{
    switch (menu_level)
    {
        case 0:
        tft180_show_string(10,48,"Function");
        tft180_show_string(10,64,"pid adjust");break;
        case 1:
            if(menu_level1_n==1){
            tft180_show_string(10,48,"led");
            tft180_show_string(10,64,"buzzer");
            }
            else if (menu_level1_n==2) {
            tft180_show_string(10,48,"speed");
            tft180_show_string(10,64,"p");
            tft180_show_string(10,80,"i");
            tft180_show_string(10,96,"d");            
            PWM_Init();
            }
            break;
        case 2:
            if(menu_level1_n==1&&menu_level2_n==1){
            tft180_show_string(10,48,"on");
            tft180_show_string(10,64,"off");
            tft180_show_string(10,80,"start TIM");
            tft180_show_string(10,96,"close TIM");
            }
            else if(menu_level1_n==1&&menu_level2_n==2){
            tft180_show_string(10,48,"start music1");
            tft180_show_string(10,63,"start music2");
            tft180_show_string(10,80,"stop");
            }
            else if(menu_level1_n==2&&menu_level2_n==1){
            tft180_show_string(10,48,"speed+5");
            tft180_show_string(10,64,"speed-5");
            }
            else if(menu_level1_n==2&&menu_level2_n==2){
            tft180_show_string(10,48,"p+1");
            tft180_show_string(10,64,"p-1");
            }
            else if(menu_level1_n==2&&menu_level2_n==3){
            tft180_show_string(10,48,"i+0.01");
            tft180_show_string(10,64,"1-0.01");
            }
            else if(menu_level1_n==2&&menu_level2_n==4){
            tft180_show_string(10,48,"d+0.1");
            tft180_show_string(10,64,"d-0.1");
            }
            break;
    }
    if(menu_level1_n==2){
        PWM_Init();
        PWM_Refresh();

    }
    tft180_show_string(0,48+menu_index*16,">");//显示光标位置
    tft180_show_string(0,16,"Menu Page");
    tft180_show_int(70,16,menu_level+1,1);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     在检测到按键时调用的函数。更新菜单页数和光标，同时把对应页数显示在TFT屏上，如果菜单到最后一页还要负责实现功能
// 参数说明     void
// 返回参数     void
// 使用示例     MENU_Refresh();
//-------------------------------------------------------------------------------------------------------------------
void MENU_Refresh(void)
{
    switch (KEY_Num) 
    {
        case 3://进入or确认         
            switch (menu_level) {
                case 0:
                menu_level1_n=menu_index+1;break;
                case 1:
                menu_level2_n=menu_index+1;break;
                case 2:
                if (menu_task==1) {
                    MENU_Func();//最低级菜单任务实现
                    menu_task=0;
                }                
                break;
            }
            menu_level++;//进入下一级菜单
            if(menu_level>2){menu_level=2;menu_task=1;}
            menu_index=0;//重置光标
            break;
        case 0://返回
            switch (menu_level) {
                case 2:
                menu_level2_n=0;break;
                case 1:
                menu_level1_n=0;break;
            }
            menu_level--;//退出到上一级菜单
            if(menu_level<0){menu_level=0;}
            menu_index=0;
            break;
        case 4://向下移动光标
            menu_index++;
            if(menu_index>menu_index_max){menu_index=menu_index_max;};
            break;
        case 5://向上移动光标
            menu_index--;
            if(menu_index<0){menu_index=0;}
            break;
    }
    MENE_ShowTFT();
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     菜单初始化，显示最开始的界面
// 参数说明     void
// 返回参数     void
// 使用示例     MENU_Init();
//-------------------------------------------------------------------------------------------------------------------
void MENU_Init(void)
{
    MENE_ShowTFT();
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     菜单设置。包括tft屏初始化，设置背景，字体
// 参数说明     void
// 返回参数     void
// 使用示例     MENU_Set_Init();
//-------------------------------------------------------------------------------------------------------------------
void MENU_Set_Init(void)
{
    tft180_init();
    tft180_full(RGB565_BLACK);
    tft180_set_color(RGB565_WHITE,RGB565_BLACK);
}