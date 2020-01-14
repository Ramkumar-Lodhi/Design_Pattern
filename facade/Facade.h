#ifndef FACADE
#define FACADE
#include "Ac.h"
#include "Light.h"
#include "Gas.h"
#include "Fan.h"

class Facade
{
private:
	Fan *f;
	Light *l;
	Gas *g;
	Ac *a;
public:
	Facade();
	void GotoOffice();
	void BacktoHome();
	virtual ~Facade();
};
#endif
