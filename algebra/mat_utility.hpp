#ifndef MAT_UTILITY_H
#define MAT_UTILITY_H

#include "mat_core.hpp"

template <typename T>
mat<T>::mat(size_t rows, size_t cols) : rows(rows), cols(cols)
{
	matrix = new T *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

template <typename T>
mat<T>::mat(size_t dim) : mat(dim, dim)
{
}

template <typename T>
mat<T>::mat(const mat<T> &other) : mat(other.get_rows(), other.get_cols())
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = other.matrix[i][j];
	}
}

template <typename T>
size_t mat<T>::get_rows() const { return rows; }

template <typename T>
size_t mat<T>::get_cols() const { return cols; }

template <typename T>
size_t mat<T>::size() const { return rows * cols; }

template <typename T>
T &mat<T>::operator()(size_t i, size_t j) const { return matrix[i][j]; }

template <typename T>
T &mat<T>::operator()(size_t i) const
{
	if (cols == 1)
		return matrix[i][0];
	else
		return matrix[0][i];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const mat<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			os << m(i, j) << " " << std::flush;
		}
		std::cout << std::endl;
	}

	return os;
}

template <typename T>
mat<T> mat<T>::zeros(size_t rows, size_t cols) { return mat(rows, cols); }

template <typename T>
mat<T> mat<T>::zeros(size_t dim) { return mat(dim); }

template <typename T>
mat<T> mat<T>::ones(size_t rows, size_t cols) { return mat(rows, cols) + 1; }

template <typename T>
mat<T> mat<T>::ones(size_t dim) { return mat(dim) + 1; }

template <typename T>
mat<T> mat<T>::identity(size_t dim)
{
	mat id(dim);
	for (size_t i = 0; i < dim; i++)
		id(i, i) = 1;

	return id;
}

template <typename T>
mat<T> mat<T>::rand(size_t rows, size_t cols, T min, T max)
{
	mat r(rows, cols);
	std::default_random_engine engine;
	engine.seed(time(nullptr));
	std::uniform_real_distribution<T> distribution(min, max);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = distribution(engine);
	}

	return r;
}

template <typename T>
mat<T> mat<T>::rand(size_t rows, size_t cols) { return rand(rows, cols, 0, 1); }

template <typename T>
mat<T> mat<T>::rand(size_t dim, size_t min, size_t max) { return rand(dim, dim, min, max); }

template <typename T>
mat<T> mat<T>::rand(size_t dim) { return rand(dim, dim, 0, 1); }

template <typename T>
mat<T>::~mat()
{
	for (size_t i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

#endif