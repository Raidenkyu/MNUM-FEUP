#include <iostream>

using namespace std;

double foo(double x) { return (x*x); }

int main(){

	const double a = 0;
	const double b = 1;
	const double h = 0.1;
	const unsigned int n = (b-a)/h;

	double integral = 0;

	// Compute the middle terms (all except y0 and yn)
	for (unsigned int i=1 ; i<n ; i++){
		integral += foo(a + i*h);
	}

	integral *= 2; 	// The middle terms have coeficient 2

	integral += foo(0);	// y0
	integral += foo(a+n*h);	// yn

	integral *= h/2;		// I = h/2 * (y0 + 2y1 + 2y2 + ... + 2y(n-1) + y(n) )

	cout << integral << endl;

	return 0;
}