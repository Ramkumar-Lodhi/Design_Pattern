#include "DigitalClock.h"
#include <iostream>

DigitalClock::DigitalClock(ClockTimer *s)
{
	m_subject = s;
	m_subject->mAttach(this);
}

DigitalClock::~DigitalClock()
{
	m_subject->mDetach(this);
}

void DigitalClock::mUpdate(Subject *ChangedSubject)
{
	if (ChangedSubject == m_subject)
		mDraw();
}

void DigitalClock::mDraw()
{
	int hour = m_subject->mGetHour();
	int minute = m_subject->mGetMinute();
	int second = m_subject->mGetSecond();

	std::cout << "Digital time is " << hour << ":"
		<< minute << ":"
		<< second << std::endl;
}

