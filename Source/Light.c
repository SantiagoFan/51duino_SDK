/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#include "Light.h"
#include "config.h"
#include "type.h"
#include "stc_new_8051.h"
/*P22��ƿ���Э�飺FF040100FF����  FF040000FF�ص�*/

/*
  MainLight_Init(void)����
  ���ã���Ƴ�ʼ���������ϵ��Ĭ�Ϲرա����Ĭ��ΪP22�ڣ���������ʽ��LED���Ž�51duino P22�ڵ�+�����̽Ž�P22��-����
  ��������
  ����ֵ����
  powered by liuviking
*/
void MainLight_Init(void)
{
	 MAIN_LIGHT_OFF;
}

/*
  OpenMainLight(void)����
  ���ã�������ƺ��������Ĭ��ΪP22�ڣ���������ʽ
  ��������
  ����ֵ����
  powered by liuviking
*/
void OpenMainLight(void)
{
	 MAIN_LIGHT_ON;
}

/*
  CloseMainLight(void)����
  ���ã��رմ�ƺ��������Ĭ��ΪP22�ڣ���������ʽ
  ��������
  ����ֵ����
  powered by liuviking
*/
void CloseMainLight(void)
{
	 MAIN_LIGHT_OFF;
}

