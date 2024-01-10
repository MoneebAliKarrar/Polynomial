#ifndef POLY_H_INCLUDED
#define POLY_H_INCLUDED
#include <iostream>
#include <map>
using namespace std;
class Poly {
  public:
	Poly() = default;
	Poly(double coefficient);
	Poly& operator=(const Poly& a);

	double& operator[](int exponent);

	Poly operator+(const Poly& p) const;
	friend Poly operator+(double b, const Poly& p);

	Poly operator-(const Poly& p) const;
	friend Poly operator-(double b, const Poly& p);

	Poly operator-() const; // Negation

	Poly operator*(const Poly& p) const;
	friend Poly operator*(double b, const Poly& p);

	double operator()(double x) const;

	friend ostream& operator<<(ostream& str, const Poly& p);

  private:
	map<int, double> coefficients;
};

#endif // POLY_H_INCLUDED
