/*
 * led.c
 *
 *  Created on: 2023��7��8��
 *      Author: bink
 */


/**************************
  *
  * V1.2 2021/12/27
  * ֧��λ�����������Ч��
  *
  * V1.1 2021/9/13
  * ���������ɫ
  * ��Ϊ��֧��Multi_timer��չ��
  * ���궨���޸�Ϊ����
  *
  * V1.0 2021/8/10
  * ��ɻ�������
  *
  ************************/

#include "led.h"

void LED_Init(void)
{
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2);

    LED_RED_Off();
    LED_R_Off();
    LED_G_Off();
    LED_B_Off();
}
void LED_RED_On(void) { LED_RED = 1; }
void LED_RED_Off(void) { LED_RED = 0; }
void LED_RED_Tog(void) { LED_RED ^= 1; }

void LED_R_Off(void) { LED_R = 0;}
void LED_G_Off(void) { LED_G = 0;}
void LED_B_Off(void) { LED_B = 0; }

void LED_R_On(void) { LED_R = 1; }
void LED_G_On(void) { LED_G = 1;  }
void LED_B_On(void) { LED_B = 1;  }

void LED_R_Tog(void) { LED_R ^= 1; }
void LED_G_Tog(void) { LED_G ^= 1; }
void LED_B_Tog(void) { LED_B ^= 1; }

//��ɫ White
void LED_W_On(void)
{
    LED_R_On();
    LED_G_On();
    LED_B_On();
}
//��ɫ White
void LED_W_Off(void)
{
    LED_R_Off();
    LED_G_Off();
    LED_B_Off();
}
//��ɫ White
void LED_W_Tog(void)
{
    LED_R_Tog();
    LED_G_Tog();
    LED_B_Tog();
}
//��ɫ Yellow
void LED_Y_On(void)
{
    LED_R_On();
    LED_G_On();
    LED_B_Off();
}
//Ʒ�� Pinkish red
void LED_P_On(void)
{
    LED_R_On();
    LED_G_Off();
    LED_B_On();
}
//��ɫ Cyan
void LED_C_On(void)
{
    LED_R_Off();
    LED_G_On();
    LED_B_On();
}

void LED_Show_Staus(uint8_t num)
{
    uint8_t temp = num%7;
    switch (temp)
    {
        case 0:
            LED_R_On();
            LED_G_Off();
            LED_B_Off();
        break;
        case 1:
            LED_R_Off();
    LED_G_On();
    LED_B_Off();
        break;
        case 2:
            LED_R_Off();
    LED_G_Off();
    LED_B_On();
        break;
        case 3:
            LED_W_On();
        break;
        case 4:
            LED_Y_On();
        break;
        case 5:
            LED_P_On();
        break;
        case 6:
            LED_C_On();
        break;
        default:
            LED_RED_On();
            break;
    }
}




