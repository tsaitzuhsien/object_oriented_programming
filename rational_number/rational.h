#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

class Rational {
	private:
		int numerator, denominator;
		void simplify();
	public:
		Rational(int a = 0, int b = 1);
	   	Rational operator+(const Rational &r) const;	
	   	Rational operator-(const Rational &r) const;	
		Rational operator*(const Rational &r) const;
		Rational operator/(const Rational &r) const;
		bool operator<(const Rational &r) const;
		void print(string s, ostream &out) const;
};

class UndefinedRationalNumber: public exception {
	private:
		int error_code;
		char *error_msg;
	public:
		UndefinedRationalNumber(int code) noexcept;
		const char* what() const noexcept override;
		~UndefinedRationalNumber() noexcept;
};

istream& operator>>(istream &in, Rational &r);
ostream& operator<<(ostream &out, const Rational &r);
