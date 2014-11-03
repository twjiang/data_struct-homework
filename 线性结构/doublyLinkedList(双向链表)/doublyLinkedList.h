#ifndef doublyLinkedList_H_INCLUDED
#define doublyLinkedList_H_INCLUDED
#include <iostream>
using namespace std;

template <typename ElemType>
class doublyLinkedList
{
private:
	struct Node
	{
		ElemType data;
		Node *next;
		Node *prior;
	};
	Node *head;

public:
	doublyLinkedList()
	{
		head = new Node;
		head->next = NULL;
		head->prior = NULL;
	}

	~doublyLinkedList()
	{
		delete head;
	}

	Node *getHead()
	{
		return head;
	}

	Node *getTail()
	{
		Node *p = head;
		while(p->next != NULL)
			p = p->next;
		return p;
	}

	void insert(ElemType x, Node *p)
	{
		Node *s = new Node;
		s->data = x;
		s->prior = p;
		s->next = p->next;
		if(p->next != NULL)
			p->next->prior = s;
		p->next = s;
	}

	void deleteNode(Node *p)
	{
		if(p != head)
		{
			p->prior->next = p->next;
			if(p->next != NULL)
				p->next->prior = p->prior;
			delete p;
		}
	}

	void printList()
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