#pragma once
#include <iostream>
class ISubscriber
{
public:
	virtual void update(float temp, float humidity) = 0;
};

