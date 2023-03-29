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
