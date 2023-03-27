#ifndef mat_H
#define mat_H

#include <cstdio>
#include <tuple>

class mat
{
public:
    // constructor
    mat(size_t rows, size_t cols);
    mat(size_t dim);
    mat(const mat &other);

    // get and set
    size_t get_rows() const;
    size_t get_cols() const;
    size_t get_size() const;
    std::pair<size_t, size_t> get_shape() const;

    double get(size_t r, size_t c) const;
    void set(size_t r, size_t c, double value);

    // GET / SET OPERATORS
    // vec operator[](size_t r) const;
    // vec &operator[](size_t r);

    // ----- OPERATIONS -----
    mat inv() const;

    mat scalar_sum(double value) const;
    mat scalar_diff(double value) const;
    mat product_by_scalar(double value) const;
    mat div_by_scalar(double value) const;

    mat sum(const mat &other) const;
    mat diff(const mat &other) const;
    mat rc_product(const mat &other) const;
    mat div(const mat &other) const;

    // ----- OPERATORS -----
    mat operator+(double value) const;
    mat operator-(double value) const;
    mat operator*(double value) const;
    mat operator/(double value) const;

    mat operator+(const mat &other) const;
    mat operator-(const mat &other) const;
    mat operator*(const mat &other) const;
    mat operator/(const mat &other) const;

    // UTILITY
    void show() const;

    // destructor
    ~mat();

    // base matrices
    static mat zeros(size_t rows, size_t cols);
    static mat zeros(size_t dim);

    static mat ones(size_t rows, size_t cols);
    static mat ones(size_t dim);

    static mat identity(size_t dim);

    static mat rand(size_t rows, size_t cols);
    static mat rand(size_t dim);

private:
    size_t rows, cols;
    double **matrix;
};

#endif
