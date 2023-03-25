#include "mat2.h"

#include <iostream>

// constructor
mat2::mat2(size_t rows, size_t cols)
	: rows(rows), cols(cols)
{
	matrix = new double *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

// get value in position (r, c)
double mat2::get(size_t r, size_t c) const { return matrix[r][c]; }

// get number of rows
size_t mat2::get_rows() const { return rows; }

// get number of columns
size_t mat2::get_cols() const { return cols; }

// set value in position (r, c) to <value>
void mat2::set(size_t r, size_t c, double value) { matrix[r][c] = value; }

// get the inverse if possible
mat2 mat2::inv() const
{
	return *this;
}

// sum element by element
mat2 mat2::sum(const mat2 &other) const
{
	mat2 s(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			s.set(i, j, matrix[i][j] + other.get(i, j));
	}

	return s;
}

// sum element by element
mat2 mat2::operator+(const mat2 &other) const { return sum(other); }

// difference element by element
mat2 mat2::diff(const mat2 &other) const
{
	mat2 d(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			d.set(i, j, matrix[i][j] - other.get(i, j));
	}

	return d;
}

// difference element by element
mat2 mat2::operator-(const mat2 &other) const { return diff(other); }

// raws by columns product
mat2 mat2::rc_product(const mat2 &other) const
{
	size_t other_cols = other.get_cols();
	mat2 p(other_cols, rows);
	double s = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			s = 0;
			for (size_t k = 0; k < rows; k++)
			{
				s += matrix[i][k] * other.get(k, j);
			}
			p.set(i, j, s);
		}
	}

	return p;
}

mat2 mat2::operator*(const mat2 &other) const { return rc_product(other); }

// divides the matrix by the inverse of the other matrix
mat2 mat2::div(const mat2 &other) const
{
	return *this * other.inv();
}

// divides the matrix by the inverse of the other matrix
mat2 mat2::operator/(const mat2 &other) const
{
	return div(other);
}

// display the matrix
void mat2::show() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " " << std::flush;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// destructor
mat2::~mat2()
{
	for (size_t i = 0; i < cols; i++)
		delete[] matrix[i];

	delete[] matrix;
}