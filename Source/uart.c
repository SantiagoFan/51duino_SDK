/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
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
uint8 rec_flag=0;	//����0�ȴ����� ����1���ڽ��� 
extern uchar IR_Type;  
extern uchar IR_Num;
extern uchar Cruising_Flag;
extern uint16 Uart_timeout_count;
extern uint8 Left_Speed; //����ٶ�
extern uint8 Right_Speed;	//�Ҳ��ٶ�
extern uint8 Left_Speed_Hold;	//����ٶ�����
extern uint8 Right_Speed_Hold; //�Ҳ��ٶ�����
void UART_init(void)
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	BRT = RELOAD_COUNT;		//�趨���������ʷ�������װֵ
	AUXR |= 0x04;		//���������ʷ�����ʱ��ΪFosc,��1T
	AUXR |= 0x01;		//����1ѡ����������ʷ�����Ϊ�����ʷ�����
	AUXR |= 0x10;		//�������������ʷ�����
	ES      =   1;    //�������ж�
    EA      =   1;    //�����ж�
	TI      =   1;	
	EX0=0;
	EX1=0;
}

void UART_send_byte(uint8 byte)
{
	ES     =   0;  //�ش����ж�
    TI     =   0;  //���㴮�ڷ�������ж������־
    SBUF   =   byte;
    while(TI ==0); //�ȴ��������
    TI     =   1;  //���㴮�ڷ�������ж������־
    ES     =   1;  //�������ж�
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
	else if	(buffer[0]==0x04)//����ƣ���������ʽ��5V
	{
		 if(buffer[1]==0x01)
		 {
		    OpenMainLight(); //����
		 }
		 else
		 {
		 	CloseMainLight(); //�ص�
		 }
	
	
	}
	else if(buffer[0]==0x13)//ģʽ�л�����
	{
	    switch(buffer[1])
		{
		  case 0x01: Cruising_Flag = 0x01; break;//����
		  case 0x02: Cruising_Flag = 0x02; break;//Ѳ��
		  case 0x03: Cruising_Flag = 0x03; break;//����
		  case 0x04: Cruising_Flag = 0x04; break;//�״����
		  case 0x00: Cruising_Flag = 0x00; break;//����ģʽ
		  default:Cruising_Flag = 0x00; break;//����ģʽ
		}
	}
	else if(buffer[0]==0x32)//�洢����Ƕ�
	{
	  	Earse_Section(50*512);
		for(i=1;i<=8;i++)
		{
		   Write_Byte(50*512+i,GetServoAngle(i));	
		}
	}
	else if(buffer[0]==0x33)//��ȡ����ǶȲ���ֵ
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
					//UART_init(); //	���������������
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