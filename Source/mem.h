/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#ifndef _MEM_H_
#define _MEM_H_

#include "type.h"
#include "stc_new_8051.h"

/*
  Read_Byte(uint Addr)函数
  作用：从EEPORM读取uchar数据
  参数：地址值
  返回值：uchar值
  powered by tianyalu
*/
uchar Read_Byte(uint Addr);


/*
  Write_Byte(uint Addr,uchar My_Data)函数
  作用：将指定数据写入EEPROM指定地址
  参数：Addr-地址值，My_Data-要写入的数据
  返回值：无
  powered by tianyalu
*/
void Write_Byte(uint Addr,uchar My_Data);


/*
  Earse_Section(uint Addr)函数
  作用：擦除EEPROM中指定地址的值
  参数：Addr-地址值
  返回值：无
  powered by tianyalu
*/
void Earse_Section(uint Addr);


/*
  Read_Word(uint Addr)函数
  作用：从EEPORM读取uint数据
  参数：Addr-地址值
  返回值：uint值
  powered by tianyalu
*/
uint Read_Word(uint Addr);


/*
  Write_Word(uint Addr,uint My_Data)函数
  作用：把数据写入EEPROM指定地址
  参数：Addr-指定地址值，My_Data-要写入的数据
  返回值：无
  powered by tianyalu
*/
void Write_Word(uint Addr,uint My_Data);

#endif