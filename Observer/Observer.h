#pragma once
#include "Subject.h"

class Subject;
class Observer
{
public:
	Observer() {}
	~Observer() {}
	virtual void mUpdate(Subject *changeObj) = 0;
};

