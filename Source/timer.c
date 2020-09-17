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
  Delay_Ms(uint32 t)����
  ���ã��ӳ�ָ��ʱ�䣬��λ����
  ������������
  ����ֵ����
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
  Timer0_Init(void)����
  ���ã���ʱ��0��ʼ������������ģʽ�����ȼ����жϿ���
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Timer0_Init(void)
{
	TMOD   &=   0xf0; 
    TMOD   |=   0x01; 
	AUXR   |=   0XC0;
	IP   |=   0x02;//��ʱ��0�ж����ȼ����
	TR0=1;
	ET0=1;
}
/*
  Timer1_Init(void)����
  ���ã���ʱ��1��ʼ������������ģʽ�����ȼ����жϿ���
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Timer1_Init(void)
{
    ET1     =	  1;
    TMOD   &=   0x0f; 
    TMOD   |=   0x10;   
    TH1     =   0xA9;   //1MS��ʱ
    TL1     =   0x9A;
    TR1     =   1;    //����ʱ��1

}
/*
  Timer_0(void) interrupt 1����
  ���ã���ʱ��0�жϷ�����������������ƻ����ң�ص���
  ��������
  ����ֵ����
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
  Timer_1(void) interrupt 3����
  ���ã���ʱ��1�жϷ�������������ʹ�ã�Ŀǰ�������ҵ���ٶȵ����ʹ���ͨ�ż��
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Timer_1(void) interrupt 3
{	 
    static uint16 ms_count=0;
	static uchar _100us_count=0;
	//TH1     =   0xA9;   
    //TL1     =   0x9A;

	Uart_timeout_count++;
	if((Uart_timeout_count == 1000) && (rec_flag)) //���ڽ���1�볬ʱ
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
     TL1     =   0x5C; //10KHZƵ�ʶ�ʱ

	 _100us_count++;

	 if(_100us_count <= Left_Speed) //���ռ�ձȣ�1KHz
	 {
	     MOTOR_A_EN = 1;
	 }
	 else
	 {
	     MOTOR_A_EN = 0;
	 }

	 if(_100us_count <= Right_Speed)	//�Ҳ�ռ�ձȣ�1KHz
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
