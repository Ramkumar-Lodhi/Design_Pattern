#pragma once
#include "Observer.h"
#include "ClockTimer.h"
class DigitalClock :public Observer
{
private:
	ClockTimer *m_subject;
public:
	DigitalClock(ClockTimer *);
	~DigitalClock();
	void mUpdate(Subject *);
	void mDraw();
};

