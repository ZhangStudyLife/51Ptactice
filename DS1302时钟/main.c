#include <REGX52.H>
#include "DS1302.h"
#include "LCD1602.h"
#include "Delay.h"
unsigned char second;
void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowString(1, 0, "DS1302 Test");
	DS1302_WriteByte(0x80, 0x03);
	second = DS1302_ReadByte(0x81);
	LCD_ShowNum(2, 2, second,5);
	LCD_ShowNum(2,10,45,2);
	while (1)
	{
		
	}
}