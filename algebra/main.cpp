#include <iostream>

#include "mat.hpp"

int main()
{
	mat a = mat::zeros(3, 4);
	std::cout << a.get_size() << std::endl;

	mat b = a;
	std::cout << b.get_size() << std::endl;

	a.show();
	b.show();

	return 0;
}
