/*
 * RL.c
 *
 *  Created on: 2023��7��7��
 *      Author: bink
 */
#include "RL.h"
#include"Communication\uart_to_pc.h"

uint8_t LineSensor_Read(uint32_t time)
{
    uint8_t result;

    //P5.3����ߵ�ƽ,�򿪺��ⷢ���
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
    //P7.0-7.7��������Ϊ���
    GPIO_setAsOutputPin(GPIO_PORT_P7, PIN_ALL8);
    //����P7.0-7.7����ߵ�ƽ
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, PIN_ALL8);
    //��ʱ10us
    delay_us(10);
    //P7.0-7.7��������Ϊ����
    GPIO_setAsInputPin(GPIO_PORT_P7, PIN_ALL8);
    //��ʱ�ض�ʱ��
    delay_us(time);
    //��ȡP7.0-7.7������ֵ
    result = P7->IN;

    //P5.3����͵�ƽ,�رպ��ⷢ���
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
    //���ض˿ڶ�ȡֵ
    return result;
}
void DataPro(uint8_t SensorArray[], uint8_t* sum,uint8_t* left,uint8_t* right)
{
    *sum = 0;
    volatile uint8_t i;
    val = LineSensor_Read(DEBUG_TIME);
    if (val & 0x01)//����ס�˷���1��û����ס����0
    {
        SensorArray[0] = 1;//��1��1
    }
    else
    {
        SensorArray[0] = 0;
    }
    if (val & 0x02) {
         SensorArray[1] = 1;
    }
    else
    {
        SensorArray[1] = 0;
    }
    if (val & 0x04) {
        SensorArray[2] = 1;
    }
    else {
        SensorArray[2] = 0;
    }
    if (val & 0x08) {
        SensorArray[3] = 1;
    }
    else {
        SensorArray[3] = 0;
    }
    if (val & 0x10) {
        SensorArray[4] = 1;
    }
    else {
        SensorArray[4] = 0;
    }
    if (val & 0x20) {
        SensorArray[5] = 1;
    }
    else {
        SensorArray[5] = 0;
    }
    if (val & 0x40) {
        SensorArray[6] = 1;
    }
    else {
        SensorArray[6] = 0;
    }
//    if (val & 0x80) {
//        SensorArray[7] = 1;
//    }
//    else {
//        SensorArray[7] = 0;
//    }

    //�����Ӧ���Ĵ���������
//    findStatusOfSensor();
    for (i = 0; i < SENSOR_NUMBER-1; i++)
    {
        *sum += SensorArray[i];
    }
    for(i= 0;i< (SENSOR_NUMBER/2-1);i++)
    {
        *left += SensorArray[i];
    }
    for(i=SENSOR_NUMBER/2;i<(SENSOR_NUMBER-1);i++)
    {
        *right += SensorArray[i];
    }
}



