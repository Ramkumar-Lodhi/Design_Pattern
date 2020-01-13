#include "PhotoProcessor.h"
PhotoProcessor::PhotoProcessor() : mNextProcessor(0) { }
void PhotoProcessor::process(Photo &p)
{
	processImplementation(p);
	if (mNextProcessor != 0)
	{
		mNextProcessor->process(p);
	}
}

PhotoProcessor::~PhotoProcessor() { }
void PhotoProcessor::setNextProcessor(PhotoProcessor *p)
{
	mNextProcessor = p;
}