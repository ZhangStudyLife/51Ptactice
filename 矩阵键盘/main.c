#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
    LCD_Init();
    while(1)
    {
        LCD_ShowString(1,1,"Hello,World!");
        Delay(50000);
        LCD_ShowString(2,1,"Hello,MCU!");
        Delay(50000);
    }
}
