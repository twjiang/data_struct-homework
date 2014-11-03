#include <iostream>
#include "memory.h"
#define MAXSIZE 20

using namespace std;

int main()
{
	memory<int> _my_memory;
	char _my_choice = '9';
	int _my_lists_head[MAXSIZE];
	int count = 1;
	
	for(int i = 1; i < MAXSIZE; i++)
			_my_lists_head[i] = 0;
	
	cout << endl;
	cout << "---------------Simulation Of Memory---------------" << endl;
	cout << endl;
	
	while(_my_choice)
	{
		cout << "Check the memory usage----------------------------1" << endl;
		cout << "Establish a new double linked list----------------2" << endl;
		cout << "Operations for list of exisiting------------------3" << endl;
		cout << "quit----------------------------------------------0" << endl;
		cin >> _my_choice;
		
		if(_my_choice == '1')
			_my_memory.checkUsage();
			
		else if(_my_choice == '2')
			_my_memory.createList();
			
		else if(_my_choice == '3')
		{
			int _choice;
			cout << "number of list: ";
			cin >> _choice;
			_my_memory.operateList(_choice);
		}
		
		else
			return 0;
	}
	
	return 0;
}