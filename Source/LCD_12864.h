/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#ifndef _LCD_12864_H_
#define _LCD_12864_H_

#include "type.h"
#include "config.h"
#include "stc_new_8051.h"
#include "timer.h"

void LCD_SendByte(uint8 Dbyte);//����һ���ֽ�
void Wricom( uint8 Cbyte );//��������
void Wridat( uint8 Dbyte );//��������
void Dis_string( uint8 row,
                 uint8 col,
				 uint8 *puts );//��ʾ�ַ��� (��ָ��λ��)
void Dis_string1( uint8 row,
                 uint8 col,
				 uint8 *puts );	//��ʾ�ַ���(����ҳ��ʾ)
void Dis_bmp(uint8 *puts);//��ʾͼ�� 
void Lcd_Init(void); //12864��ʼ��
void Clear_txt( void );	//���ı�����(дASCII��)
void Clear_bmp( void );//��ͼ�񣨶�Ӧλд0��1��


#endif
