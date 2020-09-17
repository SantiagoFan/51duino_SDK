/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#include "uart.h"
#include <stdio.h>
#include "motor.h"
#include "steer.h"
#include "mem.h"
#include "IR.h"
#include "timer.h"
#include "Servo.h"
#include "Light.h"
uint8 xdata buffer[3];
uint8 rec_flag=0;	//等于0等待接受 等于1正在接受 
extern uchar IR_Type;  
extern uchar IR_Num;
extern uchar Cruising_Flag;
extern uint16 Uart_timeout_count;
extern uint8 Left_Speed; //左侧速度
extern uint8 Right_Speed;	//右侧速度
extern uint8 Left_Speed_Hold;	//左侧速度锁存
extern uint8 Right_Speed_Hold; //右侧速度锁存
void UART_init(void)
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	BRT = RELOAD_COUNT;		//设定独立波特率发生器重装值
	AUXR |= 0x04;		//独立波特率发生器时钟为Fosc,即1T
	AUXR |= 0x01;		//串口1选择独立波特率发生器为波特率发生器
	AUXR |= 0x10;		//启动独立波特率发生器
	ES      =   1;    //允许串口中断
    EA      =   1;    //开总中断
	TI      =   1;	
	EX0=0;
	EX1=0;
}

void UART_send_byte(uint8 byte)
{
	ES     =   0;  //关串口中断
    TI     =   0;  //清零串口发送完成中断请求标志
    SBUF   =   byte;
    while(TI ==0); //等待发送完成
    TI     =   1;  //清零串口发送完成中断请求标志
    ES     =   1;  //允许串口中断
}

void UART_send(uint8 *Buffer, uint8 Length)
{
	while(Length != 0)
	{
		UART_send_byte(*Buffer);
		Buffer++;
		Length--;
	}

}

void Communication_Decode(void)  
{	
	uint8 i;

	if(buffer[0]==0x00)
	{
		switch(buffer[1])
		{	
			case 0x01:Left_Speed=Left_Speed_Hold;Right_Speed=Right_Speed_Hold;MOTOR_GO_FORWARD; return;
			case 0x02:Left_Speed=Left_Speed_Hold;Right_Speed=Right_Speed_Hold;MOTOR_GO_BACK;    return;
			case 0x03:Left_Speed=Left_Speed_Hold;Right_Speed=Right_Speed_Hold;MOTOR_GO_LEFT;    return;
		    case 0x04:Left_Speed=Left_Speed_Hold;Right_Speed=Right_Speed_Hold;MOTOR_GO_RIGHT;   return;
			case 0x00:Left_Speed=Left_Speed_Hold;Right_Speed=Right_Speed_Hold;MOTOR_GO_STOP;    return;

			case 0x05:Left_Speed=4;Right_Speed=10;MOTOR_GO_FORWARD;return;
			case 0x06:Left_Speed=4;Right_Speed=10;MOTOR_GO_BACK;return;
			case 0x07:Left_Speed=10;Right_Speed=4;MOTOR_GO_FORWARD;return;
			case 0x08:Left_Speed=10;Right_Speed=4;MOTOR_GO_BACK;return;
			default: return;
		}	
	}
	else if(buffer[0]==0x01)
	{
		if(buffer[2]>180)
			return;
			
		switch(buffer[1])
		{
			case 0x01:SetServoAngle(1,buffer[2]); return;
			case 0x02:SetServoAngle(2,buffer[2]); return;
			case 0x03:SetServoAngle(3,buffer[2]); return;
			case 0x04:SetServoAngle(4,buffer[2]); return;
			case 0x05:SetServoAngle(5,buffer[2]); return;
			case 0x06:SetServoAngle(6,buffer[2]); return;
			case 0x07:SetServoAngle(7,buffer[2]); return;
			case 0x08:SetServoAngle(8,buffer[2]); return;
			default : return;
		}  
	}
	else if(buffer[0]==0x02)
	{
		if(buffer[2]>10)
			return;
		switch(buffer[1])
		{
			case 0x01:Left_Speed_Hold=Left_Speed  = buffer[2]; return;
			case 0x02:Right_Speed_Hold=Right_Speed = buffer[2]; return;
			default : return;
		}
	}
	else if	(buffer[0]==0x04)//车大灯，拉电流形式，5V
	{
		 if(buffer[1]==0x01)
		 {
		    OpenMainLight(); //开灯
		 }
		 else
		 {
		 	CloseMainLight(); //关灯
		 }
	
	
	}
	else if(buffer[0]==0x13)//模式切换开关
	{
	    switch(buffer[1])
		{
		  case 0x01: Cruising_Flag = 0x01; break;//跟随
		  case 0x02: Cruising_Flag = 0x02; break;//巡线
		  case 0x03: Cruising_Flag = 0x03; break;//避障
		  case 0x04: Cruising_Flag = 0x04; break;//雷达避障
		  case 0x00: Cruising_Flag = 0x00; break;//正常模式
		  default:Cruising_Flag = 0x00; break;//正常模式
		}
	}
	else if(buffer[0]==0x32)//存储舵机角度
	{
	  	Earse_Section(50*512);
		for(i=1;i<=8;i++)
		{
		   Write_Byte(50*512+i,GetServoAngle(i));	
		}
	}
	else if(buffer[0]==0x33)//读取舵机角度并赋值
	{
		 Init_Steer();
	}
	else
	{
		return;
	}
}

void UART_Interrupt_Receive(void) interrupt 4
{
	static uint8 i;

    if(RI==1)
    {
        RI  =   0;
        if(rec_flag==0)
		{
			if(SBUF==0xff)
			{
				rec_flag=1;	
				Uart_timeout_count = 0;
				i=0;
			}			
		}
		else
		{
			if(SBUF==0xff)
			{	
				rec_flag=0;	
				if(i==3)
				{
					Communication_Decode();	
					//UART_init(); //	解决串口死机问题
				}
				i=0;
			}
			else
			{
				buffer[i]=SBUF;
				i++;
			}
		}		
    }
    else
    {
        TI  =  0;
    }
		
}