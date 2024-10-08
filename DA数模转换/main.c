#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Key.h"
#include "Nixie.h"

sbit DA = P2^1;
unsigned char Conuter,Compare;
unsigned char KeyNum,i;

void Timer0_ISR() interrupt 1
{   
    TL0 = 0xA4;				//设置定时初始值
    TH0 = 0xFF;				//设置定时初始值
	Conuter++;
	Conuter%=100;
	if(Conuter < Compare)
	{
		DA =1;
	}
	else
	{
		DA =0;
	}
}
	  
void main()
{
	Timer0_Init();  
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			Delay(20);
		}
		for (i=100;i>0;i--)
		{
			Compare=i;
			Delay(20);
		}
	}
}