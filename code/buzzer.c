// #include "menu.h"
#include "zf_common_headfile.h"
// #include "key.h"
// #include "led.h"
#include "buzzer.h"

#define PWM_CH TIM1_PWM_MAP0_CH1_A8



void BUZZER_Init(void)
{
    pwm_init(PWM_CH,0,0);//523
}

void BUZZER_Music1_On(void)
{
    pwm_set_freq(PWM_CH,262,5000);
}

void BUZZER_Music2_On(void)
{
    pwm_set_freq(PWM_CH,523,5000);
}

void BUZZER_Off(void)
{
    pwm_set_duty(PWM_CH,0);
}