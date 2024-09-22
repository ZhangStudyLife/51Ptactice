#include <REGX52.H>
#include "OneWire.h"

#define DS18B20_SKIP_ROM	0xcc
#define DS18B20_CONVERT_T	0x44
#define DS18B20_READ_SCRATCHPAD	0xbe
#define DS18B20_WRITE_SCRATCHPAD	0x4e
#define DS18B20_COPY_SCRATCHPAD	0x48
#define DS18B20_RECALL_E2	0xb8
#define DS18B20_READ_POWER_SUPPLY	0xb4

// DS18B20

void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)
{
	unsigned char LSB,MSB;
	unsigned int T;
	float Temp;
	
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	LSB=OneWire_ReceiveByte();
	MSB=OneWire_ReceiveByte();
	T=MSB;
	T<<=8;
	T|=LSB;
	Temp=T*0.0625;
	return Temp;
}
