#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>

using namespace std;

class Rational {
	private:
		int numerator, denominator;
		void simplify();
	public:
		Rational(int a = 0, int b = 1);
		bool operator<(const Rational &r) const;
		void print(string s, ostream &out) const {
			out << s << numerator << '/' << denominator << endl;
			return;
		}
};

istream& operator>>(istream &in, vector<Rational> &rn);
ostream& operator<<(ostream &out, const vector<Rational> &rn);
