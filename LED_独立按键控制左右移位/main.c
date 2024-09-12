#include <REGX52.H>
#include <INTRINS.H>
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
    P2 = 0xFE;   // 1111 1110
    while (1)
    {
        if(P3_1==0) 
        {
            Delay20ms();
            if(P3_1==0)
            {
                while(P3_1==0);
                P2 = P2 << 1;
            }
        }
        if(P3_3==0)
        {
            Delay20ms();
            if(P3_3==0)
            {
                while(P3_3==0);
                P2 = P2 >> 1;
            }
        }
        if(P3_0==0)
        {
            Delay20ms();
            if(P3_0==0)
            {
                while(P3_0==0);
                P2 = 0xFE;
            }
        }
    }
}