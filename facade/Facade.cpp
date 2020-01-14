#include "Facade.h"
Facade::Facade()
{
	a = new Ac();
	f = new Fan();
	g = new Gas();
	l = new Light();
}
Facade::~Facade()
{
	delete a;
	delete f;
	delete g;
	delete l;
}
void Facade::GotoOffice()
{
	a->AcOff();
	f->FanOff();
	g->GasOff();
	l->LightOff();
}
void Facade::BacktoHome()
{
	a->AcOn();
	f->FanOn();
	g->GasOn();
	l->LightOn();
}