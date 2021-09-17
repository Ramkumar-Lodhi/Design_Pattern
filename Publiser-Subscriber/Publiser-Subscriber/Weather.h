#pragma once
#include "IPublisher.h"
#include <vector>
#include<iostream>

class Weather : public IPublisher
{
	float m_temp;
	float m_humidity;
	std::vector<ISubscriber *>clientList;
public:
	void Register(ISubscriber*) override;
	void Delete(ISubscriber*) override;
	void notify() override;
	void setWeatherInfo(float temp, float humidity) override;
};

