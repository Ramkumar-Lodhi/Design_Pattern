#pragma once
#include "Subject.h"
class ClockTimer :public Subject
{
private:
	char m_buf[128];
public:
	ClockTimer();// { _strtime(m_buf);
	int mGetHour();
	int mGetMinute();
	int mGetSecond();
	void mTick();
};

