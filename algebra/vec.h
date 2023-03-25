#ifndef VEC_H
#define VEC_H

#include <cstdio>

class vec
{
public:
    // constructor
    vec(size_t length);

    // get / set
    size_t get_length() const;

    double get(size_t index) const;
    void set(size_t index, double value);

    // ----- OPERATIONS -----
    vec inv() const;

    vec scalar_sum(double value) const;
    vec scalar_diff(double value) const;
    vec product_by_scalar(double value) const;
    vec div_by_scalar(double value) const;

    vec sum(const vec &other) const;
    vec diff(const vec &other) const;
    vec rc_product(const vec &other) const;
    vec div(const vec &other) const;

    // ----- OPERATORS -----
    vec operator+(double value) const;
    vec operator-(double value) const;
    vec operator*(double value) const;
    vec operator/(double value) const;

    vec operator+(const vec &other) const;
    vec operator-(const vec &other) const;
    vec operator*(const vec &other) const;
    vec operator/(const vec &other) const;

    // UTILITY
    void show() const;

    // destructor
    ~vec();

    // base matrices
    static vec zeros(size_t length);
    static vec ones(size_t length);
    static vec rand(size_t length);

private:
    size_t length;
    double *vector;
};

#endif
