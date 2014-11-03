#ifndef singlyLinkedList_H_INCLUDED
#define singlyLinkedList_H_INCLUDED
#include <iostream>
using namespace std;

template <typename ElemType>
class singlyLinkedList
{
private:
	struct Node
	{
		ElemType data;
		Node* next;
	};
	Node* _head;

public:
	singlyLinkedList()
	{
		_head = new Node;
		_head->next = NULL;
	}

	~singlyLinkedList()
	{
		delete _head;
	}

	Node* head()
	{
		return _head;
	}

	Node* tail()
	{
		Node* p = _head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		return p;
	}

	void insert(ElemType x, Node* p)
	{
		Node* q;
		q = new Node;
		q->data = x;
		q->next = p->next;
		p->next = q;
		cout << "insert success." << endl;
	}

	void deleteNode(ElemType x)
	{
		Node *p = locate(x);
		Node* q = _head;
		Node* t;
		while(q != p && q != NULL)
		{
			t = q;
			q = q->next;
		}
		if(q == NULL)
			cout << "there is no such data!" << endl;
		else
		{
			t->next = q->next;
			delete q;
			cout << "delete success." << endl;
		}
	}

	Node* locate(ElemType x)
	{
		Node* q = _head;
		while(q->next != NULL)
		{
			if(q->next->data == x)
				return q->next;
			else
				q = q->next;
		}
		return _head;
	}

	ElemType retrieve(Node* p)
	{
		return p->data;
	}

	Node* previous(Node* p)
	{
		Node* q;
		if(p == _head)
		{
			cout << "no Previous" << endl;
			return _head;
		}
		else
		{
			q = _head;
			while(q->next != p && q->next != NULL)
				q = q->next;
			return q;
		}
	}

	Node* next(Node* p)
	{
		Node* q;
		q = p->next;
		return q;
	}

	Node* makeNull()
	{
		_head = new Node;
		_head->next = NULL;
		return _head;
	}

	void print()
	{
		Node* q = _head->next;
		while(q != NULL)
		{
			cout << q->data << " ";
			q = q->next;
		}
		cout << endl;
	}
};

#endif 