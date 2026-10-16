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
	ra.print("ra is ", cout);	
	rb.print("rb is ", cout);	

	Rational r_sum(ra + rb);
	r_sum.print("sum is ", cout);	

	Rational r_dif(ra - rb);
	r_dif.print("dif is ", cout);	

	Rational r_pro(ra * rb);
	r_pro.print("pro is ", cout);	

	try {
		Rational r_div(ra / rb);
		r_div.print("div is ", cout);	
	} catch (exception & e) {
		cout << e.what() << endl;
		return 0;
	}
	
	return 0;
}
