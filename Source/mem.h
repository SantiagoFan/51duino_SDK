/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#ifndef _MEM_H_
#define _MEM_H_

#include "type.h"
#include "stc_new_8051.h"

/*
  Read_Byte(uint Addr)����
  ���ã���EEPORM��ȡuchar����
  ��������ֵַ
  ����ֵ��ucharֵ
  powered by tianyalu
*/
uchar Read_Byte(uint Addr);


/*
  Write_Byte(uint Addr,uchar My_Data)����
  ���ã���ָ������д��EEPROMָ����ַ
  ������Addr-��ֵַ��My_Data-Ҫд�������
  ����ֵ����
  powered by tianyalu
*/
void Write_Byte(uint Addr,uchar My_Data);


/*
  Earse_Section(uint Addr)����
  ���ã�����EEPROM��ָ����ַ��ֵ
  ������Addr-��ֵַ
  ����ֵ����
  powered by tianyalu
*/
void Earse_Section(uint Addr);


/*
  Read_Word(uint Addr)����
  ���ã���EEPORM��ȡuint����
  ������Addr-��ֵַ
  ����ֵ��uintֵ
  powered by tianyalu
*/
uint Read_Word(uint Addr);


/*
  Write_Word(uint Addr,uint My_Data)����
  ���ã�������д��EEPROMָ����ַ
  ������Addr-ָ����ֵַ��My_Data-Ҫд�������
  ����ֵ����
  powered by tianyalu
*/
void Write_Word(uint Addr,uint My_Data);

#endif