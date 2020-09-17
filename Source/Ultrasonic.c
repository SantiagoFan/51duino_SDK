/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/

#include "config.h"
#include "ultrasonic.h"
#include "motor.h"
#include "uart.h"
/*
  Send_wave(void)函数
  作用：超声波发送函数
  参数：无
  返回值：无
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
  Get_Distance(void)函数
  作用：超声波接收函数，并计算与障碍物的距离值
  参数：无
  返回值：无
  powered by tianyalu
*/
uchar Get_Distance(void)
{
    uint32 Distance = 0;

    Send_wave();
    TH1 = 0;
    TL1 = 0;
	while(TH1<250 && Echo!= 1);	  
	if(TH1 <= 250)	//测距范围<0.5M
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
  AvoidByRadar(void)函数
  作用：全功能超声波雷达避障函数，探测到前方障碍时停车
  参数：无
  返回值：无
  powered by tianyalu
*/
void AvoidByRadar(void)
{
   if(Get_Distance()<0x0A)//如果雷达回波数据小于10厘米触发
	{
		 MOTOR_GO_STOP;
	}
	else
	{
	  MOTOR_GO_FORWARD;
	}

}
/*
  Send_Distance(void)函数
  作用：超声波雷达测距并回传函数，通信协议FF 03 00 距离值 FF ；每隔1秒发送一次
  参数：无
  返回值：无
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
