#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
	return x*x;
}

int main(){
	double a = -1;
	double b = 1;
	double e = 0.01;
	double c,d;
	double fc,fd;
	const double fi = (sqrt(5)-1)/2;
	while(abs(b-a) > e){
		d = a*(b-a)*fi;
		c = b - (b-a)*fi;
		fc = f(c);
		fd = f(d);
		if(fc < fd){
			b = d;
			d = c;
			fd = fc;
			c = b -(b-a)*fi;
			fc = f(c);
		}

		else{
			a = c;
			c = d;
			fc = f(d);
			d = a+ (b-a)*fi;
			fd = f(d);
		}
		}

	cout << "Inf = " << a << " Sup = " << b << endl;
	return 0;
}