#include <iostream>
#include <cstdio>
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
		throw UndefinedRationalNumber(332);
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

UndefinedRationalNumber::UndefinedRationalNumber(int code) noexcept: error_code(code) {
	error_msg = (char *)malloc(sizeof(char) * 256);
}

const char* UndefinedRationalNumber::what() const noexcept {
	if (error_code == 332)
		sprintf(error_msg, "Error code %d: the denominator cannot be zero.", error_code);
	else if (error_code == 334)
		sprintf(error_msg, "Error code %d: the slash is required.", error_code);
	return error_msg;
}

UndefinedRationalNumber::~UndefinedRationalNumber() noexcept {
	free(error_msg);
	cout << "Destructing the exception." << endl;
}

istream& operator>>(istream &in, Rational &r) {
	string s;
	if (in >> s) {
		auto slash_pos {s.find("/")};
		if (slash_pos == string::npos)
			throw UndefinedRationalNumber(334);
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
