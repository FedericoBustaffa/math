#include "vec.hpp"

#include <random>

// constructors
vec::vec()
	: length(0)
{
	vector = nullptr;
}

vec::vec(size_t length)
	: length(length)
{
	vector = new double[length];
	for (size_t i = 0; i < length; i++)
		vector[i] = 0;
}

vec::vec(const vec &other)
	: length(other.get_length())
{
	vector = new double[length];
	for (size_t i = 0; i < length; i++)
	{
		vector[i] = other.get(i);
	}
}

size_t vec::get_length() const { return length; }

double &vec::get(size_t index) const { return vector[index]; }

void vec::set(size_t index, double value) { vector[index] = value; }

double &vec::operator[](size_t index) const { return vector[index]; }

vec vec::scalar_sum(double scalar) const
{
	vec s(length);
	for (size_t i = 0; i < length; i++)
		s.set(i, vector[i] + scalar);

	return s;
}

vec vec::scalar_diff(double scalar) const
{
	vec d(length);
	for (size_t i = 0; i < length; i++)
		d.set(i, vector[i] - scalar);

	return d;
}

vec vec::scalar_mul(double scalar) const
{
	vec p(length);
	for (size_t i = 0; i < length; i++)
		p.set(i, vector[i] * scalar);

	return p;
}

vec vec::scalar_div(double scalar) const
{
	vec dv(length);
	for (size_t i = 0; i < length; i++)
		dv.set(i, vector[i] / scalar);

	return dv;
}

vec vec::sum(const vec &other) const
{
	vec s(length);
	for (size_t i = 0; i < length; i++)
		s.set(i, vector[i] + other.get(i));

	return s;
}

vec vec::diff(const vec &other) const
{
	vec d(length);
	for (size_t i = 0; i < length; i++)
		d.set(i, vector[i] - other.get(i));

	return d;
}

vec vec::mul(const vec &other) const
{
	vec m(length);
	for (size_t i = 0; i < length; i++)
		m.set(i, vector[i] * other.get(i));

	return m;
}

vec vec::div(const vec &other) const
{
	vec dv(length);
	for (size_t i = 0; i < length; i++)
		dv.set(i, vector[i] / other.get(i));

	return dv;
}

vec vec::operator+(double scalar) const { return scalar_sum(scalar); }
vec vec::operator-(double scalar) const { return scalar_diff(scalar); }
vec vec::operator*(double scalar) const { return scalar_mul(scalar); }
vec vec::operator/(double scalar) const { return scalar_div(scalar); }

vec vec::operator+(const vec &other) const { return sum(other); }
vec vec::operator-(const vec &other) const { return diff(other); }
vec vec::operator*(const vec &other) const { return mul(other); }
vec vec::operator/(const vec &other) const { return div(other); }

std::ostream &operator<<(std::ostream &os, const vec &v)
{
	for (size_t i = 0; i < v.get_length(); i++)
		os << v.get(i) << std::endl;

	return os;
}

vec::~vec()
{
	std::cout << "vec destructor" << std::endl;
	delete[] vector;
}

// Static methos for vector generation
vec vec::zeros(size_t length) { return vec(length); }

vec vec::ones(size_t length) { return vec(length) + 1; }

vec vec::rand(size_t length)
{
	vec r(length);
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 1);

	for (size_t i = 0; i < length; i++)
		r.set(i, distribution(generator));

	return r;
}
