/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#ifndef _IR_H_
#define _IR_H_

#include "type.h"
#include "stc_new_8051.h"
#include "config.h"
#define IR_SEND_LED_ON	 LED4=1;LED5=0;LED6=1
#define IR_SEND_LED_OFF	 LED4=0;LED5=1;LED6=0;
void IR_Rec(void);//��������Ӻ���
void IR_Tra(void);//���ⷢ���Ӻ���
void Timer_For_IR(void);  //���ⶨʱ��

#endif