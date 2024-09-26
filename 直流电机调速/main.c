#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Key.h"
#include "Nixie.h"

sbit Motor = P1^1;
unsigned char Conuter,Compare;
unsigned char KeyNum,Speed;

void Timer0_ISR() interrupt 1
{   
    TL0 = 0xA4;				//设置定时初始值
    TH0 = 0xFF;				//设置定时初始值
	Conuter++;
	Conuter%=100;
	if(Conuter < Compare)
	{
		Motor =1;
	}
	else
	{
		Motor =0;
	}
}
	  
void main()
{
	Timer0_Init();
	Compare = 0;
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if (KeyNum==1)
		{
			Speed++;z
			Speed%=4;
			Nixie(1,Speed);
		}
		if (Speed==0)Compare=0;
		if (Speed==1)Compare=50;
		if (Speed==2)Compare=75;
		if (Speed==3)Compare=100;

	}
}