#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
	heap<int> myHeap;
	int length;
	cout << "Please input the length of data sequence:";
	cin >> length;
	cout << "Please input data sequence:" << endl;
	myHeap.createHeapTree(length);
	myHeap.heapSort();
	cout << "the sorted data sequence:" << endl;
	myHeap.printSortResult();
	return 0;
}

