#include "Photo.h"
Photo::Photo(std::string s) : mTitle(s)
{
	std::cout << "In Photo class Processing " << mTitle << " ...\n";
}