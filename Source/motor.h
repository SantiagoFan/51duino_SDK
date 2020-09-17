/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#ifndef _MOTOR_H_
#define _MOTOR_H_


#include "type.h"
#include "config.h"

void Motor_Init(void);//声明电机驱动函数
void Delay_ForBarrier(uint32);//声明延时函数
void Cruising_Mod(void);//全功能选择模式
#define MOTOR_GO_FORWARD   MOTOR_A_CON1=1;MOTOR_A_CON2=0;MOTOR_B_CON1=1;MOTOR_B_CON2=0;LED1=0;LED2=1;LED3=1;LED4=1 //车体前进	                            
#define MOTOR_GO_BACK	   MOTOR_A_CON1=0;MOTOR_A_CON2=1;MOTOR_B_CON1=0;MOTOR_B_CON2=1;LED1=1;LED2=0;LED3=1;LED4=1 //车体后退
#define MOTOR_GO_RIGHT	   MOTOR_A_CON1=0;MOTOR_A_CON2=1;MOTOR_B_CON1=1;MOTOR_B_CON2=0;LED1=1;LED2=1;LED3=0;LED4=1 //车体左转
#define MOTOR_GO_LEFT	   MOTOR_A_CON1=1;MOTOR_A_CON2=0;MOTOR_B_CON1=0;MOTOR_B_CON2=1;LED1=1;LED2=1;LED3=1;LED4=0 //车体右转
#define MOTOR_GO_STOP	   MOTOR_A_CON1=0;MOTOR_A_CON2=0;MOTOR_B_CON1=0;MOTOR_B_CON2=0;LED1=1;LED2=1;LED3=1;LED4=1 //车体停止
#endif

