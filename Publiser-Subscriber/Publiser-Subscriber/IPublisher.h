#pragma once
#include "ISubscriber.h"

class IPublisher
{
public:
	virtual void Register(ISubscriber *) = 0;
	virtual void Delete(ISubscriber *) = 0;
	virtual void notify() = 0;
	virtual void setWeatherInfo(float temp, float humidity) = 0;
};

