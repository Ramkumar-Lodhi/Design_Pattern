#pragma once
#include "Task.h"
#include <memory>
#include "RealTask.h"
#include<iostream>
using namespace std;
class ProxyTask :public Task
{
private:
	unique_ptr<Task>realTask;
public:
	ProxyTask();
	void Request();
};

