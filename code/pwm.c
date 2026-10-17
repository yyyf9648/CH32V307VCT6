#include "menu.h"
#include "zf_common_headfile.h"
#include "key.h"
#include "led.h"
#include "pwm.h"
uint8 pwm_speed =   0 ;
uint8 pwm_p     =   0 ;
float pwm_i     = 0.001f;
float pwm_d     = 0.01f;

void PWM_Init(void)
{           
    tft180_show_string(0,112,"speed:");
    tft180_show_string(80,112,"p:");
    tft180_show_string(0,128,"i:");
    tft180_show_string(65,128,"d:");
    // pwm_speed=30;
    // pwm_p=5;
    // pwm_i=0.01;
    // pwm_d=0.2;
}

void PWM_Refresh(void)
{
    tft180_show_int(48,112,pwm_speed,3);
    tft180_show_int(95,112,pwm_p,3);
    tft180_show_float(15,128,pwm_i,1,3);
    tft180_show_float(80,128,pwm_d,1,2);
}