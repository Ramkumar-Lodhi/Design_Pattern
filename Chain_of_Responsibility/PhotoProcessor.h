#ifndef PHOTO_PROCESSOR
#define PHOTO_PROCESSOR

#include "Photo.h"
class PhotoProcessor
{
private:
	PhotoProcessor *mNextProcessor;
protected:
	virtual void processImplementation(Photo &a) = 0;
public:
	PhotoProcessor();
	void process(Photo &p);
	void setNextProcessor(PhotoProcessor *p);
	virtual ~PhotoProcessor();
};
#endif //PHOTO_PROCESSOR
