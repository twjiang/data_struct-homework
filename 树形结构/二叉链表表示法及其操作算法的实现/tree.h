#ifndef tree_H_INCLUDED
#define tree_H_INCLUDED
#include <iostream>
#include <string>
#include "linkedQueue.h"

using namespace std;

template <typename ElemType>
class tree
{
private:
	struct Node
	{
		ElemType data;
		Node *first_child;
		Node *sibling;
	};
	Node *tree_root;
	linkedQueue<Node*> child_Temp_Queue;
	linkedQueue<Node*> child_Queue;
	string child_string;
public:
	tree()
	{
		tree_root = NULL;
	}
	~tree()
	{

	}

	void create(int root_num)
	{
		Node *p;
		cout << "please enter the tree root node: ";
		tree_root = new Node;
		tree_root->first_child = NULL;
		tree_root->sibling = NULL;
		cin >> tree_root->data;

		cout << "please enter the child of the tree root node: ";
		cin >> child_string;
		tree_root->first_child = new Node;
		tree_root->first_child->data = child_string[0];
		tree_root->first_child->first_child = NULL;
		tree_root->first_child->sibling = NULL;

		int n = child_string.length();
		n--;

		p = tree_root->first_child;
		child_Temp_Queue.enQueue(p);
		child_Queue.enQueue(p);
		int i = 1;
		while(n--)
		{
			p->sibling = new Node;
			p = p->sibling;
			p->data = child_string[i++];
			p->first_child = NULL;
			p->sibling = NULL;
			child_Temp_Queue.enQueue(p);
			child_Queue.enQueue(p);
		}

		int m = root_num;
		m--;
		while(m--)
		{
			create();
		}
		child_Temp_Queue.makeNull();
	}

	void create()
	{
		ElemType data;
		cout << "please enter the root node: ";
		cin >> data;
		while(child_Temp_Queue.getFront()->data != data)
		{
			child_Temp_Queue.outQueue();
		}
		Node *p = child_Temp_Queue.getFront();
		child_Temp_Queue.outQueue();

		cout << "please enter the child of the root node: ";
		cin >> child_string;
		p->first_child = new Node;
		p->first_child->data = child_string[0];
		p->first_child->first_child = NULL;
		p->first_child->sibling = NULL;

		int n = child_string.length();
		n--;

		p = p->first_child;
		child_Temp_Queue.enQueue(p);
		child_Queue.enQueue(p);
		int i = 1;
		while(n--)
		{
			p->sibling = new Node;
			p = p->sibling;
			p->data = child_string[i++];
			p->first_child = NULL;
			p->sibling = NULL;
			child_Temp_Queue.enQueue(p);
			child_Queue.enQueue(p);
		}
	}

	void preorder()
	{
		cout << tree_root->data << " ";
		Node *q = tree_root->first_child;
		while(q != NULL)
		{
			preorder(q);
			q = q->sibling;
		}
		cout << endl;
	}

	void preorder(Node *p)
	{
		cout << p->data << " ";
		Node *q = p->first_child;
		while(q != NULL)
		{
			preorder(q);
			q = q->sibling;
		}
	}

	void postorder()
	{
		Node *q = tree_root->first_child;
		while(q != NULL)
		{
			postorder(q);
			q = q->sibling;
		}
		cout << tree_root->data << endl;
	}

	void postorder(Node *p)
	{
		Node *q = p->first_child;
		while(q != NULL)
		{
			preorder(q);
			q = q->sibling;
		}
		cout << p->data << " ";
	}

	void level_order()
	{
		cout << tree_root->data << ": ";
		Node *p = tree_root->first_child;
		while(p != NULL)
		{
			cout << p->data << " ";
			p = p->sibling;
		}
		cout << endl;

		while(!child_Queue.isEmpty())
		{
			if(child_Queue.getFront()->first_child != NULL)
			{
				cout << child_Queue.getFront()->data << ": ";
				print_subtree(child_Queue.getFront());
				child_Queue.outQueue();
			}
			else
				child_Queue.outQueue();
		}
		
	}

	void print_subtree(Node *p)
	{
		Node *q = p->first_child;
		while(q != NULL)
		{
			cout << q->data << " ";
			q = q->sibling;
		}
		cout << endl;
	}
};

#endif