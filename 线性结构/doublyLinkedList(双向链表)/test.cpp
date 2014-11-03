#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
	doublyLinkedList<int> list;
	int data;
	cin >> data;
	while(data != 0)
	{
		list.insert(data, list.getTail());
		cin >> data;
	}
	list.deleteNode(list.getHead()->next->next->next);
	list.printList();
	return 0;
}