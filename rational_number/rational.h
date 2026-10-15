#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Rational {
	private:
		int denominator, numerator;
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

istream& operator>>(istream &in, Rational &r);
ostream& operator<<(ostream &out, const Rational &r);
