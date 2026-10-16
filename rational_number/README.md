## Task Description
We continue from the problem Rational Number Operations. Now we want to add the error handler to check whether a rational number operation is valid. We want to detect the following two invalid operations.
* Invalid input
* Division by zero

Please implement the member functions in the class `Rational` and `UndefinedRationalNumber` to compute rational number arithmetics and detect errors.

* The sign of the denominator should be positive.
* The error code of not containing a slash in the input is `334`.
* The error code of divided by zero is `332`.
* When the input does not contain a slash, please print `Error code 334: the slash is required.` to stdout.
* If the denominator of a rational number is zero, please print `Error code 334: the slash is required.` to stdout.
* In the destructor of the exception instance, please print `Destructing the exception with error code XXX`, where XXX is the error code of this instance.

Please submit your header file and .cpp file to the system. We will use the following main function to check the correctness of your programs.

```
#include <iostream>
#include <cstdint>
#include <exception>

#include "rational.h"

using namespace std;

int main() {
	Rational ra, rb;
	try {
		cin >> ra >> rb;
	} catch (exception &e){
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
```

In this problem, you have to provide your own header file and .cpp file.

## Sample Input 1
```
1/2
3/4
```

## Sample Output 1
```
The first rational number is 1/2
The second rational number is 3/4
Sum is 5/4
Difference is -1/4
Product is 3/8
Division is 2/3
```

## Sample Input 2
```
1/2
0/4
```

## Sample Output 2
```
The first rational number is 1/2
The second rational number is 0/1
Sum is 1/2
Difference is 1/2
Product is 0/1
Error code 332: the denominator cannot be zero.
Destructing the exception with error code 332.
```

## Sample Input 3
```
4/0
13
```

## Sample Output 3
```
Error code 332: the denominator cannot be zero.
Destructing the exception with error code 332.
```

## Sample Input 4
```
13
4/0
```
## Sample Output 4
```
Error code 334: the slash is required.
Destructing the exception with error code 334.
```
