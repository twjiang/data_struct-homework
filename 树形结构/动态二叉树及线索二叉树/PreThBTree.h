#ifndef PRETHBTREE_H_INCLUDED
#define PRETHBTREE_H_INCLUDED

#include <iostream>

#include "stack.h"
#include "queue.h"

using namespace std;


template<typename Elemtype>
class PreThBTree
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
	PreThBTree()
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
	~PreThBTree()
	{

	}

	Node* createPreThBTree()
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
	    preOrderTh(root);
	    return root;
	}

	void preOrderTh(Node* p)
	{
		if(p)
		{
			if(pre)
			{
				if(pre->rtag == false)
					pre->rchild = p;
				if(p->ltag == false)
					p->lchild = pre;
			}
			pre = p;

			if(p->ltag == true)
			{
				preOrderTh(p->lchild);			
			}
			if(p->rtag == true)
			{
				preOrderTh(p->rchild);
			}			
		}
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
			q = p->rchild;
		}
		return q;
	}
	
	void thPreOrder()
	{
		Node* temp;
		temp = root;
		cout << temp->data << " ";
		do
		{
			temp = preNext(temp);
			cout << temp->data << " ";
		}while(temp->rchild != NULL);
	}

private:
	Node* root;
	Node* s[100];
	Node* pre;
};

#endif