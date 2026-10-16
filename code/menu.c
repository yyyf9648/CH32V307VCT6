#include "menu.h"
#include "zf_common_headfile.h"
#include "key.h"
#include "led.h"
#include "buzzer.h"
int             menu_level = 0;
int             menu_index = 0;
int         menu_index_max = 3;//光标最多到第4行


int             menu_level1_n = 0;
int             menu_level2_n = 0;
int             menu_task     = 0;

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
        BUZZER_On();
    }
    if (menu_level1_n==1&&menu_level2_n==2&&menu_index==2) {//stop
        BUZZER_Off();
    }
}

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
            tft180_show_string(10,64,"pwm");
            }
            else if (menu_level1_n==2) {
            tft180_show_string(10,48,"p");
            tft180_show_string(10,64,"i");
            tft180_show_string(10,80,"d");
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
            tft180_show_string(10,48,"p+1");
            tft180_show_string(110,64,"p-1");
            }
            else if(menu_level1_n==2&&menu_level2_n==2){
            tft180_show_string(10,48,"i+0.01");
            tft180_show_string(10,64,"1-0.01");
            }
            else if(menu_level1_n==2&&menu_level2_n==3){
            tft180_show_string(10,48,"d+0.1");
            tft180_show_string(10,64,"d-0.1");
            }
            break;
    }
    tft180_show_string(0,48+menu_index*16,">");//显示光标位置
    tft180_show_string(0,16,"Menu Page");
    tft180_show_int(70,16,menu_level+1,1);
}


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

void MENU_Init(void)
{
    MENE_ShowTFT();
}

void MENU_Set_Init(void)
{
    tft180_init();
    tft180_full(RGB565_BLACK);
    tft180_set_color(RGB565_WHITE,RGB565_BLACK);
}