#ifndef linkedQueue_H_INCLUDED
#define linkedQueue_H_INCLUDED

#include <iostream>

using namespace std;

template<typename Elemtype>
class linkedQueue
{
private:
	struct Node 
	{
		Elemtype data;
		Node *next;
	};
	Node *front;
	Node *rear;
	
public:
	linkedQueue()
	{
		front = new Node;
		front->next = NULL;
		rear = front;
	}
	~linkedQueue()
	{
		delete front;
		delete rear;
	}


	Elemtype getFront()
	{
		if(!isEmpty())
			return front->next->data;
		else 
		{
			cout << "the queue is empty!" << endl;
			return 0;
		}
	}
	bool isEmpty()
	{
		return front == rear;
	}
	void enQueue(Elemtype x)
	{
		Node *p = new Node;
		p->data = x;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	void outQueue()
	{
		if(isEmpty())
		{
			cout << "the queue is empty!" << endl;
		}
		else
		{
			Node *p = front;
			front = p->next;
			delete p;
		}
	}
	void makeNull()
	{
		front->next = NULL;
		rear = front;
	}
	void print()
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