#include <iostream>
#include <time.h>
#include "staticLinkedList.h"

using namespace std;

int main()
{
	staticLinkedList<int> list;
	int head, q, t;
	char choice = '9';
	int data;
	
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "----------------The simulation of the dynamic memory allocation---------------" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Get a space in the memory (simulate p = new Node)" << endl;
	head = list.getHeadNode();
	q = head;
	cout << ".......Successful access to space" << endl;
	cout << endl;
	cout << "basic operations : " << endl;
	cout << "insert(default)--------------1" << endl;
	cout << "insert(position)-------------2" << endl;
	cout << "delete-----------------------3" << endl;
	cout << "print list-------------------4" << endl;
	cout << "print memory-----------------5" << endl;
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
				q = list.insert(data, q);
				break;
			case '2':
				cout << "the data you want inserted: ";
				cin >> data;
				cout << "the position you want inserted: ";
				cin >> t;
				list.insertWithPosition(data, t);
				break;
			case '3':
				cout << "the data you want deleted: " ;
				cin >> data;
				list.deleteData(data);
				break;
			case '4':
				cout << "the list: ";
				list.print();
				break;
			case '5':
				cout << "the memory: ";
				cout << endl;
				list.printMemory();
				break;
			default:
				break;
		}
	}while(choice != '0'); 
	
	
	
	/*p = list.getNode();
	q = p;
	q = list.insert(12, q);
	q = list.insert(23, q);
	list.insert(34, q);
	
	list.deleteNode(2);
	
	list.print();*/

	return 0;
}