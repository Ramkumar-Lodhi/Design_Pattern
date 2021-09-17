#include "Tablet.h"

void Tablet::update(float temp, float humidity) {
	m_temprature = temp;
	m_humidity = humidity;
	std::cout << "Update " << __FUNCTION__ << std::endl;
}