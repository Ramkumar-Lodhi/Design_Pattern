#ifndef FILTER
#define FILTER
#include "PhotoProcessor.h"
class Filter :public PhotoProcessor
{
private:
	void processImplementation(Photo &a);
};
#endif
