#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> m(3);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			m(i, j) = 1 + i * j;
		}
	}
	std::cout << m << std::endl;

	mat<double> m2 = m;
	std::cout << m2 << std::endl;

	return 0;
}
