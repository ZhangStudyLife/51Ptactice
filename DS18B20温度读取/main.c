#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "DS18B20.h"

float Temp;
void main()
{
	DS18B20_ConvertT();
	LCD_Init();
	Delay(750);
	while(1)
	{
		DS18B20_ConvertT();
		Temp=DS18B20_ReadT();
		if (Temp<0)
		{
			LCD_ShowChar(1,1,'-');
			Temp=-Temp;
		}
		else
		{
			LCD_ShowChar(1,1,'+');
		}
		LCD_ShowNum(1,2,Temp,2);
		LCD_ShowChar(1,4,'.');
		LCD_ShowNum(1,5,(unsigned long)(Temp*100)%100,2);
		LCD_ShowNum(2,5,(unsigned long)(Temp*10000)%10000,4);
	}
}
