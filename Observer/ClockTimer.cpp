#include "ClockTimer.h"

ClockTimer::ClockTimer() 
{
	_strtime(m_buf);
};
void ClockTimer::mTick()
{
	_tzset();
	_strtime(m_buf);
	mNotify();
}

int ClockTimer::mGetHour()
{
	char timebuf[128];
	strncpy(timebuf, m_buf, 2);
	timebuf[2] = NULL;
	return atoi(timebuf);
}

int ClockTimer::mGetMinute()
{
	char timebuf[128];
	strncpy(timebuf, m_buf + 3, 2);
	timebuf[2] = NULL;

	return atoi(timebuf);
}

int ClockTimer::mGetSecond()
{
	char timebuf[128];
	strncpy(timebuf, m_buf + 6, 2);
	timebuf[2] = NULL;

	return atoi(timebuf);
}

