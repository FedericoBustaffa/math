#include <iostream>

#include "vec.hpp"

int main()
{
	vec a = vec::rand(3);

	std::cout << a[1] << std::endl;
	a[1] = 1;
	std::cout << a[1] << std::endl;

	return 0;
}
