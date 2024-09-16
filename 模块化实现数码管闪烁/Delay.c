#include <INTRINS.H>
void Delay(unsigned char n)	//@11.0592MHz
{
	while(n!=0){
		unsigned char data i, j;
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		n--;
	}
}
