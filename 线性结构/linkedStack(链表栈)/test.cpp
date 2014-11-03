#include <iostream>
#include "linkedStack.h"

using namespace std;

int main()
{
	linkedStack<int> stack;
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