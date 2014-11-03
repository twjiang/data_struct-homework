#include <iostream>
#include "forest.h"

using namespace std;

int main(int argc, char const *argv[])
{
	forest<char> my_forest;

	char choice = '9';
	int data;
	int num;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "---------------The establishment of the forest, and transformation------------" << endl;
	cout << endl;
	cout << "basic operations : " << endl;
	cout << "create a tree in the forest----------------1" << endl;
	cout << "print a tree-------------------------------2" << endl;
	cout << "transformation a tree to bTree-------------3" << endl;
	cout << "transformation the forest to bTree---------4" << endl;
	cout << "quit the program---------------------------0" << endl;
	do
	{
		cout << "choose the basic operations: ";
		cin >> choice;
		switch(choice)
		{
			case '1':
				my_forest.create_tree();
				break;
			case '2':
				cout << "please input the number of the tree you want print:";
				cin >> num;
				my_forest.print_tree(num);
				break;
			case '3':
				cout << "please input the number of the tree you want transformate:";
				cin >> num;
				my_forest.tree_to_bTree(num);
				break;
			case '4':
				my_forest.forest_to_bTree();
				break;
			default:
				break;
		}
	}while(choice != '0');

	return 0;
}