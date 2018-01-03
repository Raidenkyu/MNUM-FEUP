#include <iostream>

double foo (double x , double y) {return (y);}		// dy/dx = y   ---->   y = e^x

int main(){
	/* Initial conditions */
	const double x0 = 0;
	const double y0 = 1;
	const unsigned int n = 60;	// Number of iterations
	const double step = 0.1	;


	/* Useful Variables */
	double x = x0;
	double y = y0;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the new X and the new Y */
		y = y + step*foo(x,y);
		x = x + step;


		/* Print the function's value in X */
		std::cout << "X = " << x << "   -->   Y = " << y << '\n';
	}

	return 0;
}