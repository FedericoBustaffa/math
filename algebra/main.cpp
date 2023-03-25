#include <iostream>

#include "mat2.h"

int main()
{
	mat2 a(3, 3);
	mat2 b(3, 3);

	for (size_t i = 0; i < a.get_rows(); i++)
	{
		for (size_t j = 0; j < a.get_cols(); j++)
		{
			a.set(i, j, i + j * 5);
			b.set(i, j, a.get(i, j) / 10);
		}
	}

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
