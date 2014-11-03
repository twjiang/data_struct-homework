#ifndef forest_H_INCLUDED
#define forest_H_INCLUDED
#include <iostream>
#define MAXSIZE 100

using namespace std;

template <typename ElemType>
class forest
{
private:
	ElemType vertex[MAXSIZE][MAXSIZE];
	int n[MAXSIZE], e[MAXSIZE];
	int count;
	
	struct EdgeNode
	{
		int adjvex;
		EdgeNode *next;
	};
	struct VertexNode
	{
		ElemType vertex;
		EdgeNode *firstedge;
	};
	VertexNode verlist[MAXSIZE][MAXSIZE];

	struct Node
	{
		ElemType data;
		Node *lchild;
		Node *rchild;
	};
	Node *root[MAXSIZE];
	Node *node[MAXSIZE][MAXSIZE];
	Node *BTree_root;
public:
	forest()
	{
		count = 0;
	}
	~forest()
	{

	}

	int location(ElemType x) 
	{  
		int k;
		for(k = 0; vertex[count][k]!= x; k++);  
	  	return k;  
	}

	void create_tree()
	{
		cout << "Please enter the number of node and edge:" << endl;
		cin >> n[count] >> e[count];

		cout << "Please enter all the node:" << endl;
		for(int i = 0; i < n[count]; i++)
		{
			cin >> vertex[count][i];
			verlist[count][i].vertex = vertex[count][i];
			verlist[count][i].firstedge = NULL;
		}
		cout << "Please enter the adjacent nodes(parent and it's child):" << endl;
		for(int j = 0; j < e[count]; j++)
		{
			ElemType parent, child;
			cin >> parent >> child;
			EdgeNode *p = new EdgeNode;
			p->adjvex = location(child);
			p->next = NULL;
			if(verlist[count][location(parent)].firstedge == NULL)
				verlist[count][location(parent)].firstedge = p;
			else
			{
				EdgeNode *q = verlist[count][location(parent)].firstedge;
				while(q->next != NULL)
					q = q->next;
				q->next = p;
			}
		}
		count++;
	}

	void print_tree(int num)
	{
		if(num >= count)
				cout << "the tree have not been created." << endl;
		cout << "----------------------------------" << endl;
		for(int i = 0; i < n[num]; i++)
		{
			if(verlist[num][i].firstedge != NULL)
			{
				cout << "parent: " << verlist[num][i].vertex << "----child: ";
				EdgeNode *p = verlist[num][i].firstedge;
				while(p != NULL)
				{
					cout << verlist[num][p->adjvex].vertex << " ";
					p = p->next;
				}
				cout << endl;
			}
		}
		cout << "----------------------------------" << endl;
	}

	void tree_to_bTree(int num)
	{
		for(int i = 0; i < n[num]; i++)
		{
			//cout << "e" << endl;
			node[num][i] = new Node;
			node[num][i]->data = vertex[num][i];
			node[num][i]->lchild = NULL;
			node[num][i]->rchild = NULL;
			//cout << node[num][i]->data << endl;
		}
		for(int i = 0; i < n[num]; i++)
		{
			//cout << "y" << endl;
			if(verlist[num][i].firstedge != NULL)
			{
				//cout << "z" << endl;
				EdgeNode *p = verlist[num][i].firstedge;
				node[num][i]->lchild = node[num][p->adjvex];
				while(p->next != NULL)
				{
					node[num][p->adjvex]->rchild = node[num][p->next->adjvex];
					p = p->next;
				}
			}
		}
		cout << "the bTree is : " << endl;
		print_bTree(node[num][0]);
		cout << endl;
		return;
	}

	void forest_to_bTree()
	{
		for(int i = 0; i < count; i++)
			tree_to_bTree(i);
		for(int i = 0; i < count-1; i++)
		{
			node[i][0]->rchild = node[i+1][0];
		}
		cout << "the forest_bTree is : " << endl;
		print_bTree(node[0][0]);
		cout << endl;
		return;
	}

	void print_bTree(Node* p)
	{
		if(p!=NULL)
		{
			cout << p->data;
			if(p->lchild!=NULL||p->rchild!=NULL)
			{
				cout<<'(';
				print_bTree(p->lchild);
				if(p->rchild!=NULL)
				{
					cout<<',';
					print_bTree(p->rchild);
				}
				cout<<')';
			}
		}
	}
};

#endif