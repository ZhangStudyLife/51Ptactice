#include <REGX52.H>
#include "LCD1602.h"
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Hello World 123");
	LCD_ShowChar(2,3,'B');
	while(1)
	{
	}
}