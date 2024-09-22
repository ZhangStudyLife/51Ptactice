#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "AT24C02.h"
#include "Key.h"

float Temp,TempShow;
char TLow=0,THigh=0;
unsigned char KeyNum;
void main()
{
	DS18B20_ConvertT();
	LCD_Init();
	LCD_ShowString(1,1,"Temp:");
	LCD_ShowString(2,1,"TL:");
	LCD_ShowString(2,9,"TH:");
	Delay(750);
	THigh=AT24C02_ReadByte(2);
	Delay(10);
	TLow=AT24C02_ReadByte(1);
	Delay(10);
	if (THigh>125 || THigh<TLow || TLow<-55)
	{
		THigh=28;
		TLow=20;
		AT24C02_WriteByte(1,TLow);
		Delay(10);
		AT24C02_WriteByte(2,THigh);
		Delay(10);
	}
	while(1)
	{

		KeyNum=Key();
		//温度读取及显示
		DS18B20_ConvertT();
		Temp=DS18B20_ReadT();
		if (Temp<0)
		{
			LCD_ShowChar(1,6,'-');
			TempShow=-Temp;
		}
		else
		{
			LCD_ShowChar(1,6,'+');
		}
		LCD_ShowNum(1,7,Temp,2);
		LCD_ShowChar(1,9,'.');
		LCD_ShowNum(1,10,(unsigned long)(Temp*100)%100,2);

		//阈值判断及显示
		LCD_ShowSignedNum(2,4,TLow,3);
		LCD_ShowSignedNum(2,12,THigh,3);
		if (KeyNum){
			if (KeyNum == 1)
			{
				TLow++;
				if (TLow>=THigh)
				{
					TLow--;
				}
			}
			if (KeyNum == 2)
			{
				TLow--;
				if (TLow<-55)
				{
					TLow=-55;
				}
			}
			if (KeyNum == 3)
			{
				THigh++;
				if (THigh>125)
				{
					THigh=125;
				}
			}
			if (KeyNum == 4)
			{
				THigh--;
				if (THigh<=TLow)
				{
					TLow--;
				}
			}

		}
		AT24C02_WriteByte(1,TLow);
		Delay(10);
		AT24C02_WriteByte(2,THigh);
		Delay(10);
		if (Temp<TLow)
		{
			LCD_ShowString(1,13,"L");
		}
		else if (Temp>THigh)
		{
			LCD_ShowString(1,13,"H");
		}
		else
		{
			LCD_ShowString(1,13," ");
		}

	}
}
