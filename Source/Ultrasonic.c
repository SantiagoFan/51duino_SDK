/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/

#include "config.h"
#include "ultrasonic.h"
#include "motor.h"
#include "uart.h"
/*
  Send_wave(void)����
  ���ã����������ͺ���
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Send_wave(void)
{
    uint16 i;

	Trig = 1;
	for(i=0;i<150;i++);
	Trig = 0;
}
/*
  Get_Distance(void)����
  ���ã����������պ��������������ϰ���ľ���ֵ
  ��������
  ����ֵ����
  powered by tianyalu
*/
uchar Get_Distance(void)
{
    uint32 Distance = 0;

    Send_wave();
    TH1 = 0;
    TL1 = 0;
	while(TH1<250 && Echo!= 1);	  
	if(TH1 <= 250)	//��෶Χ<0.5M
	{
	   TH1 = 0;
	   TL1 = 0;
	   while(Echo == 1);
	   Distance = TH1;
	   Distance = Distance*256;
	   Distance = Distance + TL1;
	   Distance = Distance * 17; 
	   Distance = Distance / 22118; 
	   return (uchar)(Distance&0xFF);
	}
}
/*
  AvoidByRadar(void)����
  ���ã�ȫ���ܳ������״���Ϻ�����̽�⵽ǰ���ϰ�ʱͣ��
  ��������
  ����ֵ����
  powered by tianyalu
*/
void AvoidByRadar(void)
{
   if(Get_Distance()<0x0A)//����״�ز�����С��10���״���
	{
		 MOTOR_GO_STOP;
	}
	else
	{
	  MOTOR_GO_FORWARD;
	}

}
/*
  Send_Distance(void)����
  ���ã��������״��ಢ�ش�������ͨ��Э��FF 03 00 ����ֵ FF ��ÿ��1�뷢��һ��
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Send_Distance(void)
{
	   UART_send_byte(0xFF);
	   UART_send_byte(0x03);
	   UART_send_byte(0x00);
	   UART_send_byte(Get_Distance());
	   UART_send_byte(0xFF);
	   Delay_Ms(1000);   
}
