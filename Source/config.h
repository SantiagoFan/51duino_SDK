/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
/*
【管脚配置注意事项】
由于单片机的管脚个数有限，有些功能的管脚可能存在重复定义（冲突）
请在具体编写代码时注意管脚定义有无冲突现象，如有请更换管脚配置，或者注释不用的功能代码，以免引起程序错乱。
*/
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "stc_new_8051.h"

/* 直流电机管脚配置 */
sbit MOTOR_A_CON1=P0^0;
sbit MOTOR_A_CON2=P0^2;
sbit MOTOR_A_EN=P0^1;

sbit MOTOR_B_CON1=P0^3;
sbit MOTOR_B_CON2=P0^5;
sbit MOTOR_B_EN=P0^4;

sbit Beep=P3^6;
/* 超声波管脚配置 */
sbit Echo=P3^4;
sbit Trig=P3^5;


/* 舵机管脚配置 */
/*
此项为系统固定管脚，请勿放开注释
sbit SE1=P1^0;//舵机1
sbit SE2=P1^1;//舵机2
sbit SE3=P1^2;//舵机3
sbit SE4=P1^3;//舵机4
sbit SE5=P1^4;//舵机5
sbit SE6=P1^5;//舵机6
sbit SE7=P1^6;//舵机7
sbit SE8=P1^7;//舵机8
*/


#define SE1_Deg  90 //舵机1上电默认角度
#define SE2_Deg  45 //舵机2上电默认角度
#define SE3_Deg  67 //舵机3上电默认角度
#define SE4_Deg  67 //舵机4上电默认角度
#define SE5_Deg  90 //舵机5上电默认角度
#define SE6_Deg  90 //舵机6上电默认角度
#define SE7_Deg  64 //舵机7上电默认角度
#define SE8_Deg  80 //舵机8上电默认角度

/* LED管脚配置 */
sbit LED6=P0^6;
sbit LED5=P0^7;
sbit LED4=P2^7;
sbit LED3=P2^6;
sbit LED2=P2^5;
sbit LED1=P2^4;


/* 跟随管脚配置 */
sbit Input_Detect0=P3^7;	  //右侧探头
sbit Input_Detect1=P3^3;	 //距离探测
sbit Input_Detect2=P2^1;	 //左侧探头

/* 避障管脚配置 */
sbit Input_Detect_LEFT=P2^0;	  //右侧探头
sbit Input_Detect_RIGHT=P2^3;	 //左侧探头

/*12864LCD液晶显示屏管脚配置
在需要使用时放开，并确认不与其他管脚配置冲突
*/

sbit LCD_CS = P2^1;
sbit LCD_SD = P2^0;
sbit LCD_SCK = P2^3;


/* 车大灯配置 */
sbit MainLight=P2^2;
sbit IR_R=P3^2;

/* 串口配置 */
/*晶振为22.1184MHz 以下为可选波特率*/
#define BPS_9600     0x70  
#define BPS_19200	 0xB8
#define BPS_38400	 0xDC
#define BPS_57600	 0xE8
#define BPS_115200	 0xF4

#define RELOAD_COUNT   BPS_9600	//波特率选择

#endif