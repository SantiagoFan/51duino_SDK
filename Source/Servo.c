/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
*/
#include "stc_new_8051.h"
#include "timer.h"
#include "steer.h"
#include "MEM.h"
#include "uart.h"
#include "Servo.h"
#include "config.h"

uint16 se_timer[8]={SE1_Deg,SE2_Deg,SE3_Deg,SE4_Deg,SE5_Deg,SE6_Deg,SE7_Deg,SE8_Deg};//8·������ƽӿڣ�SE1_Deg��Ӧ1�Ŷ����
/*
  SetServoAngle(uint16 servoNum,uint16 angle)����
  ���ã����ö��ת���Ƕ�
  ������servoNum-�����ţ���Χ��1-8����angle-�˶��ת���ĽǶȣ���Χ��0-160��
  ����ֵ����
  powered by liuviking
*/
void SetServoAngle(uint16 servoNum,uint16 angle)
{
    if(servoNum>8)return;
	if(servoNum<0)return;
	if(angle>160)return;
	if(angle<0)return;
	se_timer[servoNum-1]=angle;
}
/*
  Init_Steer(void)����
  ���ã���ʼ�������ͨ���Ƕ�ֵ����EEPROM�����ж�ȡ
  ��������
  ����ֵ����
  powered by liuviking
*/
void Init_Steer(void)
{
	uint8 CheckServoAngleCount=0;
	uint8 OrginalAngle=0;
	uint8 i;
	for(i=1;i<9;i++)
	{
		  OrginalAngle= Read_Byte(50*512+i);
		  if(OrginalAngle == 0xFF)
		  {
		  	CheckServoAngleCount++;
		  }
	}

	if(CheckServoAngleCount==8)return;
    
	for(i=1;i<9;i++)
	{	
		 SetServoAngle(i,Read_Byte(50*512+i)); //100*512�Ƕ���Ƕȴ洢λ��
	}
	
}
/*
  GetServoAngle(uint16 servoNum)����
  ���ã���ȡָ������ӿڵĽǶ�ֵ
  ������servoNum-��Ҫ��ȡ�Ķ���ڱ�ţ���Χ��1-8��
  ����ֵ���Ƕȣ���Χ0-160��
  powered by liuviking
*/
uchar GetServoAngle(uint16 servoNum)
{
    if(servoNum>8)return;
	if(servoNum<1)return;
	return (uchar)se_timer[servoNum-1];
}
