#include "ProxyTask.h"
int main()
{
	unique_ptr<ProxyTask> p(new ProxyTask());
	p->Request();
	return 0;
}