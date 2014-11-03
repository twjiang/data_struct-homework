#ifndef sort_H_INCLUDED
#define sort_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

template <typename elemtype>
void bubble_sort(vector<elemtype> &A, int n)
{
	clock_t start_time=clock();
	for(int i = 0; i < n-1; i++)
	{
		for(int j = n-1; j >= i+1; j--)
		{
			if(A[j] < A[j-1])
			{
				elemtype temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
int partition(vector<elemtype> &A, int p, int r)
{
	elemtype x = A[r];
	int i = p - 1;
	for(int j = p; j <= r-1; j++)
	{
		if(A[j] <= x)
		{
			i = i + 1;
			elemtype temp1 = A[i];
			A[i] = A[j];
			A[j] = temp1;
		}
	}
	elemtype temp2 = A[i+1];
	A[i+1] = A[r];
	A[r] = temp2;
	return (i + 1);
}

template <typename elemtype>
void quick_sort(vector<elemtype> &A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

template <typename elemtype>
void quick_sort(vector<elemtype> &A)
{
	clock_t start_time=clock();
	int q = partition(A, 0, A.size()-1);
	quick_sort(A, 0, q-1);
	quick_sort(A, q+1, A.size()-1);
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
void insert_sort(vector<elemtype> &A, int n)
{
	clock_t start_time=clock();
	elemtype key;
	int k;
	for(int i = 1; i < n; i++)
	{
		key = A[i];
		k = i;
		for(int j = i-1; j >= 0; j--)
		{
			if(A[j] > key)
			{
				A[j+1] = A[j];
				k = j;
			}
		}
		A[k] = key;
	}
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
void shell_sort(vector<elemtype> &A)
{
	clock_t start_time=clock();
	for (int gap = A.size() / 2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < A.size(); i++)
		{
			elemtype temp = A[i];
			int j = i;

			for(; j >= gap && temp < A[j-gap]; j-=gap)
			{
				A[j] = A[j-gap];
			}
			A[j] = temp;
		}
	}
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
void selection_sort(vector<elemtype> &A)
{
	clock_t start_time=clock();
	int k;
	elemtype temp;
	for(int i = 0; i < A.size()-1; i++)
	{
		k = i;
		{
			for(int j = i+1; j < A.size(); j++)
			{
				if(A[k] > A[j])
					k = j;
			}
			if(k != i)
			{
				temp = A[i];
				A[i] = A[k];
				A[k] = temp;
			}
		}
	}
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
void pushDown(vector<elemtype> &A, int first, int last)
{ 
	int r = first;
	while(r<=last/2)
	{
		if(r == last / 2 && last % 2 == 0)
		{
			if(A[r] > A[2*r])
				swap(A[r], A[2*r]);
			r = last;
		}
		else if(A[r] > A[2*r] && A[2*r] <= A[2*r+1])
		{
			swap(A[r], A[2*r]);
			r = 2 * r;
		}
		else if(A[r] > A[2*r+1] && A[2*r] > A[2*r+1])
		{
			swap(A[r], A[2*r+1]);
			r = 2 * r + 1;
		}
		else
			r = last;
	}
}

template <typename elemtype>
void heap_sort(vector<elemtype> &A)
{
	clock_t start_time=clock();
	elemtype temp;
	for( int i = A.size() / 2; i >= 1; i--) 
		pushDown(A, i, A.size()); 
	for( int i = A.size(); i >= 2; i--) 
	{
		swap(A[1], A[i]);
		pushDown(A, 1, i-1);
	}
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

template <typename elemtype>
void merge(vector<elemtype> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<elemtype> L;
	std::vector<elemtype> R;
	for(int i = 0; i < n1; i++)
		L.push_back(A[p + i]);
	for(int j = 0; j < n2; j++)
		R.push_back(A[q + j + 1]);
	int i = 0;
	int j = 0;
	for(int k = p; k <= r; k++)
	{
		if((L[i] <= R[j] || j == n2) && i != n1)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

template <typename elemtype>
void merge_sort(vector<elemtype> &A, int p, int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

template <typename elemtype>
void merge_sort(vector<elemtype> &A)
{
	clock_t start_time=clock();
	int q = A.size() / 2;
	merge_sort(A, 0, q);
	merge_sort(A, q+1, A.size()-1);
	merge(A, 0, q, A.size()-1);
	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

//vector<int> D;
void counting_sort(vector<int> &A, vector<int> &B, int k)
{
	vector<int> C;
	vector<int> D;
	for(int i = 0; i < B.size(); i++)
	{
		D.push_back(0);
	}
	for(int i = 0; i < k; i++)
	{
		C.push_back(0);
	}
	for(int i = 0; i < B.size(); i++)
	{
		C[B[i]] = C[B[i]] + 1;
	}
	for(int i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i-1];
	}
	for(int j = A.size()-1; j >= 0; j--)
	{
		D[C[B[j]]-1] = A[j];
		C[B[j]] = C[B[j]] - 1;
	}
	for(int i = 0; i < A.size(); i++)
	{
		A[i] = D[i];
	}
	return;
}

void radix_sort(vector<int> &A)
{
	clock_t start_time=clock();
	
	vector<int> B;
	int index = 1;
	int temp1, temp2;
	bool flag = false;

	for(int i = 0; i < A.size(); i++)
		B.push_back(A[i]);

	while(flag == false)
	{
		flag = true;
		index = index * 10;
		B.clear();
		for(int i = 0; i < A.size(); i++)
		{
			temp1 = A[i] % index;
			temp2 = temp1 / (index / 10);
			if(temp2 > 0)
				flag = false;
			B.push_back(temp2);
		}
		if(flag == false)
		{
			counting_sort(A, B, 10);
		}
	}

	clock_t end_time=clock();
	cout<< "running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}


#endif