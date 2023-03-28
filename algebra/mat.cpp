#include "mat.hpp"

#include <random>

mat::mat()
	: rows(0), cols(0)
{
	matrix = nullptr;
}

mat::mat(size_t rows, size_t cols)
	: rows(rows), cols(cols)
{
	matrix = new vec[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = vec(cols);
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

mat::mat(size_t dim)
	: rows(dim), cols(dim)
{
	matrix = new vec[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = vec(cols);
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

mat::mat(const mat &other)
	: rows(other.get_rows()), cols(other.get_cols())
{
	matrix = new vec[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = vec(cols);
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = other[i][j];
	}
}

size_t mat::get_rows() const { return rows; }

size_t mat::get_cols() const { return cols; }

size_t mat::get_size() const { return rows * cols; }

vec &mat::get(size_t index) const { return matrix[index]; }

void mat::set(size_t index, const vec &v) { matrix[index] = v; }

vec &mat::operator[](size_t index) const { return matrix[index]; }

std::ostream &operator<<(std::ostream &os, const mat &m)
{
	for (size_t i = 0; i < m.get_rows(); i++)
	{
		for (size_t j = 0; j < m.get_cols(); j++)
			os << m[i][j] << " " << std::flush;

		std::cout << std::endl;
	}

	return os;
}

mat::~mat()
{
	std::cout << "mat destructor" << std::endl;
	delete matrix;
}

mat mat::zeros(size_t rows, size_t cols) { return mat(rows, cols); };
mat mat::zeros(size_t dim) { return mat(dim, dim); }

// mat mat::ones(size_t rows, size_t cols) { return mat(rows, cols) + 1; }
// mat mat::ones(size_t dim) { return mat(dim, dim) + 1; }

mat mat::identity(size_t dim)
{
	mat id(dim);
	for (size_t i = 0; i < dim; i++)
		id[i][i] = 1;

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
			r[i][j] = distribution(generator);
	}

	return r;
}

mat mat::rand(size_t dim) { return rand(dim, dim); }