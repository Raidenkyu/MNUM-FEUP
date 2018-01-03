#include <iostream>

using namespace std;


double foo(double x, double y){
	return x*y;
}

int main(){
	/* Initial conditions */
	const double x0 = 1;
	const double y0 = 1;
	const unsigned int n = 60;	// Number of iterations
	const double step = 0.01;


	/* Useful Variables */
	double x = x0;
	double y = y0;
	double d1 , d2 , d3 , d4;


	/* Print the values in (x0 , y0) */
	cout << "Iteracao n 0" << endl;
	cout << "X = " << x << "   -->   Y = " << y << endl;

	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the increments */
		d1 = step*foo(x,y);
		d2 = step*foo(x+step/2.0 , y + d1/2.0);
		d3 = step*foo(x*step/2.0 , y + d2/2.0);
		d4 = step*foo(x*step , y + d3);

		/* Compute the new X and the new Y */
		y = y + (d1/6 + d2/3 + d3/3 + d4/6);
		x = x + step;

		/* Print the function's value in X */
		cout << "Iteracao n " << i+1 << endl;
		cout << "X = " << x << "   -->   Y = " << y << endl;
	}
	cin.get();
	return 0;
}