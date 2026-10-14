#include "menu.h"
#include "zf_common_headfile.h"
#include "key.h"

int             menu_level = 0;
int             menu_index = 0;


int             menu_level1_n = 0;
int             menu_level2_n = 0;
// void MENU_Refresh(void)
// {
//     if(menu_level==0)
//     {
//         tft180_show_string(0,32,"func");
//         tft180_show_string(0,48,"PID");
//         return;
//     }
//     if(menu_level==1&&menu_index==0)//选中第一行func时进入二级菜单
//     {
//         tft180_show_string(0,32,"led");
//         tft180_show_string(0,48,"pwm");
//         menu_flag =1;
//         menu_index=0;
//         return;
//     }
//     if(menu_level==1&&menu_index==1)//选中第二行PID时进入二级菜单
//     {
//         tft180_show_string(0,32,"p");
//         tft180_show_string(0,48,"i");
//         tft180_show_string(0,48,"d");
//         menu_flag =2;
//         menu_index=0;
//         return;
//     }


//     if(menu_level==2&&menu_index==0)//选中第一行时进入三级菜单
//     {
//         if(menu_flag==1){//此时从led进入
//             tft180_show_string(0,32,"start");
//             tft180_show_string(0,48,"stop");
//             menu_index=0;
//         }
//         if(menu_flag==2){//此时从P进入
//             tft180_show_string(0,32,"+1");
//             tft180_show_string(0,48,"-1");
//             menu_index=0;
//         }
//         return;
//     }
//     if(menu_level==2&&menu_index==1)//选中第二行时进入三级菜单
//     {
//         if(menu_flag==1)
//         {
//             tft180_show_string(0,32,"start music1");
//             tft180_show_string(0,48,"start music2");
//             tft180_show_string(0,64,"stop");
//             menu_index=0;
//         }
//         if(menu_flag==2)
//         {
//             tft180_show_string(0,32,"+1");
//             tft180_show_string(0,48,"-1");
//             menu_index=0;//重置选中的选项
//         }
//         return;
//     }
//     if(menu_level==2&&menu_index==2)
//     {
//         if(menu_flag==2)
//         {
//             tft180_show_string(0,32,"+1");
//             tft180_show_string(0,48,"-1");
//             menu_index=0;//重置选中的选项
//         }
//     }
//     return;
// }

void MENU_Refresh(void)
{
    switch (KEY_Num) 
    {
        case 3://进入or确认         
            switch (menu_level) {
                case 0:
                menu_level1_n=menu_index+1;
                case 1:
                menu_level2_n=menu_index+1;
            }
            menu_level++;//进入下一级菜单
            if(menu_level>2){menu_level=2;}
            menu_index=0;
            break;
        case 0://返回
            switch (menu_level) {
                case 2:
                menu_level2_n=0;
                case 1:
                menu_level1_n=0;
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
        tft180_show_string(0,48,"Function");
        tft180_show_string(0,64,"pid adjust");break;
        case 1:
            if(menu_level1_n==1){
            tft180_show_string(0,48,"led");
            tft180_show_string(0,64,"pwm");
            }
            else if (menu_level1_n==2) {
            tft180_show_string(0,48,"p");
            tft180_show_string(0,64,"i");
            tft180_show_string(0,80,"d");
            }
            break;
        case 2:
            if(menu_level1_n==1&&menu_level2_n==1){
            tft180_show_string(0,48,"start");
            tft180_show_string(0,64,"stop");
            }
            else if(menu_level1_n==1&&menu_level2_n==2){
            tft180_show_string(0,48,"start music1");
            tft180_show_string(0,63,"start music2");
            tft180_show_string(0,80,"stop");
            }
            else if(menu_level1_n==2&&menu_level2_n==1){
            tft180_show_string(0,48,"p+1");
            tft180_show_string(0,64,"p-1");
            }
            else if(menu_level1_n==2&&menu_level2_n==1){
            tft180_show_string(0,48,"i+0.01");
            tft180_show_string(0,64,"1-0.01");
            }
            else if(menu_level1_n==2&&menu_level2_n==2){
            tft180_show_string(0,48,"d+0.1");
            tft180_show_string(0,64,"d-0.1");
            }
            break;
    }
    tft180_show_string(0,16,"menu level");
    tft180_show_int(90,16,menu_level,1);
    tft180_show_string(0,32,"menu_index");
    tft180_show_int(90,32,menu_index,1);
}

void MENU_Init(void)
{
    tft180_show_string(0,16,"menu level");
    tft180_show_int(90,16,menu_level,1);
    tft180_show_string(0,32,"menu_index");
    tft180_show_int(90,32,menu_index,1);
    tft180_show_string(0,48,"Function");
    tft180_show_string(0,64,"pid adjust");
}