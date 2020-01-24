#include "AnalogClock.h"
AnalogClock::AnalogClock(ClockTimer *s)
{
	m_subject = s;
	m_subject->mAttach(this);
}

AnalogClock::~AnalogClock()
{
	m_subject->mDetach(this);
}

void AnalogClock::mUpdate(Subject *ChangedSubject)
{
	if (ChangedSubject == m_subject)
		mDraw();
}

void AnalogClock::mDraw()
{
	int hour = m_subject->mGetHour();
	int minute = m_subject->mGetMinute();
	int second = m_subject->mGetSecond();

	std::cout << "Analog time is " << hour << ":"<< minute << ":"<< second << std::endl;
}