#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#define MAX 100

using namespace std;

template<typename Elemtype>
class stack             
{
private:
	Elemtype elements[MAX];
	int _top;
public:
	stack()
	{
		_top = 0;
	}
	~stack()
	{

	}

	void push(Elemtype x)
	{
		if(_top == MAX - 1)
		{
			cout << "the stack is full!" << endl;
		}
		else
		{
			_top += 1;
		    elements[_top] = x;	
		}
	}

	int size()
	{
		return _top;
	}

	void pop()
	{
		if(_top == 0)
		{
			cout << "the stack is empty!" << endl;
		}
		else
		{
			_top -= 1;
		}
	}

	bool empty()
	{
		return !_top;
	}

	void makeNull()
	{
		_top = 0;
	}

	Elemtype top()
	{
		if(empty())
		{
			cout << "the stack is empty!" << endl;
			return 0;
		}
		return elements[_top];
	}

	void print()
	{
		if(empty())
		{
			cout << endl;
		}
		else
		{
			for(int i = 1; i <= _top; i++)
			{
				cout << elements[i] << " ";
			}
			cout << endl;
		}
	}
};

#endif