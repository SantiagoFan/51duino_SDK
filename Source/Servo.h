/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/

#ifndef __SERVO_H__
#define __SERVO_H__
#include "steer.h"

void SetServoAngle(uint16,uint16);
void Init_Steer(void);
uchar GetServoAngle(uint16);
#endif