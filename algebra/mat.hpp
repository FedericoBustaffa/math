#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <random>
#include <ctime>

template <typename T>
class mat
{
public:
	mat(size_t rows, size_t cols) : rows(rows), cols(cols)
	{
		matrix = new T *[rows];
		for (size_t i = 0; i < rows; i++)
		{
			matrix[i] = new T[cols];
			for (size_t j = 0; j < cols; j++)
				matrix[i][j] = 0;
		}
	}

	mat(size_t dim) : mat(dim, dim)
	{
	}

	mat(const mat<T> &other) : mat(other.get_rows(), other.get_cols())
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				matrix[i][j] = other.matrix[i][j];
		}
	}

	size_t get_rows() const { return rows; }

	size_t get_cols() const { return cols; }

	size_t size() const { return rows * cols; }

	T &operator()(size_t i, size_t j) const { return matrix[i][j]; };

	T &operator()(size_t i) const
	{
		if (cols == 1)
			return matrix[i][0];
		else
			return matrix[0][i];
	}

	// operazioni scalari
	mat operator+(T scalar) const
	{
		mat m(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				m(i, j) = matrix[i][j] + scalar;
		}

		return m;
	}

	mat operator-(T scalar) const
	{
		mat m(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				m(i, j) = matrix[i][j] - scalar;
		}

		return m;
	}

	mat operator*(T scalar) const
	{
		mat m(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				m(i, j) = matrix[i][j] * scalar;
		}

		return m;
	}

	mat operator/(T scalar) const
	{
		mat m(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				m(i, j) = matrix[i][j] / scalar;
		}

		return m;
	}

	// somma elemento per elemento
	mat operator+(const mat &other) const
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
	mat operator-(const mat &other) const
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
	mat operator*(const mat &other) const
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

	mat transpose() const
	{
		mat t(cols, rows);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
				t(j, i) = matrix[i][j];
		}

		return t;
	}

	// stdout
	friend std::ostream &operator<<(std::ostream &os, const mat &m)
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

	static mat zeros(size_t rows, size_t cols) { return mat(rows, cols); }
	static mat zeros(size_t dim) { return mat(dim); }

	static mat ones(size_t rows, size_t cols) { return mat(rows, cols) + 1; }
	static mat ones(size_t dim) { return mat(dim) + 1; }

	static mat identity(size_t dim)
	{
		mat id(dim);
		for (size_t i = 0; i < dim; i++)
			id(i, i) = 1;

		return id;
	}

	static mat rand(size_t rows, size_t cols, T min, T max)
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

	static mat rand(size_t rows, size_t cols) { return rand(rows, cols, 0, 1); }

	static mat rand(size_t dim, size_t min, size_t max) { return rand(dim, dim, min, max); }

	static mat rand(size_t dim) { return rand(dim, dim, 0, 1); }

	~mat()
	{
		for (size_t i = 0; i < rows; i++)
			delete[] matrix[i];

		delete[] matrix;
	}

private:
	size_t rows;
	size_t cols;
	T **matrix;
};

#endif
