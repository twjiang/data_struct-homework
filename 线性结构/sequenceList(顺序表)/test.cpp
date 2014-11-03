#include <iostream>
#include "sequenceList.h"

using namespace std;

int main()
{
    sequenceList<int> _list;
	_list.addData(45);
	_list.addData(46);
	_list.addData(47);
	_list.addData(48);
	_list.addData(49);
	cout << _list.findFirst(48) << endl;
	_list.deleteData(2);
	cout << _list.findFirst(48) << endl;
	_list.printList();
	
	return 0;
}