/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#ifndef _LCD_12864_H_
#define _LCD_12864_H_

#include "type.h"
#include "config.h"
#include "stc_new_8051.h"
#include "timer.h"

void LCD_SendByte(uint8 Dbyte);//发送一个字节
void Wricom( uint8 Cbyte );//发送命令
void Wridat( uint8 Dbyte );//发送数据
void Dis_string( uint8 row,
                 uint8 col,
				 uint8 *puts );//显示字符串 (按指定位置)
void Dis_string1( uint8 row,
                 uint8 col,
				 uint8 *puts );	//显示字符串(按整页显示)
void Dis_bmp(uint8 *puts);//显示图像 
void Lcd_Init(void); //12864初始化
void Clear_txt( void );	//清文本文字(写ASCII码)
void Clear_bmp( void );//清图像（对应位写0、1）


#endif
