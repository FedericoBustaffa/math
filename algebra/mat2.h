#ifndef MAT2_H
#define MAT2_H

#include <iostream>

class mat2
{
public:
    // constructor
    mat2(size_t rows, size_t cols);

    // get value in position (r, c)
    double get(size_t r, size_t c) const;

    // get number of rows
    size_t get_rows() const;

    // get number of columns
    size_t get_cols() const;

    // set value in position (r, c) to <value>
    void set(size_t r, size_t c, double value);

    // sum element by element
    mat2 sum(const mat2 &other) const;

    // sum element by element
    mat2 operator+(const mat2 &other) const;

    // raws by columns product
    mat2 rc_product(const mat2 &other) const;

    // raws by columns product
    mat2 operator*(const mat2 &other) const;

    // display the matrix
    void show() const;

    // destructor
    ~mat2();

private:
    size_t rows, cols;
    double **matrix;
};

#endif
