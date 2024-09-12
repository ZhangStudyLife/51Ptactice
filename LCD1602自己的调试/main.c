#include <REGX52.H>
#include "LCD1602.h"
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Hello World 123");
	LCD_ShowChar(2,3,'B');
	LCD_ShowNum(2,5,1531,5);
	
	while(1)
	{
	}
}