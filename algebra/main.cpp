#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> a = mat<double>::ones(4) + 2;
	mat<double> i = mat<double>::identity(4);

	std::cout << a * i << std::endl;
    auto shape = a.shape();
    std::cout << "a shape: (" << shape.first << ", " << shape.second << ")" << std::endl;

	return 0;
}
