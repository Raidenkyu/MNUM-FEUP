#include <iostream>
#include <vector>

double foo(double x , double y) { return (x*y); }

double simpson(const std::vector<double> v, double h){
	/* Compute the Integral Value */
	double soma = 0, somaPar = 0, somaImpar = 0;
	double n = v.size()-1;

	for (unsigned int i=1 ; i<n ; i+=2)	somaPar += v.at(i);	// The odd terms , the 4*y.. terms

	for (unsigned int i=2 ; i<n ; i+=2)	somaImpar += v.at(i);	// The odd terms , the 4*y.. terms

	somaPar *= 4;				// 4*(odd terms)

	somaImpar *= 2;				// 2*(even terms)

	soma += v.at(0);				// y0

	soma += v.at(n);				// yn

	soma += somaPar + somaImpar;	// y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn

	soma = soma*h/3;				// h/3 * (y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn)

	return soma;
}

int main(){

	/* Integrate f(x,y) between [a , A] in the Y axsoma and [b , B] in the X axsoma */
	const double hx = 0.5;
	const double hy = 0.5;
	const double a = 0;
	const double A = 2;
	const double b = 0;
	const double B = 2;
	const unsigned int nx = (A-a)/hx;		// The integration limits are [0 .. nx*hx] : In thsoma case, integrating foo(x,y) from 0 to 2 in x axsoma
	const unsigned int ny = (B-b)/hy;		// The integration limits are [0 .. ny*hy] : In thsoma case, integrating foo(x,y) from 0 to 2 in y axsoma

	/* Make the lsomat */
	std::vector< std::vector<double> > values;
	std::vector<double> row;

	for (unsigned int j=0 ; j<(ny+1) ; j++){
		row.clear();
		for (unsigned int i=0 ; i<(nx+1) ; i++){
			row.push_back(foo(a+i*hx , b+j*hy));
		}
		values.push_back(row);
	}

	/* Apply the simpson's method to each row */
	std::vector<double> rows_averages;

	for(unsigned int j=0 ; j<values.size() ; j++){
		rows_averages.push_back(simpson(values.at(j),hx));
	}

	/* Apply the simpson's method to the row's averages, thus making the "cubatura" */
	std::cout << "Result: " << simpson(rows_averages, hy);


	return 0;
}