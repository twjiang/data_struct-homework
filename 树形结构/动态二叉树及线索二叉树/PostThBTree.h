#ifndef POSTTHBTREE_H_INCLUDED
#define POSTTHBTREE_H_INCLUDED

#include <iostream>
#include <vector>

#include "stack.h"
#include "queue.h"

using namespace std;


template<typename Elemtype>
class PostThBTree
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

	PostThBTree()
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
	~PostThBTree()
	{
		delete root;
	}

	Node* createPostThBTree()
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
	    postOrderTh(root);
	    return root;
	}

	void postOrderTh(Node* p)
	{
		if(p)
		{
			if(p->ltag == true)
			{
				postOrderTh(p->lchild);
			}
			if(p->rtag == true)
			{
				postOrderTh(p->rchild);
			}
			if(pre)
			{
				if(pre->rtag == false)
					pre->rchild = p;
				if(p->ltag == false)
					p->lchild = pre;
			}
			pre = p;
		}
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
		else if(i%2 != 0)
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
				while(p->ltag == false && p->rtag == true)
				{
					p = p->rchild;
				}
				return p;
			}
		}
	}

	void thPostOrder()
	{
		Node* temp;
		temp = root;
		while(temp->ltag == true)
		{
			temp = temp->lchild;
			while(temp->ltag == false && temp->rtag == true)
			{
				temp = temp->rchild;
			}
		}
		cout << temp->data << " ";
		do
		{
			temp = postNext(temp);
			cout << temp->data << " ";
		}while(postNext(temp) != NULL);
	}

private:
	Node* root;
	Node* s[100];
	Node* pre;
};

#endif
