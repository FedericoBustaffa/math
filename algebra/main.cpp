#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> a(3);
	mat<double> b(3, 1);
	mat<double> c(1, 3);

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			a(i, j) = 1 + i * j;
			b(i) = b(i) + a(j, i);
			c(i) = b(i) / 3;
		}
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << a * b << std::endl;
	std::cout << b * c << std::endl;
	std::cout << c * b << std::endl;

	return 0;
}
