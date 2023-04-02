#ifndef MAT_PROPERTIES_H
#define MAT_PROPERTIES_H

#include "core.hpp"

#include <string>

template <typename T>
double mat<T>::det() const
{
	if (rows != cols)
		throw std::string("Matrice non quadrata");

	switch (rows)
	{
	case 1:
		return matrix[0][0];
		break;

	case 2:
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		break;
		/*
	case 3:
		double p = 1;
		double s = 0;
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = i; j < 3; j++)
			{
				p *= matrix[j % 3][j % 3];
			}
		}
		break;
		*/

	default:
		break;
	}

	return 0.0;
}

#endif
