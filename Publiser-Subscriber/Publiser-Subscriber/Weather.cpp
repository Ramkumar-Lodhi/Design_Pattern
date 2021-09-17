#include "Weather.h"

void Weather::Register(ISubscriber* client) {
	if (client != nullptr) {
		clientList.push_back(client);
		std::cout << "subscriber registered successdully " << std::endl;
	} else {
		std::cout << "Allocation failed " << std:: endl;
	}
}

void Weather::Delete(ISubscriber* client) {
	auto itr = std::find(clientList.begin(), clientList.end(), client);
	if (itr != clientList.end()) {
		clientList.erase(itr);
		std::cout << "Deleted subscriber successfully " << std::endl;
	} else {
		std::cout << "Subscriber not longer available " << std::endl;
	}
}

void Weather::notify() {
	for (auto it : clientList)
		it->update(m_temp, m_humidity);
}

void Weather::setWeatherInfo(float temp, float humidity) {
	m_temp = temp;
	m_humidity = humidity;
	notify();
}
