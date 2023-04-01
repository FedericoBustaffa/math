#include <iostream>

#include "mat.hpp"

int main()
{
	mat<double> a = mat<double>::identity(3);
	mat<double> b(4, 8);

	try
	{
		std::cout << a.det() << std::endl;
		std::cout << b.det() << std::endl;
	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
	}

	return 0;
}
