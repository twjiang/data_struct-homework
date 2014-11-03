#ifndef sequenceStack_H_INCLUDED
#define sequenceStack_H_INCLUDED

#include <iostream>
#define MAX 100

using namespace std;

template<typename Elemtype>
class sequenceStack
{
private:
	Elemtype elements[MAX];
	int top;
public:
	sequenceStack()
	{
		top = 0;
	}
	~sequenceStack()
	{

	}

	void push(Elemtype x)
	{
		if(top == MAX - 1)
		{
			cout << "the stack is full!" << endl;
		}
		else
		{
			top += 1;
		    elements[top] = x;	
		}
	}

	void pop()
	{
		if(top == 0)
		{
			cout << "the stack is empty!" << endl;
		}
		else
		{
			top -= 1;
		}
	}

	bool empty()
	{
		return !top;
	}

	void makeNull()
	{
		top = 0;
	}

	Elemtype getTop()
	{
		if(empty())
		{
			cout << "the stack is empty!" << endl;
			return 0;
		}
		return elements[top];
	}

	void print()
	{
		if(empty())
		{
			cout << endl;
		}
		else
		{
			for(int i = 1; i <= top; i++)
			{
				cout << elements[i] << " ";
			}
			cout << endl;
		}
	}
};

#endif