#include <REGX52.H>
#include <INTRINS.H>
#include <stdio.h>
unsigned char reverseBits(unsigned char num) {
    unsigned char result = 0;
    unsigned char i; // 将 i 的类型更改为 unsigned char
    for (i = 0; i < 8; i++) {
        result <<= 1;                // 将结果左移一位，为当前最低位腾出位置
        result |= (num & 1);         // 获取 num 的最低位，合并到结果的最低位
        num >>= 1;                   // 将 num 右移一位，处理下一个位
    }
    return result;
}


void Delay20ms(void)	//@11.0592MHz
{
    unsigned char i, j, k; // 去掉 data 关键字

    _nop_();
    i = 1;
    j = 52;
    k = 74;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void main()
{
    // K2控制重置 
    // K3控制加号
    // K4控制减号
	unsigned char a = 0xFF;
    P2 = 0xFF;   // 将P2端口的初始值设为高电平

    while(1)
    {
        if (P3_0 == 0)  // 按下K2
        {
            Delay20ms(); // 去抖动
            if (P3_0 == 0) // 确认按键仍然按下
            {
                a = 0xFF;
                while (P3_0 == 0); // 等待按键释放
            }
        }

        if (P3_2 == 0)  // 按下K3
        {
            Delay20ms(); // 去抖动
            if (P3_2 == 0) // 确认按键仍然按下
            {
                a--;
                while (P3_2 == 0); // 等待按键释放
            }
        }

        if (P3_3 == 0)  // 按下K4
        {
            Delay20ms(); // 去抖动
            if (P3_3 == 0) // 确认按键仍然按下
            {
                a++;
                while (P3_3 == 0); // 等待按键释放
            }
        }

        P2 = reverseBits(a);  // 更新P2端口的输出
    }
}

