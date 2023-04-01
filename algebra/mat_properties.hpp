#ifndef MAT_PROPERTIES_H
#define MAT_PROPERTIES_H

#include <string>

template <typename T>
double mat<T>::det() const
{
	if (rows != cols)
		throw std::string("Matrice non quadrata");

	return 0.0;
}

#endif
