/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "config.h"
#include "stc_new_8051.h"

#define LIGHT_TYPE_IRRIGATION 0//�������͹����
#define LIGHT_TYPE_PULL  1//��������������

#define MAIN_LIGHT_ON MainLight=1  //P22�ڴ�ƿ���������������ʽ
#define MAIN_LIGHT_OFF MainLight=0	//P22�ڴ�ƹرգ�����������ʽ
void MainLight_Init(void);
void OpenMainLight(void);
void CloseMainLight(void);
void OpenSpecifyLight(bit,uint16);
#endif