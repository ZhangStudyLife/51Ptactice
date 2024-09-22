#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "Key.h"
#include "MatrixKey.h"
#include "Buzzer.h"


sbit Buzzer=P2^5;

unsigned char KeyNum;
static unsigned int i;

void main()
{
	while(1)
	{
		KeyNum=Key();
		Nixie(1,KeyNum);
		if (KeyNum)
		{
			Buzzer_Time(5000);
		}
	}
}