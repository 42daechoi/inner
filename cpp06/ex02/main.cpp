#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	Base *ret;
	int  rand_num;

	std::srand(time(NULL));
	rand_num = rand() % 3;
	if (rand_num == 0)
		ret = new A();
	else if (rand_num == 1)
		ret = new B();
	else
		ret = new C();
	return (ret);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "I'm A class\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "I'm B class\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "I'm C class\n";
}

void identify(Base &p)
{
	try {
		A a = dynamic_cast<A &>(p);	
	} catch (std::exception &e) {
		try {
			B b = dynamic_cast<B &>(p);	
		} catch (std::exception &e) {
			std::cout << "I'm C class\n";
		}
	}
	try {
		A a = dynamic_cast<A &>(p);	
	} catch (std::exception &e) {
		try {
			C b = dynamic_cast<C &>(p);	
		} catch (std::exception &e) {
			std::cout << "I'm B class\n";
		}
	}
	try {
		B a = dynamic_cast<B &>(p);	
	} catch (std::exception &e) {
		try {
			C b = dynamic_cast<C &>(p);	
		} catch (std::exception &e) {
			std::cout << "I'm A class\n";
		}
	}
}

int main(void)
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}