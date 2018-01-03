
#include <iostream>
#include <vector>

using namespace std;
void rowop(vector<vector<double>> & matrix, int a , int b , double k){
	for (unsigned int i=0 ; i<matrix[a].size() ; i++){
		matrix[a][i] -= matrix[b][i]*k;
	}
}

int main(){

	
	vector<vector<double> > matrix(4);
	for ( int i = 0 ; i < 4 ; i++ )
		matrix[i].resize(5);
	matrix = {{ 95 , 3   , 1  , 2  , 101},
			  { 4  , 100 , 10 , 5  , 119},
			  { 3  , 9   , 55 , 5  , 72 },
			  { 10 , 2   , 4  , 80 , 96 }};
	for (unsigned int i=0 ; i<matrix.size() ; i++){
		rowop(matrix,i,i,1-1/matrix[i][i]);
		for (unsigned int j=0 ; j<matrix.size() ; j++){
			if (i != j){
				rowop(matrix,j,i,matrix[j][i]);
			}
		}
	}

	for (unsigned int i=0 ; i<matrix.size() ; i++){
		for (unsigned int j=0 ; j<matrix[i].size() ; j++){
			cout << matrix[i][j] << "  ";
		}
		cout << "\n\n";
	}




	return 0;
}
