#include <iostream>
#include "AVLtree.h"

void InsertFunction();
void DeleteFunction();
void FindFunction();
void DisplayFunction();

AVLtree<int> myAVLtree;
AVLtree<int>::Node *root = new AVLtree<int>::Node;
int main()
{
	char choice = '9';
	cout << endl;
	cout << endl;
	cout << "--------------Welcome to The World of AVL---------------" << endl;
	cout << endl;
	cout << "now, let's create an AVLtree!" << endl;
	cout << "please input the a series of data (end with 0):" << endl;
	root = myAVLtree.create();
	cout << "at last AVL   : ";
	myAVLtree.print(root);
	cout << endl;
	cout <<"-----------------------------------------------------";
	cout << endl;
	cout << "now, you already create an AVLtree :" << endl;
	while(choice != '0')
	{
		cout << "------------------------------------" << endl;
		cout << "insert data :         1" << endl;
		cout << "delete data :         2" << endl;
		cout << "find data   :         3" << endl;
		cout << "display the AVLtree:  4" << endl;
		cout << "quit        :         0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				InsertFunction();
				break;
			case '2':
				DeleteFunction();
				break;
			case '3':
				FindFunction();
				break;
			case '4':
				DisplayFunction();
				break;
			default:
				break;			
		}
	}
}

void InsertFunction()
{
	int data;
	cout << "please input the data you want ro insert: ";
	cin >> data;
	myAVLtree.insert(data, root);
	cout << "after insert: ";
	myAVLtree.print(root);
	cout << endl;
	return;
}
void DeleteFunction()
{
	int data;
	cout << "please input the data you want ro delete: ";
	cin >> data;
	myAVLtree.mydelete(data, root);
	cout << "after delete: ";
	myAVLtree.print(root);
	cout << endl;
	return;
}
void FindFunction()
{
	int data;
	cout << "please input the data you want ro find: ";
	cin >> data;
	myAVLtree.find(data, root);
	return;		
}	
void DisplayFunction()
{
	myAVLtree.print(root);
	cout << endl;
	return;
}