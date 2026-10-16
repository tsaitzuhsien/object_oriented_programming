#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <vector>

#include "rational.h"

#define N_MAX 1024

using namespace std;

int main() {
	int n;
	try {
		if (!(cin >> n))
			throw invalid_argument("Input failed.");
		if (n <= 0)
			throw invalid_argument("The number of elements should be positive");
	} catch (exception &e) {
		cout << e.what() << endl;
		return 0;
	}

	vector<Rational> rn;
	rn.resize(n);
	try {
		cin >> rn;
	} catch (exception & e){
		cout << e.what() << endl;
		return 0;
	}

	bool ascending;
	cin >> ascending;

	sort(rn.begin(), rn.end(), [=](const Rational &front, const Rational &rear){ return ((ascending)? (front < rear):!(front < rear)); });

	cout << rn;

	return 0;
}
