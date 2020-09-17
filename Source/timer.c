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
#include "IR.h"
#include "MEM.h"
#include "uart.h"
#include "Servo.h"
#include "motor.h"
extern uint8 rec_flag;
extern uint16 Sampling_cnt;
extern bit IR_38K_En;
extern bit IR_R_T; 
extern bit IR_EN;
uint16 Uart_timeout_count=0;
extern void Steering_Engine_Control(void);
extern uint8 Left_Speed;
extern uint8 Right_Speed;
/*
  Delay_Ms(uint32 t)函数
  作用：延迟指定时间，单位毫秒
  参数：毫秒数
  返回值：无
  powered by tianyalu
*/
void Delay_Ms(uint32 t)
{  
    uint16 i;
	while(t--)
	{
	   for(i=0;i<1050;i++);
	}
}
/*
  Timer0_Init(void)函数
  作用：定时器0初始化函数，设置模式、优先级、中断开关
  参数：无
  返回值：无
  powered by tianyalu
*/
void Timer0_Init(void)
{
	TMOD   &=   0xf0; 
    TMOD   |=   0x01; 
	AUXR   |=   0XC0;
	IP   |=   0x02;//定时器0中断优先级最高
	TR0=1;
	ET0=1;
}
/*
  Timer1_Init(void)函数
  作用：定时器1初始化函数，设置模式、优先级、中断开关
  参数：无
  返回值：无
  powered by tianyalu
*/
void Timer1_Init(void)
{
    ET1     =	  1;
    TMOD   &=   0x0f; 
    TMOD   |=   0x10;   
    TH1     =   0xA9;   //1MS定时
    TL1     =   0x9A;
    TR1     =   1;    //开定时器1

}
/*
  Timer_0(void) interrupt 1函数
  作用：定时器0中断服务函数，用作舵机控制或红外遥控电视
  参数：无
  返回值：无
  powered by tianyalu
*/
void Timer_0(void) interrupt 1 
{
	if(IR_EN ==1)
	{
		Timer_For_IR();
	}
	else
	{
		Steering_Engine_Control();
	}
}
/*
  Timer_1(void) interrupt 3函数
  作用：定时器1中断服务函数，可自由使用，目前用作左右电机速度调整和串口通信检测
  参数：无
  返回值：无
  powered by tianyalu
*/
void Timer_1(void) interrupt 3
{	 
    static uint16 ms_count=0;
	static uchar _100us_count=0;
	//TH1     =   0xA9;   
    //TL1     =   0x9A;

	Uart_timeout_count++;
	if((Uart_timeout_count == 1000) && (rec_flag)) //串口接收1秒超时
	{
		rec_flag = 0;
	}

	if(ms_count++ >= 1000)
	{
	     ms_count = 0;
		 if(rec_flag)
		 {
		     LED5 = ~LED5;
		 }
		 else
		 {
		     LED5 = 1;
		 }
	}
	 

 

	 TH1     =   0xF7;   
     TL1     =   0x5C; //10KHZ频率定时

	 _100us_count++;

	 if(_100us_count <= Left_Speed) //左侧占空比，1KHz
	 {
	     MOTOR_A_EN = 1;
	 }
	 else
	 {
	     MOTOR_A_EN = 0;
	 }

	 if(_100us_count <= Right_Speed)	//右侧占空比，1KHz
	 {
	     MOTOR_B_EN = 1;
	 }
	 else
	 {
	     MOTOR_B_EN = 0;
	 }

	 if(10 == _100us_count)
	 {
	      _100us_count = 0;
		  MOTOR_A_EN = 0;
		  MOTOR_B_EN = 0;
	 }
	 	
}
