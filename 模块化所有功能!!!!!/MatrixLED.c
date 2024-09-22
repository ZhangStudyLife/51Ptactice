#include <REGX52.H>
#include "Delay.h"


sbit RCK=P3^5;			//RCLK
sbit SCK=P3^6;			//SRCLK
sbit SER=P3^4;			//SER

#define MatrixLED_PORT P0


void MatrixLED_Init()
{
    MatrixLED_PORT=0xFF;
    RCK=0;
    SCK=0;
}



/**
 * @brief 74HC595写入一个字节
 * @param Byte: 要写入的字节
 */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for ( i = 0; i<8;i++)
	{
		SER=Byte&(0x80>>i);		//通过&运算 取出Byte的某一位
		SCK=1;				//上升沿,移位
		SCK=0;				//置0
	}
	RCK=1;
	RCK=0;
}




/**
 * @brief 在点阵屏上显示某一列
 * @param Column: 列号 范围: 0-7
 * @param Data: 选择列显示的数据 , 高位在上 , 1为亮, 0为灭
 */
void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data)
{
    _74HC595_WriteByte(Data);
    MatrixLED_PORT = ~(0x80 >> Column);
	Delay(1);
    MatrixLED_PORT = 0xFF;
}



