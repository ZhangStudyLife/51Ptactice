 #include <REGX52.H>
 #include "Delay.h"

 /**
   * @brief  获取独立按键键码
   * @param  无
   * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
   */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
 	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=1;}
 	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=2;}
 	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=3;}
 	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=4;}
	
 	return KeyNumber;
 }

 void Key_Loop(void)
 {

 }



//#include <REGX52.H>
//#include "Delay.h"

//unsigned char Key_KeyNumber;

///**
//  * @brief  获取按键键码
//  * @param  无
//  * @retval 按下按键的键码，范围：0,1~4,0表示无按键按下
//  */
//unsigned char Key(void)
//{
//	unsigned char Temp=0;
//	Temp=Key_KeyNumber;
//	Key_KeyNumber=0;
//	return Temp;
//}

///**
//  * @brief  获取当前按键的状态，无消抖及松手检测
//  * @param  无
//  * @retval 按下按键的键码，范围：0,1~4,0表示无按键按下
//  */
//unsigned char Key_GetState()
//{
//	unsigned char KeyNumber=0;
//	
//	if(P3_1==0){KeyNumber=1;}
//	if(P3_0==0){KeyNumber=2;}
//	if(P3_2==0){KeyNumber=3;}
//	if(P3_3==0){KeyNumber=4;}
//	
//	return KeyNumber;
//}

///**
//  * @brief  按键驱动函数，在中断中调用
//  * @param  无
//  * @retval 无
//  */
//void Key_Loop(void)
//{
//	static unsigned char NowState,LastState;
//	LastState=NowState;				//按键状态更新
//	NowState=Key_GetState();		//获取当前按键状态
//	//如果上个时间点按键按下，这个时间点未按下，则是松手瞬间，以此避免消抖和松手检测
//	if(LastState==1 && NowState==0)
//	{
//		Key_KeyNumber=1;
//	}
//	if(LastState==2 && NowState==0)
//	{
//		Key_KeyNumber=2;
//	}
//	if(LastState==3 && NowState==0)
//	{
//		Key_KeyNumber=3;
//	}
//	if(LastState==4 && NowState==0)
//	{
//		Key_KeyNumber=4;
//	}
//}
