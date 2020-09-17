/*
��Ȩ������
������С�����ͿƼ���СR�Ƽ������£�WIFI���������������˴��⹤���Ұ�Ȩ���� www.wifi-robots.com
�����������޸ı����򣬲�Ӧ���������з�������С�������˼��������Ӳ�Ʒ�ϣ����ǽ�ֹ������ҵĲ����
СR�Ƽ����������������Ȩ��Ȩ����2015-8-22
By WIFI���������������˴��⹤����
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
uint8 Left_Speed = 10; //����ٶ�
uint8 Right_Speed = 10;	//�Ҳ��ٶ�
uint8 Left_Speed_Hold=10;	//����ٶ�����
uint8 Right_Speed_Hold=10; //�Ҳ��ٶ�����
/*
  Motor_Init(void)����
  ���ã���ʼ���������оƬ��L298Pʹ�ܶ��øߵ�ƽ
  ��������
  ����ֵ����
  powered by tianyalu
*/
void Motor_Init(void)
{
	MOTOR_A_EN=1;
	MOTOR_B_EN=1;
	MOTOR_GO_STOP;
}

/*
  Follow_Track(void)����
  ���ã�ȫ���ܸ�������ģʽ������ǰ���ƶ�����
  ��������
  ����ֵ����
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

		
	     if(Input_Detect1 == 1)	//�м䴫����OK
		  {
		  
		   	if((Input_Detect0 == 0)&& (Input_Detect2 == 0)) //����ͬʱ̽�⵽�ϰ���
			{
			
				 Robots_Run_Status=0x04;//ֹͣ 
			} 
			 
			if((Input_Detect0 == 0)&& (Input_Detect2 == 1))//����ϰ���
			{
			
				Robots_Run_Status=0x01;//��ת 
			}
		
			if((Input_Detect0 == 1)&& (Input_Detect2 == 0))//�Ҳ��ϰ���
			{
				Robots_Run_Status=0x02;//��ת 
			}
			 
			if((Input_Detect0 == 1)&& (Input_Detect2 == 1))//���κ��ϰ���
			{
				Robots_Run_Status=0x03;//ֱ�� 
			}
		  }
		  else
		  {
		  	   Robots_Run_Status=0x04;
		  }

}
/*
  FollowLine(void)����
  ���ã�ȫ����Ѳ�߶ݼ�ģʽ������Ѱ����
  ��������
  ����ֵ����
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

		   	if((Input_Detect_LEFT == 0)&& (Input_Detect_RIGHT == 0))//����ͬʱ̽�⵽�ϰ���
			{
			
				 Robots_Run_Status=0x03;//ֱ�� 
			} 
			 
			if((Input_Detect_LEFT == 0)&& (Input_Detect_RIGHT == 1))//�Ҳ������ϰ�  
			{
			
				Robots_Run_Status=0x02;//��ת 
			}
		
			if((Input_Detect_LEFT == 1)&& (Input_Detect_RIGHT == 0))//��������ϰ� 
			{
				Robots_Run_Status=0x01;//��ת 
			}
			 
			if((Input_Detect_LEFT == 1)&& (Input_Detect_RIGHT == 1))//���Ҷ���⵽��������Ƶ�е���������һ����Ľ��� 
			{
				Robots_Run_Status=0x04;//ֹͣ 
			}
}
/*
  Avoiding(void)����
  ���ã�ȫ���ܺ������ģʽ������̽��ǰ���ϰ�ͣ��������������ͣ��
  ��������
  ����ֵ����
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
			else //������ִ��ǰ������
			{
				  Robots_Run_Status=0x03;
			}
}
	 

/*
  Cruising_Mod(void)����
  ���ã�ȫ����ģʽѡ����
  ��������
  ����ֵ����
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
	   //case 0x00:Send_Distance();//��������࣬ʹ�ô˹���ǰ����ȷ��WiFiģ��˫�����ݹ����Ѿ��򿪣��������ɿͻ�����ģ��������жϡ�
	   //����˫�����ݽ̳̣� http://www.wifi-robots.com/thread-2985-1-1.html
	   case 0x01:Follow_Track(); break;//����ģʽ
	   case 0x02:FollowLine(); break;//Ѳ��ģʽ
	   case 0x03:Avoiding(); break;//����ģʽ
	   case 0x04:AvoidByRadar();break;//����������ģʽ
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







