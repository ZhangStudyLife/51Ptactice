#include <REGX52.H>
#include <INTRINS.H>

void Delay200ms(void)	//@11.0592MHz
{
    unsigned char data i, j, k;

    _nop_();
    i = 2;
    j = 103;
    k = 147;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void Delay20ms(void)	//@11.0592MHz
{
    unsigned char data i, j, k;

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
    P2_0 = 1;
    P2_1 = 1;
    P2_2 = 1;
    P2_3 = 1;
    while(1){
        if (P3_1 == 0)
        {
            Delay20ms(); // 去抖动
            if (P3_1 == 0) // 确认按键仍然按下
            {
                P2_0 = !P2_0; // 切换 P2_0 状态
                while (P3_1 == 0); // 等待按键释放
            }
        }
        if (P3_0 == 0)
        {
            Delay20ms(); // 去抖动
            if (P3_0 == 0) // 确认按键仍然按下
            {
                P2_1 = !P2_1; // 切换 P2_1 状态
                while (P3_0 == 0); // 等待按键释放
            }
        }
        if (P3_2 == 0)	
        {
            Delay20ms(); // 去抖动
            if (P3_2 == 0) // 确认按键仍然按下
            {
                P2_2 = !P2_2; // 切换 P2_2 状态
                while (P3_2 == 0); // 等待按键释放
            }
        }
        if (P3_3 == 0)	
        {
            Delay20ms(); // 去抖动
            if (P3_3 == 0) // 确认按键仍然按下
            {
                P2_3 = !P2_3; // 切换 P2_3 状态
                while (P3_3 == 0); // 等待按键释放
            }
        }
    }
}