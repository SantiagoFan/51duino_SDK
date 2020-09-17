/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#include "motor.h"
#include "uart.h"
#include "timer.h"
#include "mem.h"
#include "ultrasonic.h"
#include "config.h"
uchar Cruising_Flag =0x00;
uchar  Robots_Run_Status;
uchar Pre_Cruising_Flag = 0x00;
uint8 Left_Speed = 10; //左侧速度
uint8 Right_Speed = 10;	//右侧速度
uint8 Left_Speed_Hold=10;	//左侧速度锁存
uint8 Right_Speed_Hold=10; //右侧速度锁存
/*
  Motor_Init(void)函数
  作用：初始化电机驱动芯片，L298P使能端置高电平
  参数：无
  返回值：无
  powered by tianyalu
*/
void Motor_Init(void)
{
	MOTOR_A_EN=1;
	MOTOR_B_EN=1;
	MOTOR_GO_STOP;
}

/*
  Follow_Track(void)函数
  作用：全功能跟随主人模式，跟随前方移动物体
  参数：无
  返回值：无
  powered by liuviking
*/
void Follow_Track(void)
{
  		switch(Robots_Run_Status)
		 {
			case 0x01:MOTOR_GO_RIGHT;     break;    
			case 0x02:MOTOR_GO_LEFT;     break;	   
			case 0x03:MOTOR_GO_FORWARD;  break;	   
			case 0x04:MOTOR_GO_STOP;  break;	
		 }

		
	     if(Input_Detect1 == 1)	//中间传感器OK
		  {
		  
		   	if((Input_Detect0 == 0)&& (Input_Detect2 == 0)) //两边同时探测到障碍物
			{
			
				 Robots_Run_Status=0x04;//停止 
			} 
			 
			if((Input_Detect0 == 0)&& (Input_Detect2 == 1))//左侧障碍物
			{
			
				Robots_Run_Status=0x01;//右转 
			}
		
			if((Input_Detect0 == 1)&& (Input_Detect2 == 0))//右侧障碍物
			{
				Robots_Run_Status=0x02;//左转 
			}
			 
			if((Input_Detect0 == 1)&& (Input_Detect2 == 1))//无任何障碍物
			{
				Robots_Run_Status=0x03;//直行 
			}
		  }
		  else
		  {
		  	   Robots_Run_Status=0x04;
		  }

}
/*
  FollowLine(void)函数
  作用：全功能巡线遁迹模式，红外寻黑线
  参数：无
  返回值：无
  powered by liuviking
*/
void FollowLine(void)
{
   		switch(Robots_Run_Status)
		 {
			case 0x01:MOTOR_GO_RIGHT;     break;    
			case 0x02:MOTOR_GO_LEFT;     break;	   
			case 0x03:MOTOR_GO_FORWARD;  break;	   
			case 0x04:MOTOR_GO_STOP;  break;	
		 }

		   	if((Input_Detect_LEFT == 0)&& (Input_Detect_RIGHT == 0))//两边同时探测到障碍物
			{
			
				 Robots_Run_Status=0x03;//直行 
			} 
			 
			if((Input_Detect_LEFT == 0)&& (Input_Detect_RIGHT == 1))//右侧遇到障碍  
			{
			
				Robots_Run_Status=0x02;//左转 
			}
		
			if((Input_Detect_LEFT == 1)&& (Input_Detect_RIGHT == 0))//左侧遇到障碍 
			{
				Robots_Run_Status=0x01;//右转 
			}
			 
			if((Input_Detect_LEFT == 1)&& (Input_Detect_RIGHT == 1))//左右都检测到，就如视频中的那样遇到一道横的胶带 
			{
				Robots_Run_Status=0x04;//停止 
			}
}
/*
  Avoiding(void)函数
  作用：全功能红外避障模式，红外探测前方障碍停车，防掉落悬崖停车
  参数：无
  返回值：无
  powered by liuviking
*/
void Avoiding(void)
{
   		 switch(Robots_Run_Status)
		 {
			case 0x01:MOTOR_GO_RIGHT;     break;    
			case 0x02:MOTOR_GO_LEFT;     break;	   
			case 0x03:MOTOR_GO_FORWARD;  break;	   
			case 0x04:MOTOR_GO_STOP;  break;
			case 0x05:MOTOR_GO_BACK; break;		   
		 }

		   	if((Input_Detect_LEFT == 1) || (Input_Detect_RIGHT == 1) || (Input_Detect1==0))
			{
		    
				Robots_Run_Status=0x04;
			} 
			else //否则电机执行前进动作
			{
				  Robots_Run_Status=0x03;
			}
}
	 

/*
  Cruising_Mod(void)函数
  作用：全功能模式选择函数
  参数：无
  返回值：无
  powered by tianyalu
*/
void Cruising_Mod(void)
{
       
	 if(Pre_Cruising_Flag != Cruising_Flag)
	 {
	     if(Pre_Cruising_Flag != 0)
		 {
		     MOTOR_GO_STOP; 
		 }

    	 Pre_Cruising_Flag =  Cruising_Flag;
	 }	

	switch(Cruising_Flag)
	{
	   //case 0x00:Send_Distance();//超声波测距，使用此功能前，请确保WiFi模块双向数据功能已经打开，否则会造成客户端与模块的连接中断。
	   //开放双向数据教程： http://www.wifi-robots.com/thread-2985-1-1.html
	   case 0x01:Follow_Track(); break;//跟随模式
	   case 0x02:FollowLine(); break;//巡线模式
	   case 0x03:Avoiding(); break;//避障模式
	   case 0x04:AvoidByRadar();break;//超声波壁障模式
	   case 0x05:ARMShow();break;
	   case 0x06:HeadShow();break;
	   default:break;
	}	 
}


void Delay_ForBarrier(uint32 t)
{  
    uint16 i;
	while(t--)
	{
	   for(i=0;i<1050;i++);
	}
}







