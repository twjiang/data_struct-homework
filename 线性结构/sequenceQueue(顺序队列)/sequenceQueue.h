#ifndef sequenceQueue_H_INCLUDED
#define sequenceQueue_H_INCLUDED

#include <iostream>
#define maxlength 100

using namespace std;

template<typename Elemtype>
class sequenceQueue
{
private:
	int front;
	int rear;
	Elemtype elements[maxlength];
	
public:
	sequenceQueue()
	{
		front = maxlength - 1;
		rear = maxlength - 1;
	}
	~sequenceQueue()
	{

	}

	void makeNull()
	{
		front = maxlength - 1;
		rear = maxlength - 1;
	}
	bool isEmpty()
	{
		if(front == rear)
			return true;
		else
			return false;
	}
	Elemtype getFront()
	{
		if(isEmpty())
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
	void enQueue(Elemtype x)
	{
		if((rear + 1) % maxlength == front)
			cout << "the queue is full!" << endl;
		else
		{
			rear = (rear + 1) % maxlength;
			elements[rear] = x;
		}
	}

	void outQueue()
	{
		if(isEmpty())
			cout << "the queue is empty!" << endl;
		else
		{
			front = (front + 1) % maxlength;
		}
	}

	void print()
	{
		if(isEmpty())
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
};

#endif