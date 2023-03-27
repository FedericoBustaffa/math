#ifndef VEC_H
#define VEC_H

#include <iostream>

class vec
{
public:
    // constructor
    vec(size_t length);
    vec(const vec &other);

    // get and set
    size_t get_length() const;

    double get(size_t index) const;
    void set(size_t index, double value);

    // GET / SET OPERATOR
    double &operator[](size_t r) const;

    // ----- OPERATIONS -----
    vec scalar_sum(double value) const;
    vec scalar_diff(double value) const;
    vec scalar_mul(double value) const;
    vec scalar_div(double value) const;

    vec sum(const vec &other) const;
    vec diff(const vec &other) const;
    vec mul(const vec &other) const;
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

    // STDOUT
    friend std::ostream &operator<<(std::ostream &os, const vec &m);

    // destructor
    ~vec();

    // base tensors
    static vec zeros(size_t length);
    static vec ones(size_t length);
    static vec rand(size_t length);

private:
    size_t length;
    double *tensor;
};

#endif
