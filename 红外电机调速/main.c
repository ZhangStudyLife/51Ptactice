#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

void INT0_ISR(void) interrupt 0
{
	LCD_ShowString(1,1,"B");
	Delay(1000);
	LCD_ShowString(1,1,"A");
}


void main()
{
	LCD_Init();
	Int0_Init();

	while(1)
	{
		LCD_ShowString(1,1,"A");	
	}
}