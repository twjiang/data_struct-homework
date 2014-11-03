#ifndef INTHBTREE_H_INCLUDED
#define INTHBTREE_H_INCLUDED

#include <iostream>
#include <vector>

#include "stack.h"
#include "queue.h"

using namespace std;


template<typename Elemtype>
class InThBTree
{
public:
	struct Node
	{
		Elemtype data;
		Node* lchild;
		Node* rchild;
		bool ltag;
		bool rtag;
	};

	InThBTree()
	{
		root = new Node;
		root->lchild = NULL;
		root->rchild = NULL;
		
		pre = NULL;
		
		for(int i = 0; i < 100; i++)
		{
		    s[i] = NULL;
		}
	}
	~InThBTree()
	{
		delete root;
	}

	Node* createInThBTree()
	{
		int i, j;
		Elemtype _data;
		Node* p;
	    cin >> i >> _data;
	    while(i != 0)
	    {
	    	p = new Node;
	    	p->data = _data;
	    	p->lchild = NULL;
	    	p->rchild = NULL;
	    	p->ltag = false;
	    	p->rtag = false;
	    	s[i] = p;
	    	if(i == 1)
	    		root = p;
	    		
	    	else
	    	{
	    		j = i / 2;
	    		if(i % 2 == 0)
	    		{
	    			s[j]->lchild = p;
	    			s[j]->ltag = true;
	    		}
	    		else
	    		{
	    			s[j]->rchild = p;
	    			s[j]->rtag = true;
	    		}
	    	}
	    	cin >> i >> _data;
	    }
	    inOrderTh(root);
	    return root;
	}

	void inOrderTh(Node* p)
	{
		if(p)
		{
			inOrderTh(p->lchild);
			if(pre)
			{
				
				if(pre->rtag == false)
					pre->rchild = p;
				if(p->ltag == false)
					p->lchild = pre;
			}
			pre = p;
			inOrderTh(p->rchild);
		}
	}

	Node* inNext(Node* p)
	{
		Node* q;
		q = p->rchild;
		if(p->rtag == true)
		{
			while(q->ltag == true)
			{
				q = q->lchild;
			}
		}
		return q;
	}

	Node* preNext(Node* p)
	{
		Node* q;
		if(p->ltag == true)
		{
			q = p->lchild;
		}
		else
		{
			q = p;
			while(q->rtag == false)
			{
				q = q->rchild;
			}
			q = q->rchild;
		}
		return q;
	}

	Node* postNext(Node* p)
	{
		int i = 1;
		while(s[i] != p)
		{
			i++;
		}
		if(i == 1)
		{
			return NULL;
		}
		else if(i/2 != 0)
		{
			return s[i/2];
		}
		else
		{
			if(s[i+1] == NULL)
			{
				return s[i/2];
			}
			else
			{
				p = s[i+1];
				while(p->ltag == true)
				{
					p = p->lchild;
				}
				return p;
			}
		}
	}

	void thInOrder()
	{
		Node* temp;
		int i = 1;
		while(s[i]->lchild != NULL)
		{
			i++;
		}
		temp = s[i];
		cout << temp->data << " ";
		do
		{
			temp = inNext(temp);
			cout << temp->data << " ";
		}while(temp->rchild != NULL);
	}

private:
	Node* root;
	Node* s[100];
	Node* pre;
};

#endif
