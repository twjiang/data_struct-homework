#include <iostream>
#include "sequenceQueue.h"

using namespace std;

int main()
{
	sequenceQueue<int> stack;
	int data;
	cin >> data;
	while(data != 0)
	{
		stack.enQueue(data);
		cin >> data;
	}

	stack.print();

	stack.outQueue();
	stack.outQueue();
	stack.print();
	cout << stack.getFront() << endl;

	return 0;
}