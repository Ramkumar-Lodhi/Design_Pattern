#include<iostream>
#include "ClockTimer.h"
#include "DigitalClock.h"
#include "AnalogClock.h"

int main()
{
	ClockTimer timer;
	DigitalClock digitalClock(&timer);
	AnalogClock analogClock(&timer);

	timer.mTick();
	return 0;
}