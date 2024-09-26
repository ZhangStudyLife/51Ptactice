#include "HC_SR04.h"
#include "LCD1602.h"

void Delay10us() {
    unsigned char i;
    i = 2;
    while (--i);
}


void startHC() {
    Trig = 0;
    Trig = 1;
    Delay10us();
    Trig = 0;
}

void Time0Init()
{	
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	//���ö�ʱ��0����ģʽ1����ʼֵ�趨0��ʼ���������ż�������ʱ��
}

double HC_SR04_GetDistance()
{
	double time;
	double dis;
	Time0Init();
	
	while(1){
		//1. �������Ͳ�����Trig�˿�����10us�ĸߵ�ƽ
		startHC();
		//2. ��ʼ���Ͳ���Echo�ź��ɵ͵�ƽ��ת���ߵ�ƽ
		while(Echo == 0);
		//   ��ʼ���Ͳ���������ʱ��
		TR0 = 1;
		//3. ���շ��ز���Echo�ź��ɸߵ�ƽ��ת�ص͵�ƽ
		while(Echo == 1);
		//   ���շ��ز���ֹͣ��ʱ��
		TR0 = 0;
		//4. ����ʱ��
		time = (TH0 * 256 + TL0)*1.085;//usΪ��λ
		//5. ���� = �ٶ� ��340m/s��* ʱ��/2
		dis = time * 0.017;
		//��ʱ���������㣬�Ա���һ�β��
		TH0 = 0;
		TL0 = 0;
		return dis;
	}
}
