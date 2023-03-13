#include "mat.h"

#include <iostream>

mat::mat(unsigned int rows, unsigned int cols)
	: rows(rows), cols(cols), size(rows * cols)
{
	matrix = new double *[rows];
	for (unsigned int i = 0; i < rows; i++)
		matrix[i] = new double[cols];
}

unsigned int mat::get_rows() const { return rows; }

unsigned int mat::get_cols() const { return cols; }

unsigned int mat::get_size() const { return size; }

double mat::get(unsigned int row, unsigned int col) const { return matrix[row][col]; }

void mat::set(unsigned int row, unsigned int col, double value) { matrix[row][col] = value; }

mat mat::rc_product(const mat &other) const
{
	unsigned int n = rows;
	unsigned int m = cols;
	unsigned int p = other.get_cols();
	mat result(n, p);

	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < p; j++)
		{
			for (unsigned int k = 0; k < m; k++)
				result.set(i, j, result.get(i, j) + matrix[i][k] * other.get(k, j));
		}
	}

	return result;
}

void mat::show() const
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " " << std::flush;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

mat::~mat()
{
	for (unsigned int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}