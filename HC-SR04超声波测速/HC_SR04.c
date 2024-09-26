#include "HC_SR04.h"
#include "LCD1602.h"

void Delay10us() {
    unsigned char i;
    i = 2;
    while (--i);
}


void startHC() {
    Trig = 0;
    Trig = 1;
    Delay10us();
    Trig = 0;
}

void Time0Init()
{	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	//设置定时器0工作模式1，初始值设定0开始数数，不着急启动定时器
}

double HC_SR04_GetDistance()
{
	double time;
	double dis;
	Time0Init();
	
	while(1){
		//1. 让它发送波：给Trig端口至少10us的高电平
		startHC();
		//2. 开始发送波：Echo信号由低电平跳转到高电平
		while(Echo == 0);
		//   开始发送波，启动定时器
		TR0 = 1;
		//3. 接收返回波：Echo信号由高电平跳转回低电平
		while(Echo == 1);
		//   接收返回波，停止定时器
		TR0 = 0;
		//4. 计算时间
		time = (TH0 * 256 + TL0)*1.085;//us为单位
		//5. 距离 = 速度 （340m/s）* 时间/2
		dis = time * 0.017;
		//定时器数据清零，以便下一次测距
		TH0 = 0;
		TL0 = 0;
		return dis;
	}
}
