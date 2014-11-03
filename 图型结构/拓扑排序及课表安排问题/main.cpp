#include <iostream>
#include <string>
#include "AOV_network.h"

using namespace std;

int main()
{
	AOV_network<string> course;
	char choice = '9';
	cout << "   ----------the establish of AOV network and topological sort----------   " <<endl;
	
	while(choice != '0')
	{
		cout << "build the AOV network----------------1" << endl;
		cout << "print the AOV network----------------2" << endl;
		cout << "topological sort for the AOV---------3" << endl;
		cout << "quit---------------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				course.create_AOV_network();
				break;
			case '2':
				course.print_AOV_network();
				break;
			case '3':
				course.topological_sort();
				break;
			default:
				break;			
		}
	}
	return 0;
}