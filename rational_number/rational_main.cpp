#include <iostream>
#include <cstdint>

#include "rational.h"

using namespace std;

int main() {
	Rational ra, rb;
	cin >> ra >> rb;
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
	
	return 0;
}
