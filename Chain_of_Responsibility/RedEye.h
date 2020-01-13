#ifndef REDEYE
#define REDEYE
#include "PhotoProcessor.h"
class RedEye :public PhotoProcessor
{
private:
	void processImplementation(Photo &a);
};
#endif //REDEYE

