#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
#include "Observer.h"
using namespace std;
class Observer;
class Subject
{
private:
	std::vector<Observer *> m_observer;
public:
	Subject(){ }
	~Subject() {}
	virtual void mAttach(Observer *);
	virtual void mDetach(Observer *);
	virtual void mNotify();
};

