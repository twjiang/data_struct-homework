#include <iostream>
#include "tripleMatrix.h"

using namespace std;

int main()
{
	tripleMatrix<int> myMatrix;
	int m, n, t;
	
	cout << "Please enter the sparse matrix on the number of rows, columns, the number of nonzero elements: ";
	cin >> m >> n >> t;
	myMatrix.createMatrix(m, n, t);
	cout << endl;
	myMatrix.transpose();
	return 0;
}


