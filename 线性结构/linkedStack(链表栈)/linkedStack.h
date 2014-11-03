#ifndef linkedStack_H_INCLUDED
#define linkedStack_H_INCLUDED

#include <iostream>

using namespace std;

template<typename Elemtype>
class linkedStack
{
private:
	struct Node 
	{
		Elemtype data;
		Node *next;
	};
	Node *head;
	
public:
	linkedStack()
	{
		head = new Node;
		head->next = NULL;
	}
	~linkedStack()
	{

	}

	void push(Elemtype x)
	{
		Node *p = new Node;
		p->data = x;
		p->next = head->next;
		head->next = p;
	}

	void pop()
	{
		if(head->next != NULL)
		{
			Node *p = head->next;
			head->next = p->next;
			delete p;
		}
	}

	bool empty()
	{
		if(head->next != NULL)
			return false;
		else
			return true;
	}

	void makeNull()
	{
		head->next = NULL;
	}

	Elemtype getTop()
	{
		if(head->next != NULL)
		{
			Node *p = head->next;
			return p->data;
		}
	}

	void print()
	{
		Node *p = head->next;
		while(p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

#endif