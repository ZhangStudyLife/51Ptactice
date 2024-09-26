#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "XPT2046.h"

unsigned int ADValue;
void main()
{
	P1_1=0;
	LCD_Init();
	LCD_ShowString(1,1,"ADJ NTC RG");
	while(1)
	{
		ADValue=XPT2046_ReadAD(XPT2046_XP);
		Delay(20);
		LCD_ShowNum(2,1,ADValue,4);
		ADValue=XPT2046_ReadAD(XPT2046_YP);
		Delay(20);
		LCD_ShowNum(2,6,ADValue,4);
		ADValue=XPT2046_ReadAD(XPT2046_VBAT);
		Delay(20);
		LCD_ShowNum(2,11,ADValue,4);
	}
}
