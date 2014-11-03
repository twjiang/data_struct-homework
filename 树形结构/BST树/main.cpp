#include <iostream>
#include "BSTtree.h"

using namespace std;

int main()
{
	BSTtree<int> myBSTtree;
	char choice = '9';
	int data;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "            --------------------BST Tree--------------------" << endl;
	cout << endl;
	cout << "basic operations : " << endl;
	cout << "insert-----------------------1" << endl;
	cout << "delete-----------------------2" << endl;
	cout << "print tree-------------------3" << endl;
	cout << "quit-------------------------0" << endl;
	do
	{
		cout << "choose the basic operations: ";
		cin >> choice;
		switch(choice)
		{
			case '1':
				cout << "the data you want inserted: ";
				cin >> data;
				myBSTtree.insert(data);
				break;
			case '2':
				cout << "the data you want deleted: " ;
				cin >> data;
				myBSTtree.deleteData(data);
				break;
			case '3':
				cout << "the BSTtree: ";
				myBSTtree.printTree();
				cout << endl;
			default:
				break;
		}
	}while(choice != '0'); 
	
	return 0;
}