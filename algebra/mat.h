#ifndef MAT_H
#define MAT_H

class mat
{
public:
	mat(unsigned int rows, unsigned int cols);

	unsigned int get_rows() const;
	unsigned int get_cols() const;
	unsigned int get_size() const;

	double get(unsigned int row, unsigned int col) const;
	void set(unsigned int row, unsigned int col, double value);

	mat rc_product(const mat &m) const;

	void show() const;

	~mat();

private:
	unsigned int rows;
	unsigned int cols;
	unsigned int size;
	double **matrix;
};

#endif