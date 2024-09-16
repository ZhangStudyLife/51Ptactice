#include <REGX52.H>


void Timer0_init()
{
    //TMOD = 0x01;     // 设置定时器0为16位定时器模式
                       // TMOD的低4位（0x01）设置为01，配置定时器0为16位模式
                       // TMOD的高4位设置为0，表示定时器1为另外一种模式
	TMOD=TMOD&0xF0;	   //把TMOD的低四位清零,高四位保持不变
	TMOD=TMOD|0x01;	   //把TMOD的低四位置一,高四位保持不变

    TH0 = 0xFC;        // 设置定时器0的高8位初值
                       // TH0的值为0xFC（即64535 / 256），表示定时器的计数范围的高8位

    TL0 = 0x67;        // 设置定时器0的低8位初值 
                       // TL0的值为0x67（即64535 % 256），表示定时器的计数范围的低8位

    TF0 = 0;           // 清除定时器0溢出标志
                       // 在启动定时器之前，需要清除溢出标志以确保正常工作

    TR0 = 1;           // 启动定时器0
                       // 设置TR0为1，使能定时器0开始计数

    ET0 = 1;           // 使能定时器0中断
                       // 允许定时器0的中断请求，定时器溢出时会触发中断

    EA = 1;            // 使能全局中断
                       
    PT0 = 0;           // 设置定时器0中断优先级为最低
                       // PT0为0时表示定时器0中断的优先级为最低，如果需要更高优先级，可设置为1
}