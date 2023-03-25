#include <iostream>

#include "vec.h"

int main()
{
	vec a = vec::zeros(3);

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
