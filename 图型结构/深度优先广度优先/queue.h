#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;

template<typename ElemType>
class queue
{
private:
	struct Node
	{
		ElemType data;
		Node* next;
	};
	Node* front;
	Node* rear;
public:
	queue()
	{
		front = new Node;
		front->next = NULL;
		rear = front;
	}
	~queue()
	{
		delete front;
		delete rear;
	}

	bool Empty()
	{
		return front == rear;
	}

	ElemType Front()
	{
		if(Empty())
		{
			cout << "the queue is empty!" << endl;
			return 0;
		}
		return front->next->data;
	}

	void EnQueue(ElemType x)
	{
		rear->next = new Node;
		rear->next->data = x;
		rear = rear->next; 
		rear->next = NULL;
	}

	void OutQueue()
	{
		if(Empty())
		{
			cout << "the queue is empty!" << endl;
		}
		else
		{
			front = front->next;
		}
	}

	void Print()
	{
		Node* p = front->next;
		while(p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

#endif