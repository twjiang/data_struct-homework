#include <iostream>
#include "sequenceStack.h"

using namespace std;

int main()
{
	sequenceStack<int> stack;
	int data;
	cin >> data;
	while(data != 0)
	{
		stack.push(data);
		cin >> data;
	}

	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
	cout << stack.getTop() << endl;

	return 0;
}