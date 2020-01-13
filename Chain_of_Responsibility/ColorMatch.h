#ifndef COLORMATCH
#define COLORMATCH
#include "PhotoProcessor.h"
class ColorMatch :public PhotoProcessor
{
private:
	void processImplementation(Photo &a);
};
#endif
