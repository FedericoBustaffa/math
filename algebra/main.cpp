#include <iostream>

#include "mat.h"

int main()
{
	mat a(2, 2);
	mat b(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a.set(i, j, i + j);
			b.set(i, j, i * j);
		}
	}

	mat c = a.rc_product(b);

	a.show();
	b.show();
	c.show();

	return 0;
}
