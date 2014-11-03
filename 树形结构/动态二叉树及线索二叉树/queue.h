#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#define maxlength 11
using namespace std;

template<typename Elemtype>
class queue
{
public:
	queue()
	{
		front = maxlength - 1;
		rear = maxlength - 1;
	}
	~queue()
	{

	}

	void makeNull()
	{
		front = maxlength - 1;
		rear = maxlength - 1;
	}

	bool empty()
	{
		if(front == rear)
			return true;
		else
			return false;
	}

	Elemtype getFront()
	{
		if(empty())
		{
			cout << "the queue is empty!" << endl;
			return 0;
		}
		else
		{
			int i = (front + 1) % maxlength;
			return elements[i];
		}
	}

	void enqueue(Elemtype x)
	{
		if((rear + 1) % maxlength == front)
			cout << "the queue is full!" << endl;
		else
		{
			rear = (rear + 1) % maxlength;
			elements[rear] = x;
		}
	}

	void outqueue()
	{
		if(empty())
			cout << "the queue is empty!" << endl;
		else
		{
			front = (front + 1) % maxlength;
		}
	}

	void print()
	{
		if(empty())
			cout << "the queue is empty!" << endl;
		else
		{
			for(int i = (front + 1) % maxlength; i != (rear + 1) % maxlength; )
			{
				cout << elements[i] << " ";
				i = (i + 1) % maxlength;
			}
			cout << endl;	
		}
	}

private:
	int front;
	int rear;
	Elemtype elements[maxlength];
};

#endif