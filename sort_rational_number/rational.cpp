#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

#include "rational.h"

using namespace std;

Rational::Rational(int a, int b): numerator(a), denominator(b)
{
	if (b == 0) {
		throw invalid_argument("The denominator must be positive.");
	}
}

bool Rational::operator<(const Rational &r) const {
	return (r.denominator * numerator < r.numerator * denominator);
}

void Rational::print(string s, ostream &out) const {
	out << s << numerator << '/' << denominator << endl;
	return;
}

istream& operator>>(istream &in, Rational &r) {
	string s;
	if (in >> s) {
		auto slash_pos {s.find("/")};
		if (slash_pos == string::npos)
			throw invalid_argument("No slash in the rational number.");
		int a = stoi(s.substr(0, slash_pos));
		int b = stoi(s.substr(slash_pos + 1));
		r = Rational(a, b);
	}
	return in;
}

ostream& operator<<(ostream &out, const Rational &r) {
	r.print("", out);
	return out;
}

istream& operator>>(istream &in, vector<Rational> &rn) {
	for (auto &r: rn) {
		in >> r;
	}
	return in;
}

ostream& operator<<(ostream &out, const vector<Rational> &rn) {
	for (auto r: rn) {
		out << r;
	}
	return out;
}
