/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有 www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！2015-8-22
By WIFI机器人网·机器人创意工作室
*/
#include "Light.h"
#include "config.h"
#include "type.h"
#include "stc_new_8051.h"
/*P22大灯控制协议：FF040100FF开灯  FF040000FF关灯*/

/*
  MainLight_Init(void)函数
  作用：大灯初始化函数，上电后默认关闭。大灯默认为P22口，拉电流形式（LED长脚接51duino P22口的+极，短脚接P22口-极）
  参数：无
  返回值：无
  powered by liuviking
*/
void MainLight_Init(void)
{
	 MAIN_LIGHT_OFF;
}

/*
  OpenMainLight(void)函数
  作用：开启大灯函数。大灯默认为P22口，拉电流形式
  参数：无
  返回值：无
  powered by liuviking
*/
void OpenMainLight(void)
{
	 MAIN_LIGHT_ON;
}

/*
  CloseMainLight(void)函数
  作用：关闭大灯函数。大灯默认为P22口，拉电流形式
  参数：无
  返回值：无
  powered by liuviking
*/
void CloseMainLight(void)
{
	 MAIN_LIGHT_OFF;
}

