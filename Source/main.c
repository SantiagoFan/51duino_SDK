/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
/*
51duino_SDK���ο���Դ���
�汾�ţ�V2.0
�޸����ڣ�2015-8-22
*/
#include "stc_new_8051.h"
#include "motor.h"
#include "uart.h"
#include <stdio.h>
#include "type.h"
#include "timer.h"
#include "SelfTest.h"
#include "Servo.h"
#include "LCD_12864.h"
#include "Light.h"
extern void UART_send_byte(uint8 byte);
//#define DEBUG //�Ƿ�������ģʽ����
/*
  main(void)����
  ���ã���������ڵ�
  ��������
  ����ֵ����
  powered by tianyalu
*/

void main(void)
{
	MainLight_Init();//��Ƴ�ʼ��ΪϨ��
	#ifndef DEBUG
	{
		TestApp_Init();//�Լ���ʱ����
	}
	#endif
	UART_init();//���ڳ�ʼ��
	Timer0_Init();//��ʱ��0��ʼ���������ʱ����
	Timer1_Init();//��ʱ��1��ʼ��
	Motor_Init();//�����ʼ��
	Init_Steer();//����Ƕȳ�ʼ��
	//Lcd_Init();//12864LCD��ʾ����ʼ����Ĭ�Ϲرգ�������Ҫ�ſ�
    while(1)
	{
  		Cruising_Mod();//ȫ����ģʽ����ִ���Ӻ���
	}
}
