/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "config.h"
#include "stc_new_8051.h"

#define LIGHT_TYPE_IRRIGATION 0//车灯类型灌电流
#define LIGHT_TYPE_PULL  1//车灯类型拉电流

#define MAIN_LIGHT_ON MainLight=1  //P22口大灯开启，用拉电流形式
#define MAIN_LIGHT_OFF MainLight=0	//P22口大灯关闭，用拉电流形式
void MainLight_Init(void);
void OpenMainLight(void);
void CloseMainLight(void);
void OpenSpecifyLight(bit,uint16);
#endif