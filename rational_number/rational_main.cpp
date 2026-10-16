#include <iostream>
#include <cstdint>
#include <exception>

#include "rational.h"

using namespace std;

int main() {
	Rational ra, rb;
	try {
		cin >> ra >> rb;
	} catch (exception & e){
		cout << e.what() << endl;
		return 0;
	}
	ra.print("The first rational number is ", cout);	
	rb.print("The second rational number is ", cout);	

	Rational r_sum(ra + rb);
	r_sum.print("Sum is ", cout);	

	Rational r_difference(ra - rb);
	r_difference.print("Difference is ", cout);	

	Rational r_product(ra * rb);
	r_product.print("Product is ", cout);	

	try {
		Rational r_division(ra / rb);
		r_division.print("Division is ", cout);	
	} catch (exception & e) {
		cout << e.what() << endl;
		return 0;
	}
	
	return 0;
}
