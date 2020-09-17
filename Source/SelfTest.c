/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#include "SelfTest.h"

/*
  TestApp_Init(void)函数
  作用：上电自检，流水灯显示，避免Wi-Fi模块数据干扰
  参数：无
  返回值：无
  powered by liuviking
*/
void TestApp_Init(void)
{
  
   uint16 i;
   ES=0;
   for(i=0;i<18;i++)
   {
   	   LED1=~LED1;
	   Delay_(350);
	   LED2=~LED2;
	   Delay_(350);
	   LED3=~LED3;
	   Delay_(350);
	   LED4=~LED4;
	   Delay_(350);
	   LED5=~LED5;
	   Delay_(350);
	   LED6=~LED6;
	   Delay_(350);
		
   }

  for(i=0;i<15;i++)
   {
   	   LED1=~LED1;
	   LED2=~LED2;
	   LED3=~LED3;
       LED4=~LED4;
       LED5=~LED5;
       LED6=~LED6;
	   Delay_(1000);
		
   }
   LED2=1;
   LED4=1;
   LED6=1;  	 
}

void Delay_(uint32 t)
{  
	uint16 i;
	while(t--)
	{
		for(i=0;i<1050;i++);
	}
}