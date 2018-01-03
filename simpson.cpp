#include <iostream>

using namespace std;

double foo(double x) { return (x*x); }

int main(){

	/* Integrate f(x) between 0 and 2 */
	const double h = 0.1;
	const unsigned int n = 10;		// The integration limits are [0 .. n*h] : In thsoma case, integrating foo(x) from 0 to 2


	/* Compute the Integral Value */
	double soma = 0, somaPar = 0, somaImpar = 0;



	for (unsigned int i=1 ; i<n ; i+=2)	somaPar += foo(i*h);	// The odd terms , the 4*y.. terms

	for (unsigned int i=2 ; i<n ; i+=2)	somaImpar += foo(i*h);	// The even terms , the 2*y.. terms

	somaPar *= 4;				// 4*(odd terms)

	somaImpar *= 2;				// 2*(even terms)

	soma += foo(0*h);			// y0

	soma += foo(n*h);			// yn

	soma += somaPar + somaImpar;		// y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn

	soma = soma*h/3;				// h/3 * (y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn)


	/* Dsomaplay the Result */
	cout << "Result: " << soma << endl;



	return 0;
}