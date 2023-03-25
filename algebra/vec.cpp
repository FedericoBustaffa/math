#include "vec.h"

#include <iostream>
#include <random>

// constructor
vec::vec(size_t length)
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

size_t vec::get_rows() const { return rows; }
size_t vec::get_cols() const { return cols; }
double vec::get(size_t r, size_t c) const { return matrix[r][c]; }
void vec::set(size_t r, size_t c, double value) { matrix[r][c] = value; }

vec vec::inv() const
{
	return *this;
}

vec vec::scalar_sum(double value) const
{
	vec s(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			s.set(i, j, matrix[i][j] + value);
	}

	return s;
}

vec vec::scalar_diff(double value) const
{
	vec d(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			d.set(i, j, matrix[i][j] - value);
	}

	return d;
}

vec vec::product_by_scalar(double value) const
{
	vec p(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			p.set(i, j, matrix[i][j] * value);
	}

	return p;
}

vec vec::div_by_scalar(double value) const
{
	vec dv(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			dv.set(i, j, matrix[i][j] / value);
	}

	return dv;
}

vec vec::sum(const vec &other) const
{
	vec s(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			s.set(i, j, matrix[i][j] + other.get(i, j));
	}

	return s;
}

vec vec::diff(const vec &other) const
{
	vec d(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			d.set(i, j, matrix[i][j] - other.get(i, j));
	}

	return d;
}

vec vec::rc_product(const vec &other) const
{
	size_t other_cols = other.get_cols();
	vec p(other_cols, rows);
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

vec vec::div(const vec &other) const
{
	return *this * other.inv();
}

vec vec::operator+(double value) const { return scalar_sum(value); }
vec vec::operator-(double value) const { return scalar_diff(value); }
vec vec::operator*(double value) const { return product_by_scalar(value); }
vec vec::operator/(double value) const { return div_by_scalar(value); }

vec vec::operator+(const vec &other) const { return sum(other); }
vec vec::operator-(const vec &other) const { return diff(other); }
vec vec::operator*(const vec &other) const { return rc_product(other); }
vec vec::operator/(const vec &other) const { return div(other); }

void vec::show() const
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

vec::~vec()
{
	for (size_t i = 0; i < cols; i++)
		delete[] matrix[i];

	delete[] matrix;
}

vec vec::zeros(size_t rows, size_t cols) { return vec(rows, cols); }

vec vec::ones(size_t rows, size_t cols) { return vec(rows, cols) + 1; }

vec vec::identity(size_t size)
{
	vec id(size, size);
	for (size_t i = 0; i < size; i++)
		id.set(i, i, 1);

	return id;
}

vec vec::rand(size_t rows, size_t cols)
{
	vec r(rows, cols);
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 1);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r.set(i, j, distribution(generator));
	}

	return r;
}