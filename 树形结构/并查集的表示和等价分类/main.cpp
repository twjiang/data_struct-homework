#include <iostream>
#include "unionFind.h"

using namespace std;

int main(int argc, char const *argv[])
{
	unionFind<int> myUF;
	int data = -1;
	myUF.readData();
	myUF.inputRalation();

	while(data != 0)
	{
		cout << "where is: ";
		cin >> data;
		cout << "it belong to data: ";
		cout << myUF.getData(myUF.find(data));
		cout << endl;
	}
	return 0;
}