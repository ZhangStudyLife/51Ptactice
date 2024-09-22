#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

// 动画数据，每帧8个字节，3帧动画
unsigned char code Animation[]={
	0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,  // 第一帧
	0x3C,0x42,0xA1,0x85,0x85,0xA1,0x42,0x3C,  // 第二帧
	0x3C,0x42,0xA5,0x89,0x89,0xA5,0x42,0x3C   // 第三帧
};

void main()
{
	unsigned char i, Offset=0, Count=0; // i用于循环列数，Offset用于切换动画帧，Count用于控制帧切换速度
	MatrixLED_Init();                   // 初始化点阵LED
	while(1)
	{
		// 显示当前帧的每一列
		for(i=0; i<8; i++)	// 循环8次，依次显示点阵屏的8列数据
		{
			MatrixLED_ShowColumn(i, Animation[i + Offset]); // 显示第i列，数据来自当前动画帧
		}
		Count++; // 帧延时计数
		if(Count > 15) // 控制切换帧的速度，当Count大于15时，切换到下一帧
		{
			Count = 0;           // 重置计数
			Offset += 8;         // 偏移+8，切换到下一帧
			if(Offset > 16)      // 若偏移超过16（超出3帧），则重置为第一帧
			{
				Offset = 0;      // 回到第一帧
			}
		}
	}
}
