#include "ProxyTask.h"
ProxyTask::ProxyTask():realTask(new RealTask())
{

}
void ProxyTask::Request()
{
	realTask->Request();
}
