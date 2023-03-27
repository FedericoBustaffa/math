#include "mat.hpp"

#include <iostream>
#include <random>

// constructors
mat::mat(size_t rows, size_t cols)
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

mat::mat(size_t dim)
	: rows(dim), cols(dim)
{
	matrix = new double *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

mat::mat(const mat &other)
	: rows(other.get_rows()), cols(other.get_cols())
{
	matrix = new double *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = other.get(i, j);
	}
}

size_t mat::get_rows() const { return rows; }
size_t mat::get_cols() const { return cols; }
size_t mat::get_size() const { return rows * cols; }
std::pair<size_t, size_t> mat::get_shape() const { return std::pair<size_t, size_t>(rows, cols); }

double mat::get(size_t r, size_t c) const { return matrix[r][c]; }
void mat::set(size_t r, size_t c, double value) { matrix[r][c] = value; }

mat mat::inv() const
{
	return *this;
}

mat mat::scalar_sum(double value) const
{
	mat s(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			s.set(i, j, matrix[i][j] + value);
	}

	return s;
}

mat mat::scalar_diff(double value) const
{
	mat d(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			d.set(i, j, matrix[i][j] - value);
	}

	return d;
}

mat mat::product_by_scalar(double value) const
{
	mat p(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			p.set(i, j, matrix[i][j] * value);
	}

	return p;
}

mat mat::div_by_scalar(double value) const
{
	mat dv(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			dv.set(i, j, matrix[i][j] / value);
	}

	return dv;
}

mat mat::sum(const mat &other) const
{
	mat s(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			s.set(i, j, matrix[i][j] + other.get(i, j));
	}

	return s;
}

mat mat::diff(const mat &other) const
{
	mat d(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			d.set(i, j, matrix[i][j] - other.get(i, j));
	}

	return d;
}

mat mat::rc_product(const mat &other) const
{
	size_t other_cols = other.get_cols();
	mat p(other_cols, rows);
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

mat mat::div(const mat &other) const
{
	return *this * other.inv();
}

mat mat::operator+(double value) const { return scalar_sum(value); }
mat mat::operator-(double value) const { return scalar_diff(value); }
mat mat::operator*(double value) const { return product_by_scalar(value); }
mat mat::operator/(double value) const { return div_by_scalar(value); }

mat mat::operator+(const mat &other) const { return sum(other); }
mat mat::operator-(const mat &other) const { return diff(other); }
mat mat::operator*(const mat &other) const { return rc_product(other); }
mat mat::operator/(const mat &other) const { return div(other); }

void mat::show() const
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

mat::~mat()
{
	for (size_t i = 0; i < cols; i++)
		delete[] matrix[i];

	delete[] matrix;
}

// Static methos for matrix generation
mat mat::zeros(size_t rows, size_t cols) { return mat(rows, cols); }
mat mat::zeros(size_t dim) { return zeros(dim, dim); }

mat mat::ones(size_t rows, size_t cols) { return mat(rows, cols) + 1; }
mat mat::ones(size_t dim) { return ones(dim, dim); }

mat mat::identity(size_t dim)
{
	mat id(dim, dim);
	for (size_t i = 0; i < dim; i++)
		id.set(i, i, 1);

	return id;
}

mat mat::rand(size_t rows, size_t cols)
{
	mat r(rows, cols);
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 1);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r.set(i, j, distribution(generator));
	}

	return r;
}

mat mat::rand(size_t dim) { return rand(dim, dim); }