#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

#include "stack.h"
#include "queue.h"

using namespace std;

template<typename Elemtype>
class BTree
{
public:
	struct Node
	{
		Elemtype data;
		Node* lchild;
		Node* rchild;
	};

	BTree()
	{
		root = new Node;
		root->lchild = NULL;
		root->rchild = NULL;
		j = 0;
	}
	~BTree()
	{
		delete root;
	}

	bool isEmpty()
	{
		if(root->lchild == NULL && root->rchild == NULL)
			return true;
		else
			return false;
	}

	Node* getRoot()
	{
		return root;
	}
	
	Node* getLchild(Node* p)
	{
		if(p->lchild == NULL)
		{
			cout << "no lchild." << endl;
			return NULL;
		}
		else 
			return p->lchild;
	}
	
	Node* getRchild(Node* p)
	{
		if(p->rchild == NULL)
		{
			cout << "no rchild." << endl;
			return NULL;
		}
		else 
			return p->rchild;
	}
	
	Elemtype getData(Node* p)
	{
		if(p)
			return p->data;
		else
		{
			cout << "no data." << endl;
			return 0;
		}
	}

	Node* createBTree()
	{
		Node* s[100];
		for(int i = 0; i < 100; i++)
        {
            s[i] = NULL;
        }
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
        	s[i] = p;
        	if(i == 1)
        		root = p;
        	else
        	{
        		j = i / 2;
        		if(i % 2 == 0)
        			s[j]->lchild = p;
        		else
        			s[j]->rchild = p;
        	}
        	cin >> i >> _data;
        }
        return root;
	}

	/*void createBTree(Node* p)
	{
		Elemtype ch;
		p = new Node;
		cin >> ch;
		if(ch =='#')
			p = NULL;
		else
		{
			p->data = ch;
			createBTree(p->lchild);
			createBTree(p->rchild);
		}
	}*/

	void inorder(Node* p)
	{
		if(p != NULL)
		{
			inorder(p->lchild);
			cout << p->data << " ";
			inorder(p->rchild);
		}
	}

	void inorder()
	{
		Node* p;
		p = root;
		stack<Node*> _stack;
		while(p != NULL || !_stack.empty())
		{
			while(p != NULL)
			{
				_stack.push(p);
				p = p->lchild;
			}
			if(!_stack.empty())
			{
				p = _stack.top();
				_stack.pop();
				cout << p->data <<" ";
				p = p->rchild;
			}
		}
	}

	void preorder(Node* p)
	{
		if(p != NULL)
		{
			cout << p->data << " ";
			preorder(p->lchild);
			preorder(p->rchild);
		}
	}

	void preorder()
	{
		Node* p;
		p = root;
		stack<Node*> _stack;
		while(p != NULL || !_stack.empty())
		{
			while(p != NULL)
			{
				cout << p->data <<" ";
				_stack.push(p);
				p = p->lchild;
			}
			if(!_stack.empty())
			{
				p = _stack.top();
				_stack.pop();
				p = p->rchild;
			}
		}

	}

	void postorder(Node* p)
	{
		if(p != NULL)
		{
			postorder(p->lchild);
			postorder(p->rchild);
			cout << p->data << " ";
		}
	}

	void postorder() 
	{  
	    int flag[100];  
	    stack<Node*> _stack;
	    Node* p = root;  
	    for(int i = 0; i<100; i++)
	    {
	    	flag[i] == 0;
	    } 
	    while(p != NULL || !_stack.empty())  
	    {
	    	while(p != NULL)
	    	{
	    	    _stack.push(p);  
		        flag[_stack.size()] = 1;  
		        p = p->lchild;
	    	}
	    	while(!_stack.empty() && flag[_stack.size()] == 2)
	    	{
	    		p = _stack.top();  
		        cout << p->data << " "; 
		        _stack.pop();
		        if(_stack.empty())
		        {
		        	return ;
		        }
	    	}
  			if(!_stack.empty())
  			{
  				flag[_stack.size()] = 2; 
  				p = _stack.top();
	            p = p->rchild;
  			}
	    }                                                                                                                                    
	} 


	void leverorder()
	{
		Node* q;
		q = root;
		queue<Node*> _queue;
		_queue.enqueue(q);
		while(!_queue.empty())
		{
			q = _queue.getFront();
			_queue.outqueue();
			cout << q->data << " ";
			if(q->lchild!=NULL)
				_queue.enqueue(q->lchild);
			if(q->rchild!=NULL)
				_queue.enqueue(q->rchild);
		}
	}
	
	void printBTree(Node* p)
	{
		if(p!=NULL)
		{
			cout<<p->data;
			a[++j]=p->data;
			if(p->lchild!=NULL||p->rchild!=NULL)
			{
				cout<<'(';
				a[++j]='(';
				printBTree(p->lchild);
				if(p->rchild!=NULL)
				{
					cout<<',';
					a[++j]=',';
					printBTree(p->rchild);
				}
				cout<<')';
				a[++j]=')';
			}
		}
	}

private:
	Node* root;
	char a[100];
	int j;

};

#endif
