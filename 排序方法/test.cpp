#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "sort.h"

using namespace std;

//int A[max];
vector<int> A;

void choose_sort(int n);

int main(int argc, char const *argv[])
{
	int n;

	char choice = '9';
	cout << "        ----------welcome to the world of sort----------            " <<endl;
	
	while(choice != '0')
	{
		cout << "have a try-----------------------1" << endl;
		cout << "reading 100000 integer-----------2" << endl;
		cout << "reading 200000 integer-----------3" << endl;
		cout << "reading 400000 integer-----------4" << endl;
		cout << "reading 800000 integer-----------5" << endl;
		cout << "reading 1600000 integer----------6" << endl;
		cout << "quit-----------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				n = 10;
				choose_sort(n);
				break;
			case '2':
				n = 100000;
				choose_sort(n);
				break;
			case '3':
				n = 200000;
				choose_sort(n);
				break;
			case '4':
				n = 400000;
				choose_sort(n);
				break;
			case '5':
				n = 800000;
				choose_sort(n);
				break;
			case '6':
				n = 1600000;
				choose_sort(n);
				break;
			default:
				break;			
		}
	}
	
	return 0;
}

void choose_sort(int n)
{
	ifstream fcin;
	int temp;

	char choice = '3';
	char ch;
	while(choice != '0')
	{
		cout << "using bubble sort-----------1" << endl;
		cout << "using quick sort------------2" << endl;
		cout << "using insert sort-----------3" << endl;
		cout << "using shell sort------------4" << endl;
		cout << "using selection sort--------5" << endl;
		cout << "using heap sort-------------6" << endl;
		cout << "using merge sort------------7" << endl;
		cout << "using radix sort------------8" << endl;
		cout << "quit------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				bubble_sort(A, n);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '2':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				quick_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '3':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				insert_sort(A, n);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '4':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				shell_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '5':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				selection_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '6':
				fcin.open("random.txt");
				A.clear();
				A.push_back(0);
				for(int i = 1; i <= n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				heap_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = n; i >= 1; i--)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '7':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				merge_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			case '8':
				fcin.open("random.txt");
				A.clear();
				for(int i = 0; i < n; i++)
				{
					fcin >> temp;
					A.push_back(temp);
				}
				radix_sort(A);
				cout << "the sort is done, print the result? y/n: ";
				cin >> ch;
				if(ch == 'y' || ch == 'Y')
				{
					for(int i = 0; i < n; i++)
						cout << A[i] << "\t";
					cout << endl;
				}
				fcin.close();
				break;
			default:
				break;			
		}
	}
}
