#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "mergeSort.h"
#define max 1000

using namespace std;

class HuffmanTree
{
public:
	HuffmanTree()
	{
		for(int i = 0; i < max; i++)
		{
			HuffmanT[i].weight = 0;
			HuffmanT[i].lchild = -1;
			HuffmanT[i].rchild = -1;
			HuffmanT[i].parent = -1;
		}
	}
	~HuffmanTree()
	{

	}

	int findmin(vector<double> & a)
	{
	        int i = -1;
	        do
	        {
	        	i++;
	        }while(HuffmanT[i].weight != a[0]);
	        return i;
	}

	int findsmin(vector<double> & a)
	{
	        int i = -1;
	        do
	        {
	        	i++;
	        }while(HuffmanT[i].weight != a[1]);
	        return i;
	}
	void create()
	{
		int p1, p2, temp;
		
		cout << "how many character you want to input: ";
		cin >> n;
		cout << "please input the character and the weight of each character: " << endl;
		for(count = 0; count < n; count++)
		{
			cin >> HuffmanT[count].ch;
			cin >> HuffmanT[count].weight;
			v.push_back(HuffmanT[count].weight);
		}
		
		temp = n - 1;
		while(temp --)
		{
			mergeSort(v);
			p1 = findmin(v);
			p2 = findsmin(v);
			v.push_back(v[0] + v[1]);
			
			HuffmanT[count].weight = v[0] + v[1];
			HuffmanT[count].lchild = p1;
			HuffmanT[count].rchild = p2;
			HuffmanT[p1].parent = count;
			HuffmanT[p2].parent = count;
			count++;
			
			v.erase(v.begin());
			v.erase(v.begin());
		}
	}
	
	void printTree()
	{
		for(int i = 0; i < count; i++)
		{
			cout << HuffmanT[i].ch << " " <<HuffmanT[i].weight << " " << HuffmanT[i].parent 
				 << " " << HuffmanT[i].lchild << " " << HuffmanT[i].rchild << endl;
		}
	}
	
	void encoding()
	{
		for(int i = 0; i < n; i++)
		{
			int parent = HuffmanT[i].parent;
			int child = i;
			do
			{
				if(child == HuffmanT[parent].rchild)
					code[i].insert(0, "1");
				else
					code[i].insert(0, "0");
				child = parent;
				parent = HuffmanT[parent].parent;
			}while(parent != -1);
		}
		for(int i = 0; i < n; i++)
		{
			cout << HuffmanT[i].ch << ": " << code[i] << endl;
		}
	}
	void decoding(string _code)
	{
		int p = count - 1;
		for(int i = 0; i < _code.length(); i++)
		{
			if(_code[i] == '1')
			{
				p = HuffmanT[p].rchild;
			}
			else
			{
				p = HuffmanT[p].lchild;	
			}
		}
		cout << "the character is : ";
		if(HuffmanT[p].lchild == -1 && HuffmanT[p].lchild == -1)
			cout << HuffmanT[p].ch << endl;
		else
			cout << "no such character for the code." << endl;
	}
private:
	struct HTNode
	{
		char ch;
		double weight;
		int lchild;
		int rchild;
		int parent;
	};
	HTNode HuffmanT[max];
	string code[max];
	int n, count;
	vector<double> v;
};

#endif

