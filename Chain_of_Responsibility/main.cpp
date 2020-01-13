#include<iostream>
#include "Photo.h"
#include "Colormatch.h"
#include "Filter.h"
#include "PhotoProcessor.h"
#include "RedEye.h"
#include "Scale.h"

using namespace std;

void processPhoto(Photo &photo)
{
	cout << "Photo Editing Started !!!!!" << endl;
	ColorMatch match;
	RedEye eye;
	Filter filter;
	Scale scale(Scale::S200);
	scale.setNextProcessor(&eye);
	eye.setNextProcessor(&match);
	match.setNextProcessor(&filter);
	scale.process(photo);
}

int main()
{
	Photo *p = new Photo("X2018 Photo");
	processPhoto(*p);
	cout << "Commpleted !!!!!" << endl;
	return 0;
}
