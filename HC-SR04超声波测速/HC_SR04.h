#ifndef __HC_SR04_H__
#define __HC_SR04_H__

#include <REGX52.H>


sbit Trig = P1^5;
sbit Echo = P1^7;

double HC_SR04_GetDistance();

#endif
