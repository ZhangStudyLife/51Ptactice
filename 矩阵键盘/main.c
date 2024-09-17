#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

//STC89C52RC

<<<<<<< HEAD
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
=======
void main()
 {
    LCD_Init();
    while(1)
    {
        LCD_ShowNum(1,1,MatrixKey(),2);
		LCD_ShowNum(2,1,MatrixKey(),1);
>>>>>>> 6d397c2d69e7cb89d6aa19427358483d0ade3950
    }
}
