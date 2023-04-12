#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> a = mat<double>::identity(3);
	mat<double> b(4, 8);

    std::cout << a << std::endl;

	return 0;
}
