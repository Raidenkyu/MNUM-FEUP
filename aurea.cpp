#include <iostream>
#include <cmath>

using namespace std;

double fun(double x){
	return pow(x,4) + x*x - 16*x + 64;
}

int main(){
	double x1 = 0;
	double x2 = 3;
	unsigned int niter = 50;

	const double B = (sqrt(5)-1)/2;
	const double A = B*B;

	double  x3, x4;
	
	cout << "i= " << 0 << "\tx1= " << x1 << "\tx2= " << x2;
	cout << " f(x1)= " << fun(x1) << "\tf(x2)= " << fun(x2) << "\n";
	
	for(unsigned int i = 0; i < niter; i++) {
		x3 = x1 + A*(x2-x1);
		x4 = x1 + B*(x2-x1);
		
		if(fun(x3) < fun(x4)) {
			x2 = x4;
		} else {
			x1 = x3;
		}
		
		cout << "i= " << (i+1) << "\tx1= " << x1 << "\tx2= " << x2;
		cout << " f(x1)= " << fun(x1) << "\tf(x2)= " << fun(x2) << "\n";
	}
	return 0;
}