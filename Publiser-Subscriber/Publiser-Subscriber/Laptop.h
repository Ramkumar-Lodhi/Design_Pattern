#pragma once
#include "ISubscriber.h"
class Laptop :
    public ISubscriber
{
private:
    float m_temprature;
    float m_humidity;
public:
    void update(float temp, float humidity) override;
};
