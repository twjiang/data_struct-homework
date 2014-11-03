#include <iostream>
#include "BTree.h"
#include "InThBTree.h"
#include "PreThBTree.h"
#include "PostThBTree.h"

using namespace std;

void first();
void second();
void third();
void fourth();

int main()
{
	char choice = '9';
	cout << "            ----------欢迎来到二叉树的世界----------            " <<endl;
	
	while(choice != '0')
	{
		cout << "使用普通二叉树请按：    1" <<endl;
		cout << "使用先序线索二叉树请按：2" << endl;
		cout << "使用中序线索二叉树请按：3" << endl;
		cout << "使用后序线索二叉树请按：4" << endl;
		cout << "退出使用请按：          0" <<endl;
		cout << "注：输入二叉树完成时请再输入：0和任意字母" <<endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				first();
				break;
			case '2':
				second();
				break;
			case '3':
				third();
				break;
			case '4':
				fourth();
				break;
			default:
				break;			
		}
	}
	return 0;
}

void first()
{
	BTree<char> myBTree;
	BTree<char>::Node* root;
		
	root = myBTree.createBTree();
	cout <<endl;
	cout << "二叉树（广义表）：  ";
	myBTree.printBTree(root);
	cout <<endl;
	cout <<endl;
	cout << "递归中序遍历：      " ;
	myBTree.inorder(root);
	cout << endl;
	cout <<endl;
	cout << "非递归中序遍历：    " ;
	myBTree.inorder();
	cout << endl;
	cout <<endl;
	cout << "递归先序遍历：      " ;
	myBTree.preorder(root);
	cout << endl;
	cout <<endl;
	cout << "非递归先序遍历：    " ;
	myBTree.preorder();
	cout << endl;
	cout <<endl;
	cout << "递归后序遍历：      " ;
	myBTree.postorder(root);
	cout << endl;
	cout <<endl;
	cout << "非递归后序遍历：    " ;
	myBTree.postorder();
	cout << endl;
	cout <<endl;
	cout << "层序遍历：          " ;
	myBTree.leverorder();
	cout << endl;
	cout <<endl;
}

void second()
{
	PreThBTree<char> myPreThBTree;
	PreThBTree<char>::Node* root;
	
	root = myPreThBTree.createPreThBTree();
	cout <<endl;
	cout << "非递归先序遍历：    ";
	myPreThBTree.thPreOrder();
	cout <<endl;
	cout <<endl;
}

void third()
{
	InThBTree<char> myInThBTree;
	InThBTree<char>::Node* root;
	
	root = myInThBTree.createInThBTree();
	cout <<endl;
	cout << "非递归中序遍历：    ";
	myInThBTree.thInOrder();
	cout <<endl;
	cout <<endl;
}

void fourth()
{
	PostThBTree<char> myPostThBTree;
	PostThBTree<char>::Node* root;
	
	root = myPostThBTree.createPostThBTree();
	cout <<endl;
	cout << "非递归后序遍历：    ";
	myPostThBTree.thPostOrder();
	cout <<endl;
	cout <<endl;
}