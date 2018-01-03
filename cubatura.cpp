#include <iostream>
#include <cmath>

using namespace std;

double foo(double x, double y){
	return x*y;
}

int main(){
	double hx = 0.5;
	double hy = 0.5;
	double A = 1;
	double a = 0;
	double B = 1;
	double b = 0;
	double nx = (A-a)/hx;
	double ny = (B-b)/hy;
	double soma, somaPar, somaImpar;
	double integral = 0, integralPar = 0, integralImpar = 0;
	for(unsigned int i = 1; i <= nx;i+=2){
		soma = 0;somaPar = 0; somaImpar = 0;
		for(unsigned int j = 1; j < (ny);j+=2) 
			somaImpar += foo(i*hx,j*hy);
		for(unsigned int j = 2;j< (ny);j+=2)
			somaPar += foo(i*hx,j*hy);
		soma += somaPar*2 + somaImpar*4 + foo(hx*i,0) + foo(nx*hx,0);
		integralImpar += soma;
	}
	
	for(unsigned int i = 2; i <= nx;i+=2){
		soma = 0;somaPar = 0; somaImpar = 0;
		for(unsigned int j = 1; j < (ny);j+=2) 
			somaImpar += foo(i*hx,j*hy);
		for(unsigned int j = 2;j< (ny);j+=2)
			somaPar += foo(i*hx,j*hy);
		soma += somaPar*2 + somaImpar*4 + foo(hx*i,0) + foo(nx*hx,0);
		integralPar += soma;
	}
	integral += integralPar*2 + integralImpar*4 + foo(0,0)+foo(nx*hx,ny*hy);
	integral = integral * ((hy*hx)/9);
	cout << "Result: " << integral << endl;
}