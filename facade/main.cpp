#include<iostream>
#include<memory>
#include<utility>
#include "facade.h"
int main()
{
	std::unique_ptr<Facade>p(new Facade);
	std::cout << "Hi.....I am going to Office. Please, off the necessary things" << std::endl;
	p->GotoOffice();
	std::cout << std::endl;
	std::cout << "Hi.....I am back from Office. Please on the all necessary things" << std::endl;
	p->BacktoHome();

	return 0;
}