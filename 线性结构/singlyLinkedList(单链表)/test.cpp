#include <iostream>
#include <time.h>
#include "singlyLinkedList.h"

using namespace std;

int main()
{
	singlyLinkedList<int> list;
	char choice = '9';
	int data;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "--------------------the program of singly linked list test--------------------" << endl;
	cout << endl;
	cout << "basic operations : " << endl;
	cout << "insert-----------------------1" << endl;
	cout << "delete-----------------------2" << endl;
	cout << "print list-------------------3" << endl;
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
				list.insert(data, list.tail());
				break;
			case '2':
				cout << "the data you want deleted: " ;
				cin >> data;
				list.deleteNode(data);
				break;
			case '3':
				cout << "the list: ";
				list.print();
			default:
				break;
		}
	}while(choice != '0'); 

	return 0;
}