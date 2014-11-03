#ifndef AVLTREE_H_INCLUDE
#define AVLTREE_H_INCLUDE

#include <iostream>

using namespace std;

template<typename DataType>
class AVLtree
{
public:
	struct Node			//二叉查找树的存储结构
	{
		DataType data;
		Node *lchild;    //左儿子
		Node *rchild;    //右儿子
		int height;
	};
	AVLtree()
	{
		root = NULL;
	}
	~AVLtree()
	{

	}

	int max(int a, int b)
	{
		if(a > b)
			return a;
		else
			return b;
	}
	void insert(DataType data, Node *&p)     //插入
	{
		if(p == NULL)
		{
			p = new Node;
			p->data = data;
			p->lchild = NULL;
			p->rchild = NULL;
			p->height = 0;
		}
		else if(data < p->data)
		{
			insert(data, p->lchild);	    //递归调用该函数本身
			if(treeHeight(p->lchild) - treeHeight(p->rchild) == 2) //判断二叉树是否出现不平衡状态，是则进入该分支 
	        {                               
	            if(data < p->lchild->data)       //若输入的数据比左孩子结点的数据小，则进行左旋转 
	            	p = LeftRotate(p);
	            else                        //否则先进行左旋转再右旋转 
	            	p = LR_Rotate(p); 	
	        }
		}         
		else if(data > p->data)
		{
			insert(data, p->rchild);         //递归调用该函数本身 
	        if(treeHeight(p->rchild) - treeHeight(p->lchild) == 2) //判断二叉树是否出现不平衡状态，是则进入该分支 
	        {                               
	            if(data > p->rchild->data)       //若输入的数据比右孩子结点的数据大，则进行右旋转
	            	p = RightRotate(p); 
	            else                        //否则先进行右旋转再左旋转
            		p = RL_Rotate(p);
	        } 
		}         
		p->height = max(treeHeight(p->lchild), treeHeight(p->rchild)) + 1;
	}
	void mydelete(DataType data, Node *&p)
	{
		if(p != NULL)
		{
			if(data < p->data)
			{

				mydelete(data, p->lchild);
				if(treeHeight(p->lchild) - treeHeight(p->rchild) == -2)
					p = LR_Rotate(p);
				if(treeHeight(p->lchild) - treeHeight(p->rchild) == 2)
					p = LeftRotate(p);
			}
			else if(data > p->data)
			{
				mydelete(data, p->rchild);
				if(treeHeight(p->lchild) - treeHeight(p->rchild) == 2)
					p = RL_Rotate(p);
				if(treeHeight(p->lchild) - treeHeight(p->rchild) == -2)
					p = RightRotate(p);
			}
			else
			{
				if(p->rchild == NULL)
					p = p->lchild;
				else if(p->lchild == NULL)
					p = p->rchild;
				else
					p->data = deletemin(p->rchild);
			}
		}
	}
	DataType deletemin(Node *&p)
	{
		DataType tmp;
		Node *q;
		if(p->lchild == NULL)
		{
			q = p;
			tmp = p->data;
			p = p->rchild;
			delete q;
			return tmp;
		}
		else
			return deletemin(p->lchild);
	}
	void find(DataType data, Node *&p)
	{
		if(p == NULL)
		{
			cout << "sorry, there is no such data." << endl;
		}
		else if(data < p->data)
		{
			find(data, p->lchild);	    //递归调用该函数本身
		}         
		else if(data > p->data)
		{
			find(data, p->rchild);         //递归调用该函数本身 
		}
		else
		{
			cout << "hava found it : " << data << endl; 
		}         
	}

	Node *create()
	{
		DataType data;
		cin >> data;
		while(data)         //data = 0时，输入结束
		{
			cout << "Insert " << data <<"... ...";
			cout << endl;
			insert(data, root);
			cout << "after balance : ";
			print(root);
	        cout << endl;
	        cout <<"----------------------------------";
	        cout << endl;
			cin >> data;
		}
		return root;       
	}
	int treeHeight(Node *p) //实现求树的高度的函数 
	{ 
	    if(p == NULL)       //判断二叉树是否为空 
	    	return -1; 
	    else
	    	return p->height; 
	}

	Node *LeftRotate(Node *p)             //实现树的顺时针旋转函数
	{ 
	    Node *temp; 
	    temp = p->lchild; 
	    p->lchild = temp->rchild; 
	    temp->rchild = p; 
	    temp->height = max(treeHeight(temp->lchild), p->height) + 1; 
	    p->height = max(treeHeight(p->lchild), treeHeight(p->rchild)) + 1; 
	    return temp;                      //返回新的根节点
	} 
	Node *RightRotate(Node *p)            //实现树的逆时针旋转函数 
	{ 
	    Node *temp; 
	    temp = p->rchild; 
	    p->rchild = temp->lchild; 
	    temp->lchild = p; 
	    p->height = max(treeHeight(p->lchild), treeHeight(p->rchild)) + 1; 
	    temp->height = max(treeHeight(p->rchild), p->height) + 1; 
	    return temp;                        //返回新的根节点 
	} 
	Node *LR_Rotate(Node *p)                //实现树的向左旋转再向右旋转函数 
	{ 
	    p->lchild = RightRotate(p->lchild);  //先逆时针旋转 
	    return LeftRotate(p);               //再顺时针旋转 
	} 
	Node *RL_Rotate(Node *p)              //实现树的向右旋转再向左旋转函数 
	{ 
	    p->rchild = LeftRotate(p->rchild);    //先顺时针旋转 
	    return RightRotate(p);              //再逆时针旋转 
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
private:
	Node *root;

};

#endif