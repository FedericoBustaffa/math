#ifndef MAT_CORE_H
#define MAT_CORE_H

#include <iostream>
#include <random>
#include <ctime>

template <typename T>
class mat
{
public:
	mat(size_t rows, size_t cols);
	mat(size_t dim);
	mat(const mat &other);

	size_t get_rows() const;
	size_t get_cols() const;
	size_t size() const;

	T &operator()(size_t i, size_t j) const;
	T &operator()(size_t i) const;

	// operazioni scalari
	mat operator+(T scalar) const;
	mat operator-(T scalar) const;
	mat operator*(T scalar) const;
	mat operator/(T scalar) const;

	mat operator+(const mat &other) const;
	mat operator-(const mat &other) const;
	mat operator*(const mat &other) const;

	mat transpose() const;

	static mat zeros(size_t rows, size_t cols);
	static mat zeros(size_t dim);
	static mat ones(size_t rows, size_t cols);
	static mat ones(size_t dim);
	static mat identity(size_t dim);
	static mat rand(size_t rows, size_t cols, T min, T max);
	static mat rand(size_t rows, size_t cols);
	static mat rand(size_t dim, size_t min, size_t max);
	static mat rand(size_t dim);

	~mat();

private:
	size_t rows;
	size_t cols;
	T **matrix;
};

#endif
