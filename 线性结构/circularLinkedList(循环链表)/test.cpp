#include <iostream>
#include "circularLinkedList.h"

using namespace std;

int main()
{
	circularLinkedList<int> list;
	int data;
	cin >> data;
	while(data != 0)
	{
		list.leftInsert(data);
		list.rightInsert(data);
		cin >> data;
	}

	list.printList();

	return 0;
}