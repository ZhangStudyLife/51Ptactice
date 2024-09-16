#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main()
{
	P2_0=1;
	Delay(500);
	P2_0=0;
	Delay(500);
	//print 1310521
	Nixie(8,1);
	Delay(500);
	Nixie(7,3);
	Delay(500);
	Nixie(6,1);
	Delay(500);
	Nixie(5,4);
	Delay(500);
	Nixie(4,5);
	Delay(500);
	Nixie(3,2);
	Delay(500);
	Nixie(2,1);
}