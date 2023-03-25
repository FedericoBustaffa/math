#include <iostream>
#include <random>

#include "mat2.h"

int main()
{
	mat2 a = mat2::ones(3, 3);
	mat2 b = mat2::identity(3);

	std::cout << "matrix a" << std::endl;
	a.show();
	std::cout << std::endl;

	std::cout << "matrix b" << std::endl;
	b.show();
	std::cout << std::endl;

	std::cout << "matrix a + b" << std::endl;
	(a + b).show();
	std::cout << std::endl;

	std::cout << "matrix a - b" << std::endl;
	(a - b).show();
	std::cout << std::endl;

	std::cout << "matrix a * b" << std::endl;
	(a * b).show();
	std::cout << std::endl;

	std::cout << "matrix b * a" << std::endl;
	(b * a).show();
	std::cout << std::endl;

	return 0;
}
