#include <REGX52.H>
#include "Delay.h"
unsigned char MatrixKey()
{
    unsigned char keyNum=0;

    //获取矩阵键盘的输出
    P1=0xFF;
    P1_7=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=1;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=2;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=3;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=4;return keyNum;};
<<<<<<< HEAD
    P1=0xFF;
=======
>>>>>>> 6d397c2d69e7cb89d6aa19427358483d0ade3950
    P1_6=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=5;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=6;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=7;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=8;return keyNum;};
<<<<<<< HEAD
    P1=0xFF;
=======
>>>>>>> 6d397c2d69e7cb89d6aa19427358483d0ade3950
    P1_5=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=9;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=10;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=11;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=12;return keyNum;};
<<<<<<< HEAD
    P1=0xFF;
=======
>>>>>>> 6d397c2d69e7cb89d6aa19427358483d0ade3950
    P1_4=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=13;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=14;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=15;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=16;return keyNum;};
<<<<<<< HEAD
}

// #include <REGX52.H>
// #include "Delay.h"

// unsigned char MatrixKey()
// {
//     unsigned char keyNum = 0; // 初始化按键编号为0
//     unsigned char col, row; // 列和行的变量

//     // 扫描矩阵键盘的列
//     for (col = 0; col < 4; col++)
//     {
//         P1 = 0xFF; // 初始化P1端口
//         P1 &= ~(0x80 >> col); // 逐列拉低
//         Delay(20); // 延时去抖动

//         // 检测按键
//         if (P1_3 == 0) { Delay(20); while (P1_3 == 0); Delay(20); keyNum = col * 4 + 1; }
//         if (P1_2 == 0) { Delay(20); while (P1_2 == 0); Delay(20); keyNum = col * 4 + 2; }
//         if (P1_1 == 0) { Delay(20); while (P1_1 == 0); Delay(20); keyNum = col * 4 + 3; }
//         if (P1_0 == 0) { Delay(20); while (P1_0 == 0); Delay(20); keyNum = col * 4 + 4; }

//         // 如果检测到按键按下，退出循环
//         if (keyNum != 0) break;
//     }
//     return keyNum; // 返回按键编号
// }
=======
}
>>>>>>> 6d397c2d69e7cb89d6aa19427358483d0ade3950
