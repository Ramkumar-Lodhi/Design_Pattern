#ifndef SCALE_DEF
#define SCALE_DEF
#include "PhotoProcessor.h"
class Scale :public PhotoProcessor
{
private:
	void processImplementation(Photo &a);
public:
	enum SCALE { S50, S100, S200, S300, S500 };
	Scale(SCALE s);
private:
	SCALE mSCALE;
};

#endif // SCALE

