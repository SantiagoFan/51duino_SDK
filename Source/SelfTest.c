/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#include "SelfTest.h"

/*
  TestApp_Init(void)����
  ���ã��ϵ��Լ죬��ˮ����ʾ������Wi-Fiģ�����ݸ���
  ��������
  ����ֵ����
  powered by liuviking
*/
void TestApp_Init(void)
{
  
   uint16 i;
   ES=0;
   for(i=0;i<18;i++)
   {
   	   LED1=~LED1;
	   Delay_(350);
	   LED2=~LED2;
	   Delay_(350);
	   LED3=~LED3;
	   Delay_(350);
	   LED4=~LED4;
	   Delay_(350);
	   LED5=~LED5;
	   Delay_(350);
	   LED6=~LED6;
	   Delay_(350);
		
   }

  for(i=0;i<15;i++)
   {
   	   LED1=~LED1;
	   LED2=~LED2;
	   LED3=~LED3;
       LED4=~LED4;
       LED5=~LED5;
       LED6=~LED6;
	   Delay_(1000);
		
   }
   LED2=1;
   LED4=1;
   LED6=1;  	 
}

void Delay_(uint32 t)
{  
	uint16 i;
	while(t--)
	{
		for(i=0;i<1050;i++);
	}
}