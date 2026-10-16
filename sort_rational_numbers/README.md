## Task Description
Implement a class `Rational` that supports the following functions.

* Simplify the rational number.
* The constructor that sets the numerator as $a$ and the denominator as $b$.
* Overload the operator $<$.

In addition, you are asked to overload the operator `>>` between `cin` and `vector<Rational>` and the operator `<<` between `cout` and `vector<Rational>`.
See the sample input and output for the detailed implementaion of I/O.

We will provide the following header file `rational.h`.
```
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
```

We will use the following `rational_main.cpp` file to check the correctness of your implementaion.
```
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
```

## Sample Input
```
3
1/2
3/4
5/6
0
```

## Sample Output
```
5/6
3/4
1/2
```
