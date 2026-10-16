#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstdbool>
#include <string>
#include <exception>

#include "rational.h"

using namespace std;

Rational::Rational(int a, int b): numerator(a), denominator(b)
{
	if (b == 0) {
		throw undefined_rational_number("The denominator cannot be zero.\n");
	}
	simplify();
}

Rational Rational::operator+(const Rational &r) const {
	Rational sum(denominator * r.numerator + numerator * r.denominator, denominator * r.denominator);
	sum.simplify();
	return sum;
}

Rational Rational::operator-(const Rational &r) const {
	Rational difference(numerator * r.denominator - denominator * r.numerator, denominator * r.denominator);
	difference.simplify();
	return difference;
}

Rational Rational::operator*(const Rational &r) const {
	Rational product(numerator * r.numerator, denominator * r.denominator);
	product.simplify();
	return product;
}

Rational Rational::operator/(const Rational &r) const {
	Rational division(numerator * r.denominator, denominator * r.numerator);
	division.simplify();
	return division;
}

bool Rational::operator<(const Rational &r) const {
	return (r.denominator * numerator < r.numerator * denominator);
}

void Rational::print(string s, ostream &out) const {
	out << s << numerator << '/' << denominator << endl;
	return;
}

uint32_t gcd(uint32_t u, uint32_t v) {
	if (u % v == 0) {
		return v;
	} else {
		return gcd(v, u % v);
	}
}

void Rational::simplify() {
	uint32_t g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	return;
}

UndefinedRationalNumber::UndefinedRationalNumber(): error_code(332) {
}

const string UndefinedRationalNumber::what() const noexcept override {
	return "The denominator cannot be zero.";
}

istream& operator>>(istream &in, Rational &r) {
	string s;
	if (in >> s) {
		auto slash_pos {s.find("/")};
		if (slash_pos == string::npos)
			exit(-1);
		uint32_t a = stoi(s.substr(0, slash_pos));
		uint32_t b = stoi(s.substr(slash_pos + 1));
		r = Rational(a, b);
	}
	return in;
}

ostream& operator<<(ostream &out, const Rational &r) {
	r.print("", out);
	return out;
}
