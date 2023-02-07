#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
	Animal *animal[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete animal[i];
	}
    system("leaks a.out");
    return 0; 
}