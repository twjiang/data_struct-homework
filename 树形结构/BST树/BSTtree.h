#ifndef BSTtree_H_INCLUDED
#define BSTtree_H_INCLUDED

#include <iostream>

using namespace std;

template <typename ElemType>
class BSTtree
{
private:
	struct Node
	{
		ElemType data;
		Node *lchild;
		Node *rchild;
	};
	Node *root;
public:
	BSTtree()
	{
        root = NULL;	
	}
	
	void insert(ElemType _data)
	{
		if(root == NULL)
		{
			root = new Node;
			root->data = _data;
			root->lchild = NULL;
			root->rchild = NULL;
			
		}
		else if(!findData(_data))
		{
			
			if(_data < root->data)
			{
				if(!root->lchild)
				{
					root->lchild = new Node;
					root->lchild->data = _data;
					root->lchild->lchild = NULL;
					root->lchild->rchild = NULL;
				}
				else
					insert(root->lchild, _data);
			}
			else 
			{
				if(!root->rchild)
				{
					root->rchild = new Node;
					root->rchild->data = _data;
					root->rchild->lchild = NULL;
					root->rchild->rchild = NULL;
				}
				else
					insert(root->rchild, _data);
			}
		}
	}
	
	void insert(Node* position, ElemType _data)
	{
		if(_data < position->data)
		{
			if(!position->lchild)
			{
				position->lchild = new Node;
				position->lchild->data = _data;
				position->lchild->lchild = NULL;
				position->lchild->rchild = NULL;
			}
			else
				insert(position->lchild, _data);
		}
		else
		{
			if(!position->rchild)
			{
				position->rchild = new Node;
				position->rchild->data = _data;
				position->rchild->lchild = NULL;
				position->rchild->rchild = NULL;
			}
			else
				insert(position->rchild, _data);
		}
	}
	
	void deleteData(ElemType data)
	{
		if(root != NULL)
		{
			if(data < root->data)
				deleteData(data, root->lchild);
			else if(data > root->data)
				deleteData(data, root->rchild);
			else
			{
				if(root->rchild == NULL)
					root = root->lchild;
				else if(root->lchild == NULL)
					root = root->rchild;
				else
					root->data = deleteMin(root->rchild);
			}
		}
	}
	
	void deleteData(ElemType data, Node *position)
	{
		if(position != NULL)
		{
			if(data < position->data)
				deleteData(data, position->lchild);
			else if(data > position->data)
				deleteData(data, position->rchild);
			else
			{
				if(position->rchild == NULL)
					position = position->lchild;
				else if(position->lchild == NULL)
					position = position->rchild;
				else
					position->data = deleteMin(position->rchild);
			}
		}
	}
	
	ElemType deleteMin(Node *position)
	{
		ElemType tmp;
		Node *q;
		if(position->lchild == NULL)
		{
			q = position;
			tmp = position->data;
			position = position->rchild;
			delete q;
			return tmp;
		}
		else
			return deleteMin(position->lchild);
	}
	
	Node* findData(ElemType _data)
	{
		if(root == NULL)
			return NULL;
		else if(_data < root->data)
			return findData(root->lchild, _data);
		else if(_data > root->data)
			return findData(root->rchild, _data);
		else
			return root;
	}
	
	Node* findData(Node *position, ElemType _data)
	{
		if(position == NULL)
			return NULL;
		else if(_data < position->data)
			return findData(position->lchild, _data);
		else if(_data > position->data)
			return findData(position->rchild, _data);
		else
			return position;
	}
	
	void printTree()
	{
		if(root != NULL)
		{
			cout << root->data;
			if(root->lchild != NULL || root->rchild != NULL)
			{
				cout << '(';
				print(root->lchild);
				if(root->rchild != NULL)
				{
					cout << ',';
					print(root->rchild);
				}
				cout << ')';
			}
		}
	}
	
	void print(Node* p)
	{
		if(p != NULL)
		{
			cout << p->data;
			if(p->lchild != NULL || p->rchild != NULL)
			{
				cout << '(';
				print(p->lchild);
				if(p->rchild != NULL)
				{
					cout << ',';
					print(p->rchild);
				}
				cout << ')';
			}
		}
	}
};

#endif