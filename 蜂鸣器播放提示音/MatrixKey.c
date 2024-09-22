#include <REGX52.H>
#include "Delay.h"

unsigned char MatrixKey()
{
    unsigned char keyNum = 0; // 按键编号

    // 扫描列1
    P1 = 0xFF;
    P1_7 = 0;
    if (P1_3 == 0) { Delay(20); while (P1_3 == 0); Delay(20); keyNum = 1; };
    if (P1_2 == 0) { Delay(20); while (P1_2 == 0); Delay(20); keyNum = 2; };
    if (P1_1 == 0) { Delay(20); while (P1_1 == 0); Delay(20); keyNum = 3; };
    if (P1_0 == 0) { Delay(20); while (P1_0 == 0); Delay(20); keyNum = 4; };

    // 扫描列2
    P1 = 0xFF;
    P1_6 = 0;
    if (P1_3 == 0) { Delay(20); while (P1_3 == 0); Delay(20); keyNum = 5; };
    if (P1_2 == 0) { Delay(20); while (P1_2 == 0); Delay(20); keyNum = 6; };
    if (P1_1 == 0) { Delay(20); while (P1_1 == 0); Delay(20); keyNum = 7; };
    if (P1_0 == 0) { Delay(20); while (P1_0 == 0); Delay(20); keyNum = 8; };

    // 扫描列3
    P1 = 0xFF;
    P1_5 = 0;
    if (P1_3 == 0) { Delay(20); while (P1_3 == 0); Delay(20); keyNum = 9; };
    if (P1_2 == 0) { Delay(20); while (P1_2 == 0); Delay(20); keyNum = 10; };
    if (P1_1 == 0) { Delay(20); while (P1_1 == 0); Delay(20); keyNum = 11; };
    if (P1_0 == 0) { Delay(20); while (P1_0 == 0); Delay(20); keyNum = 12; };

    // 扫描列4
    P1 = 0xFF;
    P1_4 = 0;
    if (P1_3 == 0) { Delay(20); while (P1_3 == 0); Delay(20); keyNum = 13; };
    if (P1_2 == 0) { Delay(20); while (P1_2 == 0); Delay(20); keyNum = 14; };
    if (P1_1 == 0) { Delay(20); while (P1_1 == 0); Delay(20); keyNum = 15; };
    if (P1_0 == 0) { Delay(20); while (P1_0 == 0); Delay(20); keyNum = 16; };

    return keyNum;  // 返回按键编号
}
