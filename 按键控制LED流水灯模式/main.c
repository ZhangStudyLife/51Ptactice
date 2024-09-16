#include <REGX52.H>
#include "Timer0.h"
#include "MatrixKey.h"
#include <INTRINS.H>
#include "Delay.h"

unsigned int T0Count = 0;
unsigned char LEDMode = 1;
unsigned char KeyStatus = 0;
unsigned int speed = 1000;
unsigned char LEDState = 0xFE;  // 保存当前LED状态

// 定时器0中断服务程序
void Timer0_ISR(void) interrupt 1
{
    T0Count++;  // 增加定时器0计数
    TH0 = 0xFC;  // 重载定时器0高8位初值
    TL0 = 0x67;  // 重载定时器0低8位初值

    if (T0Count >= speed) 
    {
        T0Count = 0;  // 计数器归零
        if (LEDMode == 1)  // 如果是流水灯模式
        {
            LEDState = _crol_(LEDState, 1);  // 循环左移
        }
        else if (LEDMode == 0)  // 如果是“按啥亮啥”模式
        {
            LEDState = _cror_(LEDState, 1);  // 循环右移
        }
        P2 = LEDState;  // 将当前LED状态赋给P2
    }
}

void main()
{
    P2 = LEDState;  // 初始化P2端口，设置初始LED状态
    Timer0_init();  // 初始化定时器0

    while (1)
    {
        KeyStatus = MatrixKey();  // 获取当前按键状态

        // 调试输出：将按键状态直接显示在 P2 口，便于观察按键输入
        if (KeyStatus != 0)  // 如果检测到按键
        {
            P2 = ~KeyStatus;  // 反转按键编号显示在P2上，用于调试观察
        }

        // 按键逻辑处理
        if (KeyStatus == 12)  // 如果按下键12，减少速度
        {
            speed = (int)(speed * 0.8);  
        }
        else if (KeyStatus == 16)  // 如果按下键16，增加速度
        {
            speed = (int)(speed * 1.25); 
        }
        else if (KeyStatus == 9)  // 如果按下键9，切换到流水灯模式
        {
            LEDMode = 1;
        }
        else if (KeyStatus == 10)  // 如果按下键10，切换到按啥亮啥模式
        {
            LEDMode = 0;
        }
    }
}




