#include "Mobile.h"
void Mobile::update(float temp, float humidity) {
	m_temprature = temp;
	m_humidity = humidity;
	std::cout << "Update " << __FUNCTION__ << std::endl;
}