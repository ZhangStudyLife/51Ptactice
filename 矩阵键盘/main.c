#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

//STC89C52RC

unsigned char KeyNum;

void main()
{
	LCD_Init();
	LCD_ShowString(1,2,"HEllO WORLD");
    while(1)
    {
		KeyNum=MatrixKey();
		if (KeyNum){
			LCD_ShowNum(2,1,MatrixKey(),3);
			Delay(2000);
			LCD_ShowString(2,1,"                ");
		}
    }
}
