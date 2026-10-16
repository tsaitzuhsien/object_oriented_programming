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

	try {
		Rational r_sum(ra + rb);
		Rational r_dif(ra - rb);
		Rational r_pro(ra * rb);
		Rational r_div(ra / rb);
		ra.print("ra is ", cout);	
		rb.print("rb is ", cout);	
		r_sum.print("sum is ", cout);	
		r_dif.print("dif is ", cout);	
		r_pro.print("pro is ", cout);	
		r_div.print("div is ", cout);	
	} catch (exception & e) {
		cout << e.what() << endl;
		return 0;
	}
	
	return 0;
}
