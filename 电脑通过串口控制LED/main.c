#include <REGX52.H>
#include "Delay.h"

void UART_Init(void)	//4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	EA=1;
	ES=1;
} 

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while (TI == 0);
	TI=0;
}

unsigned char receivedData = 0;		// 用于存储接收到的数据

void UART_Routine(void) interrupt 4		// 串口中断服务函数(当串口中断产生时,自动跳到这个自函数)
{
	if (RI) // 检测接收中断标志位
	{
		RI = 0;				// 清除接收中断标志位
		receivedData = SBUF;	// 从SBUF读取接收到的数据
		P2=~receivedData;
		UART_SendByte(receivedData);	// 回传接收到的数据（可选）
	}
}

unsigned char show;
void main()
{
	UART_Init();
	while(1)
	{

	}
}