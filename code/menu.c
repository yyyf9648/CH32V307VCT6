#include "menu.h"
#include "zf_common_headfile.h"
#include "key.h"
#include "led.h"
int             menu_level = 0;
int             menu_index = 0;


int             menu_level1_n = 0;
int             menu_level2_n = 0;
int             menu_task     = 0;
void MENU_Func(void)
{
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==0) {
        LED_On();
    }
    if (menu_level1_n==1&&menu_level2_n==1&&menu_index==1) {
        LED_Off();
    }
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
            if(menu_index>2){menu_index=2;};
            break;
        case 5://向上移动光标
            menu_index--;
            if(menu_index<0){menu_index=0;}
            break;
    }
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
            tft180_show_string(10,48,"start");
            tft180_show_string(10,64,"stop");
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
    switch (menu_index) {
        case 0:
        tft180_show_string(0,48,">");break;
        case 1:
        tft180_show_string(0,64,">");break;
        case 2:
        tft180_show_string(0,80,">");break;
    }
    // tft180_show_string(0,16,"menu level");
    // tft180_show_int(90,16,menu_level,1);
    // tft180_show_string(0,32,"menu_index");
    // tft180_show_int(90,32,menu_index,1);
    tft180_show_string(0,16,"Menu Page");
    tft180_show_int(70,16,menu_level+1,1);
}

void MENU_Init(void)
{
    // tft180_show_string(0,16,"menu level");
    // tft180_show_int(90,16,menu_level,1);
    // tft180_show_string(0,32,"menu_index");
    // tft180_show_int(90,32,menu_index,1);
    tft180_show_string(0,16,"Menu Page");
    tft180_show_int(90,16,menu_level+1,1);
    tft180_show_string(10,48,"Function");
    tft180_show_string(10,64,"pid adjust");
    tft180_show_string(0,48,">");
}