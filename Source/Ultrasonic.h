/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include "type.h"
#include "timer.h"
void Send_wave(void);
uchar Get_Distance(void);
void AvoidByRadar(void);
void Send_Distance(void);


#endif