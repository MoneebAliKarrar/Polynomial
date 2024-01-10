#include "Poly.h"
#include <cmath>
#include <map>
using namespace std;
// intialization
Poly::Poly(double coefficient)
{
	if (coefficient != 0.0) {
		coefficients[0] = coefficient;
	}
}
Poly& Poly::operator=(const Poly& p)
{
	if (this == &p)
		return *this;

	coefficients = p.coefficients;
	return *this;
}
// display
ostream& operator<<(ostream& str, const Poly& p)
{
	bool first_term = true;

	for (auto it = p.coefficients.rbegin(); it != p.coefficients.rend(); ++it) {
		int degree = it->first;
		double coefficient = it->second;

		if (coefficient != 0) {
			if (!first_term && coefficient > 0) {
				str << " + ";
			}
			else if (coefficient < 0) {
				str << " - ";
			}

			if (std::abs(coefficient) != 1) {
				str << std::abs(coefficient);
			}

			if (degree > 0) {
				str << "x";
				if (degree != 1) {
					str << "^" << degree;
				}
			}
			first_term = false;
		}
	}

	if (first_term) {
		str << "0";
	}

	return str;
}

// operators []
double& Poly::operator[](int exponent)
{
	return coefficients[exponent];
}
// arithmetic operation + - * /
Poly Poly::operator+(const Poly& p) const
{
	Poly result;
	for (const auto& term : coefficients) {
		result.coefficients[term.first] += term.second;
	}
	for (const auto& term : p.coefficients) {
		result.coefficients[term.first] += term.second;
	}
	return result;
}
Poly operator+(double b, const Poly& p)
{
	Poly result = p;
	result.coefficients[0] += b;
	return result;
}
Poly Poly::operator-(const Poly& p) const
{
	Poly result;
	for (const auto& term : coefficients) {
		result.coefficients[term.first] += term.second;
	}
	for (const auto& term : p.coefficients) {
		result.coefficients[term.first] -= term.second;
	}
	return result;
}
Poly operator-(double b, const Poly& p)
{
	Poly result = -p;
	result.coefficients[0] += b;
	return result;
}
// nigation
Poly Poly::operator-() const
{
	Poly result;
	for (const auto& term : coefficients) {
		result.coefficients[term.first] = -term.second;
	}
	return result;
}
Poly Poly::operator*(const Poly& p) const
{
	Poly result;
	for (const auto& term1 : coefficients) {
		for (const auto& term2 : p.coefficients) {
			int new_degree = term1.first + term2.first;
			double new_coefficient = term1.second * term2.second;
			result.coefficients[new_degree] += new_coefficient;
		}
	}
	return result;
}
Poly operator*(double b, const Poly& p)
{
	Poly result;

	for (const auto& term : p.coefficients) {
		result.coefficients[term.first] = term.second * b;
	}

	return result;
}
// value
double Poly::operator()(double x) const
{
	double result = 0.0;
	for (const auto& term : coefficients) {
		result += term.second * pow(x, term.first);
	}
	return result;
}
