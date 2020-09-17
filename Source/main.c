/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
/*
51duino_SDK二次开发源码包
版本号：V2.0
修改日期：2015-8-22
*/
#include "stc_new_8051.h"
#include "motor.h"
#include "uart.h"
#include <stdio.h>
#include "type.h"
#include "timer.h"
#include "SelfTest.h"
#include "Servo.h"
#include "LCD_12864.h"
#include "Light.h"
extern void UART_send_byte(uint8 byte);
//#define DEBUG //是否开启调试模式开关
/*
  main(void)函数
  作用：主函数入口点
  参数：无
  返回值：无
  powered by tianyalu
*/

void main(void)
{
	MainLight_Init();//大灯初始化为熄灭
	#ifndef DEBUG
	{
		TestApp_Init();//自检延时程序
	}
	#endif
	UART_init();//串口初始化
	Timer0_Init();//定时器0初始化（舵机定时器）
	Timer1_Init();//定时器1初始化
	Motor_Init();//电机初始化
	Init_Steer();//舵机角度初始化
	//Lcd_Init();//12864LCD显示屏初始化，默认关闭，根据需要放开
    while(1)
	{
  		Cruising_Mod();//全功能模式功能执行子函数
	}
}
