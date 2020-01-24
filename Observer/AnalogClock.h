#pragma once
#include "Observer.h"
#include "ClockTimer.h"
class AnalogClock :	public Observer
{
private:
	ClockTimer *m_subject;
public:
	AnalogClock(ClockTimer *);
	~AnalogClock();
	void mUpdate(Subject *);
	void mDraw();
};

