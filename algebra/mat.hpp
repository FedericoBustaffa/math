#ifndef MAT_H
#define MAT_H

#include "vec.hpp"

class mat
{
public:
	// constructors
	mat();
	mat(size_t rows, size_t cols);
	mat(size_t dim);
	mat(const mat &other);

	// get and set
	size_t get_rows() const;
	size_t get_cols() const;
	size_t get_size() const;
	vec &get(size_t index) const;
	void set(size_t index, const vec &v);

	vec &operator[](size_t index) const;

	friend std::ostream &operator<<(std::ostream &os, const mat &m);

	~mat();

	// base matrices
	static mat zeros(size_t rows, size_t cols);
	static mat zeros(size_t dim);

	// static mat ones(size_t rows, size_t cols);
	// static mat ones(size_t dim);

	static mat identity(size_t dim);

	static mat rand(size_t rows, size_t cols);
	static mat rand(size_t dim);

private:
	size_t rows;
	size_t cols;
	vec *matrix;
};

#endif