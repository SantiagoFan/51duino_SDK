/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#include "stc_new_8051.h"
#include "timer.h"
#include "steer.h"
#include "MEM.h"
#include "uart.h"
#include "Servo.h"
#include "config.h"

uint16 se_timer[8]={SE1_Deg,SE2_Deg,SE3_Deg,SE4_Deg,SE5_Deg,SE6_Deg,SE7_Deg,SE8_Deg};//8路舵机控制接口，SE1_Deg对应1号舵机口
/*
  SetServoAngle(uint16 servoNum,uint16 angle)函数
  作用：设置舵机转动角度
  参数：servoNum-舵机编号（范围：1-8），angle-此舵机转动的角度（范围：0-160）
  返回值：无
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
  Init_Steer(void)函数
  作用：初始化各舵机通道角度值，从EEPROM扇区中读取
  参数：无
  返回值：无
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
		 SetServoAngle(i,Read_Byte(50*512+i)); //100*512是舵机角度存储位置
	}
	
}
/*
  GetServoAngle(uint16 servoNum)函数
  作用：获取指定舵机接口的角度值
  参数：servoNum-需要获取的舵机口编号（范围：1-8）
  返回值：角度（范围0-160）
  powered by liuviking
*/
uchar GetServoAngle(uint16 servoNum)
{
    if(servoNum>8)return;
	if(servoNum<1)return;
	return (uchar)se_timer[servoNum-1];
}
