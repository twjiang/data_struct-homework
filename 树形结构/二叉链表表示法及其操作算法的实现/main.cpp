#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	tree<char> my_tree;
	char choice = '9';
	int data;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "-----------------The establishment of the tree, and operations----------------" << endl;
	cout << endl;
	cout << "basic operations : " << endl;
	cout << "create a tree -------------------1" << endl;
	cout << "preorder traversal---------------2" << endl;
	cout << "postorder traversale-------------3" << endl;
	cout << "level-order traversal------------4" << endl;
	cout << "quit-----------------------------0" << endl;
	do
	{
		cout << "choose the basic operations: ";
		cin >> choice;
		switch(choice)
		{
			case '1':
				int n;
				cout << "how many root : ";
				cin >> n;
				my_tree.create(n);
				break;
			case '2':
				cout << "--------------------------------------" << endl;
				cout << "the preorder traversal:" << endl;
				my_tree.preorder();
				break;
			case '3':
				cout << "--------------------------------------" << endl;
				cout << "the postorder traversale:" << endl;
				my_tree.postorder();
				break;
			case '4':
				cout << "--------------------------------------" << endl;
			    cout << "the level-order traversal:" << endl;
				my_tree.level_order();
				break;
			default:
				break;
		}
	}while(choice != '0');

	return 0;
}