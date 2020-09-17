/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#ifndef _IR_H_
#define _IR_H_

#include "type.h"
#include "stc_new_8051.h"
#include "config.h"
#define IR_SEND_LED_ON	 LED4=1;LED5=0;LED6=1
#define IR_SEND_LED_OFF	 LED4=0;LED5=1;LED6=0;
void IR_Rec(void);//红外接收子函数
void IR_Tra(void);//红外发射子函数
void Timer_For_IR(void);  //红外定时器

#endif