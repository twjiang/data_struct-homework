#ifndef unionFind_H_INCLUDED
#define unionFind_H_INCLUDED
#include <iostream>
#define MAXSIZE 100

using namespace std;

template <typename ElemType>
class unionFind
{
private:
	struct Node
	{
		ElemType data;
		int parent;
	};
	Node elements[MAXSIZE];
	int number;
public:
	unionFind()
	{

	}
	~unionFind()
	{

	}

	void readData()
	{
		cout << "how many elements you want input: ";
		cin >> number;
		cout << "please input the elements: " << endl;
		for(int i = 0; i < number; i++)
		{
			cin >> elements[i].data;
			elements[i].parent = i;
		}
	}

	void inputRalation()
	{
		int i, j, root1, root2;
		int n = 0;
		cout << "how many ralations you want input: ";
		cin >> n;
		cout << "please input the ralations: " << endl;
		for(int k = 0; k < n; k++)
		{
			cin >> i >> j;
			root1 = find(i);
			root2 = find(j);
			if(root1 != root2)
				myUnion(root1, root2);
		}
	}

	void myUnion(int root1, int root2)
	{
		elements[root2].parent = root1;
	}

	int find(ElemType x)
	{
		int position;
		int temp;
		position = findPosition(x);
		if(position != -1)
		{
			if(elements[position].parent == position)
				return position;
			else
			{
				do
				{
					temp = position;
					position = elements[position].parent;
				}while(elements[position].parent != position);
				return position;
			}
		}	
	}

	ElemType getData(int position)
	{
		return elements[position].data;
	}

	int findPosition(ElemType x)
	{
		for (int i = 0; i < number; )
		{
			if(elements[i].data == x)
				return i;
			i++;
		}
		return -1;
	}
};

#endif