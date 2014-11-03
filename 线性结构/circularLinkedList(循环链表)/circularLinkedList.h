#ifndef circularLinkedList_H_INCLUDED
#define circularLinkedList_H_INCLUDED
#include <iostream>
using namespace std;

template <typename ElemType>
class circularLinkedList
{
private:
	struct Node
	{
		ElemType data;
		Node *next;
	};
	Node *tail;

public:
	circularLinkedList()
	{
		tail = NULL;
	}

	~circularLinkedList()
	{

	}

	void leftInsert(ElemType x)
	{
		Node *p = new Node;
		p->data = x;
		if(tail == NULL)
		{
			p->next = p;
			tail = p;
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
		}
	}

	void rightInsert(ElemType x)
	{
		Node *p = new Node;
		p->data = x;
		if(tail == NULL)
		{
			p->next = p;
			tail = p;
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
			tail = p;
		}
	}

	void printList()
	{
		if(tail != NULL)
		{
			Node *p = tail->next;
			do
			{
				cout << p->data << " ";
				p = p->next;
			}while(p != tail->next);
			cout << endl;
		}
	}

	void Josephus(int n, int m)
	{
		Node *p = tail;
		Node *pre = NULL;
		for (int i = 0; i < n-1; i++) 
		{ 
			for (int j = 0; j < m-1; j++)
			{  
				pre = p; 
				p = p->next; 
			}
			cout << p->data << endl;
			pre->next = p->next; 
			p=pre->next;
		}
	}
};

#endif 