#ifndef MAT_OPERATIONS_H
#define MAT_OPERATIONS_H

#include "core.hpp"

template <typename T>
mat<T> mat<T>::operator+(T scalar) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] + scalar;
	}

	return m;
}

template <typename T>
mat<T> operator+(T scalar, const mat<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	mat<T> r(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) + scalar;
	}

	return r;
}

template <typename T>
mat<T> mat<T>::operator-(T scalar) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] - scalar;
	}

	return m;
}

template <typename T>
mat<T> operator-(T scalar, const mat<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	mat<T> r(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) - scalar;
	}

	return r;
}

template <typename T>
mat<T> mat<T>::operator*(T scalar) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] * scalar;
	}

	return m;
}

template <typename T>
mat<T> operator*(T scalar, const mat<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	mat<T> r(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) * scalar;
	}

	return r;
}

template <typename T>
mat<T> mat<T>::operator/(T scalar) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] / scalar;
	}

	return m;
}

template <typename T>
mat<T> operator/(T scalar, const mat<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	mat<T> r(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) / scalar;
	}

	return r;
}

// somma elemento per elemento
template <typename T>
mat<T> mat<T>::operator+(const mat &other) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] + other(i, j);
	}

	return m;
}

// differenza elemento per elemento
template <typename T>
mat<T> mat<T>::operator-(const mat &other) const
{
	mat m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = matrix[i][j] - other(i, j);
	}

	return m;
}

// prodotto riga per colonna
template <typename T>
mat<T> mat<T>::operator*(const mat &other) const
{
	size_t m_cols = other.get_cols();
	mat m(rows, m_cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
		{
			for (size_t k = 0; k < cols; k++)
				m(i, j) += matrix[i][k] * other(k, j);
		}
	}

	return m;
}

template <typename T>
mat<T> mat<T>::transpose() const
{
	mat t(cols, rows);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			t(j, i) = matrix[i][j];
	}

	return t;
}

#endif