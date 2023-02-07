#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t ret;

	ret = reinterpret_cast<std::uintptr_t>(ptr);
	return (ret);
}

Data* deserialize(uintptr_t raw)
{
	Data *ret;

	ret = reinterpret_cast<Data *>(raw);
	return (ret);
}

int main(void)
{
	Data data;
	Data *ptr;
	uintptr_t raw;
	
	raw = serialize(&data);
	std::cout << (uintptr_t)&data << std::endl;
	std::cout << raw << std::endl;
	ptr = deserialize(raw);
	std::cout << ((ptr == &data) ? "true" : "false") << std::endl;
}