#include <iostream>
#include <vector>

class A {
	public:
		A(int a) { this->a = a; }
	private:
		int a;
};

int main() {
	std::vector<A> v;
	A a = A(1);
	A b = A(2);
	v.push_back(a);
	std::cout << &v[0] << std::endl;
	v.push_back(b);
	std::cout << &v[0] << std::endl;
	std::cout << &v[1] << std::endl;
}