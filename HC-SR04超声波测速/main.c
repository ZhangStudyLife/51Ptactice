//#include "reg52.h"
//#include "LCD1602.h"
//#include "HC_SR04.h"

//double d;
//void main()
//{
//	LCD_Init();
//	LCD_ShowString(1,1,"hello");
//	d=HC_SR02_GetDis();
//	LCD_ShowNum(2,3,d,5);
//	
//}

#include <REGX52.H>
#include "LCD1602.h"
#include "HC_SR04.h"


void main() {
    double dis;
    LCD_Init();
    Time0Init();

    while(1) {
        dis = HC_SR04_GetDistance();
        LCD_ShowNum(1, 2, dis, 6);
        // ÆäËû´úÂë...
    }
}
