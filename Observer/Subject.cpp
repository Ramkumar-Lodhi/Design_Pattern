#include "Subject.h"
void Subject::mAttach(Observer* obj)
{
	m_observer.push_back(obj);
}

void Subject::mDetach(Observer* obj)
{
	int count = m_observer.size();
	int i;
	for (i = 0; i < count; i++) {
		if (m_observer[i] == obj)
			break;
	}
	if (i < count)
		m_observer.erase(m_observer.begin() + i);
}

void Subject::mNotify()
{
	int count = m_observer.size();

	for (int i = 0; i < count; i++)
		(m_observer[i])->mUpdate(this);
}