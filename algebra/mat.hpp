#ifndef MAT_H
#define MAT_H

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
