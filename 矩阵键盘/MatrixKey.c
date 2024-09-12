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
    P1_6=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=5;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=6;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=7;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=8;return keyNum;};
    P1_5=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=9;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=10;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=11;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=12;return keyNum;};
    P1_4=0;
    if (P1_3==0) {Delay(20);while (P1_3==0);Delay(20);keyNum=13;return keyNum;};
    if (P1_2==0) {Delay(20);while (P1_2==0);Delay(20);keyNum=14;return keyNum;};
    if (P1_1==0) {Delay(20);while (P1_1==0);Delay(20);keyNum=15;return keyNum;};
    if (P1_0==0) {Delay(20);while (P1_0==0);Delay(20);keyNum=16;return keyNum;};
}