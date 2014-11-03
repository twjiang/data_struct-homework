#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial _poly1;
	Polynomial _poly2;
	int n1, n2;
	int coef, exp;
	
	cout << "Please enter number of items of the first polynomial: ";
	cin >> n1;
	cout << "Please enter each item of the first polynomial: " << endl;
	while(n1--)
	{
		cin >> coef >> exp;
		_poly1.Insert(coef, exp);
	}
	
	cout <<"Please enter number of items of the second polynomial: ";
	cin >> n2;
	cout << "Please enter each item of the second polynomial: " << endl;
	while(n2--)
	{
		cin >> coef >> exp;
		_poly2.Insert(coef, exp);
	}
	_poly1.PolyAdd(_poly2);
	
	cout << "the results of two polynomial addition: ";
	_poly1.Print();
	return 0;
}