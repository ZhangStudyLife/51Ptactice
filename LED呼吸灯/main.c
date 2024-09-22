#include <REGX52.H>

sbit LED=P2^0;

void Delay(unsigned int t)
{
	while(t--);
}

unsigned char xunhuan;
void main()
{
	unsigned char Time;
	while(1)
	{
		for (Time=0;Time<100;Time++){
			for (xunhuan=0;xunhuan<20;xunhuan++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}
		for (Time=100;Time>0;Time--){
			for (xunhuan=0;xunhuan<20;xunhuan++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}
	}
}
