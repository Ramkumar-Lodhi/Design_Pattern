#include "Laptop.h"
void Laptop::update(float temp, float humidity) {
	m_temprature = temp;
	m_humidity = humidity;
	std::cout << "Update " << __FUNCTION__ << std::endl;
}