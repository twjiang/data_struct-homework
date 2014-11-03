#include "HuffmanTree.h"
#include <iostream>

using namespace std;

int main()
{
	HuffmanTree myHTtree;
	string code;
	char choice = '9';
	cout << "---------------------Huffman encoding and decoding--------------------" << endl;
	cout << endl;
	cout << "attention: encoding first and then decoding" << endl;
	myHTtree.create();
	cout << "-----------------------------------------" << endl;
	cout << "Huffman treeList: " << endl;
	myHTtree.printTree();
	cout << "-----------------------------------------" << endl;
	cout << "                 -------------encoding--------------" << endl;
	cout << "Huffman encodingList: " << endl;
	myHTtree.encoding();
	cout << "-----------------------------------------" << endl;
	cout << "                 -------------decoding--------------" << endl;
	cout << "decoding---------------1" << endl;
	cout << "quit-------------------0" << endl;
	cin >> choice;
	while(choice != '0')
	{
		switch (choice)
		{
			case '1':
				cout << "the code : ";
				cin >> code;
				myHTtree.decoding(code);
				break;
			case '0':
				return 0;
		}
		cout << "decoding---------------1" << endl;
		cout << "quit-------------------0" << endl;
		cin >> choice;
	}
	;
	cout << "-----------------------------------------" << endl;
	return 0;
}