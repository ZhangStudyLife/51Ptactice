#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"
#include "AT24C02.h"
#include "Timer0.h"
unsigned char Data;
unsigned char number;
unsigned char KeyNum;

void Timer0_ISR() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	Data++;
	if (Data==100)
	{
		Data=0;
		LCD_Clear(2);
	}
}

void main()
{
	Timer0_init();
	LCD_Init();
	LCD_ShowString(1,1,"AT24C02 TEST");
	
	while(1)
	{
		KeyNum=Key();
		if (KeyNum==1)
		{
			number++;
			LCD_ShowNum(2,1,number,5);
		}
		if (KeyNum==2)
		{
			number--;
			LCD_ShowNum(2,1,number,5);
		}
		if (KeyNum==3)
		{
			AT24C02_WriteByte(0,number%256);
			Delay(5);
			AT24C02_WriteByte(1,number/256);
			Delay(5);
			LCD_ShowString(2,1,"Number saved");
		}
		if (KeyNum==4)
		{
			number=AT24C02_ReadByte(0)+AT24C02_ReadByte(1)*256;
			LCD_ShowString(2,1,"Saved befor:");
			LCD_ShowNum(2,13,number,4);
		}
	}
}