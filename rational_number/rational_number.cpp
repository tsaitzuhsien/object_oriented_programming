#include <iostream>
#include <cstdlib>

#include "rational.h"

class Rational {
	private:
		uint32_t denominator, numerator;
		void simplify();
	public:
		Rational(uint32_t a, uint32_t b): numerator(a), denominator(b)
		{}
	   	Rational operator+(const Rational &r) const;	
	   	Rational operator-(const Rational &r) const;	
		Rational operator*(const Rational &r) const;
		Rational operator/(const Rational &r) const;
		bool operator<(const Rational &r) const;
};

Rational::operator+(const Rational &r) const {
	Rational sum(denominator * r.numerator + numerator * r.denominator, denominator * r.denominator);
	sum.simplify();
	return sum;
}

Rational::operator-(const Rational &r) const {
	Rational difference(numerator * r.denominator - denominator * r.numerator, denominator * r.denominator);
	difference.simplify();
	return difference;
}

Rational::operator*(const Rational &r) const {
	Rational product(numerator * r.denominator - denominator * r.numerator, denominator * r.denominator);
	product.simplify();
	return product;
}

Rational::operator/(const Rational &r) const {
	Rational division(numerator * r.denominator - denominator * r.numerator, denominator * r.denominator);
	division.simplify();
	return division;
}

Rational::operator<(const Rational &r) const {
	return (r.denominator * numerator < r.numerator * denominator);
}

uint32_t gcd(uint32_t u, uint32_t v) {
	if (u % v == 0) {
		return v;
	} else {
		return gcd(v, u % v);
	}
}

Rational::simplify() {
	uint32_t g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	return;
}

int main() {
	
}
