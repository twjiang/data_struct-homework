#include <iostream>
#include "AOE_network.h"

using namespace std;

int main(int argc, char const *argv[])
{
	AOE_network<string> my_AOE;
	char choice = '9';
	cout << "   ----------the establish of AOE network and the critical path----------   " <<endl;
	
	while(choice != '0')
	{
		cout << "build the AOE network----------------1" << endl;
		cout << "print the AOE network----------------2" << endl;
		cout << "the critical path for the AOV--------3" << endl;
		cout << "quit---------------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				my_AOE.create_AOE_network();
				break;
			case '2':
				my_AOE.print_AOE_network();
				break;
			case '3':
				my_AOE.critical_path();
				break;
			default:
				break;			
		}
	}
	return 0;
}