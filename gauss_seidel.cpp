#include <iostream>
#include <cmath>

using namespace std;

double modulo_residuo(double a, double b, double c, double d){
	return sqrt(a*a + b*b + c*c + d*d);
}

int main(){

	double matrix[4][5] = { { 95 , 3   , 1  , 2  , 101},
			                { 4  , 100 , 10 , 5  , 119},
							{ 3  , 9   , 55 , 5  , 72 },
							{ 10 , 2   , 4  , 80 , 96 }};

	double x1 = 2;
	double x2 = 3;
	double x3 = 0;
	double x4 = 9;

	for (unsigned int i=0 ; i<10 ; i++){

		x1 = (matrix[0][4] - (matrix[0][1]*x2 + matrix[0][2]*x3 + matrix[0][3]*x4))/matrix[0][0];
		x2 = (matrix[1][4] - (matrix[1][0]*x1 + matrix[1][2]*x3 + matrix[1][3]*x4))/matrix[1][1];
		x3 = (matrix[2][4] - (matrix[2][0]*x1 + matrix[2][1]*x2 + matrix[2][3]*x4))/matrix[2][2];
		x4 = (matrix[3][4] - (matrix[3][0]*x1 + matrix[3][1]*x2 + matrix[3][2]*x3))/matrix[3][3];

		cout << "**********  Iteracao no. " << i+1 << "  **********\n";
		cout << "[ " << x1 << '\t' << x2 << '\t' << x3 << '\t' << x4 << " ]" << endl;
		cout <<"Residuo: " << modulo_residuo(matrix[0][4]-(matrix[0][0]*x1+matrix[0][1]*x2+matrix[0][2]*x3+matrix[0][3]*x4), matrix[1][4]-(matrix[1][0]*x1+matrix[1][1]*x2+matrix[1][2]*x3+matrix[1][3]*x4) , matrix[2][4]-(matrix[2][0]*x1+matrix[2][1]*x2+matrix[2][2]*x3+matrix[2][3]*x4) , matrix[3][4]-(matrix[3][0]*x1+matrix[3][1]*x2+matrix[3][2]*x3+matrix[3][3]*x4)) << "\n\n";
	}

	cout << "\n";
	cout << "X1: " << x1 << endl;
	cout << "X2: " << x2 << endl;
	cout << "X3: " << x3 << endl;
	cout << "X4: " << x4 << endl;


	return 0;
}