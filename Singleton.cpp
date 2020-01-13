#include<iostream>
#include<mutex>
using namespace std;
mutex m;
class Singleton
{
private:
	int m_value;
	static Singleton *m_instance;
	Singleton(int v = 0) { m_value = v; }
public:
	Singleton(const Singleton &rhs) = delete;
	Singleton & operator=(const Singleton &rhs) = delete;
	static Singleton *getInstance();

	//Testing
	void setvalue(int v);
	int getvalue();
};

Singleton* Singleton::m_instance = nullptr;

Singleton * Singleton::getInstance()
{
	m.lock(); //For thread Safe
	if (!m_instance) //If instance exiting skip this condition
	{
		m_instance = new Singleton();   //Instance is creating
	}
	m.unlock();
	return m_instance; 
}
void Singleton::setvalue(int v)
{
	m_value = v;
}
int Singleton::getvalue()
{
	return m_value;
}
void GlobalFun()
{
	Singleton::getInstance()->setvalue(20);
	cout << "Get value in GlobalFun " << Singleton::getInstance()->getvalue() << endl;
}
void GlobalFun2()
{
	Singleton::getInstance()->setvalue(22);
	cout << "Get value in GlobalFun2 " << Singleton::getInstance()->getvalue()<<endl;
}
int main()
{
	Singleton::getInstance()->setvalue(19);
	cout << "Get value in Main " << Singleton::getInstance()->getvalue()<<endl;
	GlobalFun();
	GlobalFun2();
	cout << "Get value in Main " << Singleton::getInstance()->getvalue()<<endl;
	return 0;
}