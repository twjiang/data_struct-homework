#ifndef heap_H_INCLUDED
#define heap_H_INCLUDED

#include <iostream>
#define MAXSIZE 10000

using namespace std;

template<typename ElemType>
class heap
{
public:
	void createHeapTree(int m)
	{
		int i;
		n = m;
		ElemType _data;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> _data;
			data[i] = _data;
		}	
	}
	
	void heapSort ()
	{
		int i;
		for( i = n/2; i >= 1; i--) 
			pushDown(i, n); 
		for( i = n; i >= 2; i--) 
		{
			swap(data[1], data[i]); 
			pushDown( 1, i-1 );
		}
	}

	void pushDown(int first, int last)
	{ 
		int r = first;
		while(r<=last/2)
		{
			if(r == last / 2 && last % 2 == 0)
			{
				if(data[r] > data[2*r])
					swap(data[r], data[2*r]);
				r = last;
			}
			else if(data[r] > data[2*r] && data[2*r] <= data[2*r+1])
			{
				swap(data[r], data[2*r]);
				r = 2 * r;
			}
			else if(data[r] > data[2*r+1] && data[2*r] > data[2*r+1])
			{
				swap(data[r], data[2*r+1]);
				r = 2 * r + 1;
			}
			else
				r = last;
		}
	}
	
	void printSortResult()
	{
		for(int i = n; i >= 1; i--)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

private:
	ElemType data[MAXSIZE];
	int n;

};

#endif
