#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P2^5;

static unsigned int i;
void Buzzer_Time(unsigned int ms)
{
	for (i=0;i<ms;i++)
	{
		Buzzer=!Buzzer;
		Delay(1);
	}
}