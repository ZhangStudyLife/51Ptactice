#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

//STC89C52RC

void main()
 {
    LCD_Init();
    while(1)
    {
        LCD_ShowNum(1,1,MatrixKey(),2);
		LCD_ShowNum(2,1,MatrixKey(),1);
    }
}
