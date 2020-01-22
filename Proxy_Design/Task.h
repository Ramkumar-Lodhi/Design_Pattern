#pragma once
class Task
{
public:
	virtual void Request() = 0;
	virtual ~Task()
	{
	}
};

