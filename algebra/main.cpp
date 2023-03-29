#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> a = mat<double>::ones(4) + 2;
	mat<double> i = mat<double>::identity(4);

	std::cout << a * i << std::endl;

	return 0;
}
