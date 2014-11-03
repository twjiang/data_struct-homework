#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.h"

using namespace std;

int main(int argc, char const *argv[])
{
	char choice = '9', _choice = '9';
	string key;
	hash_table my_hash_table;
	ifstream fcin;
	int address, k, n, count = 0;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "              --------------------Hash--------------------" << endl;
	cout << "direct_addressing------------------1" << endl;
	cout << "prime_divide-----------------------2" << endl;
	cout << "square_middle----------------------3" << endl;
	cout << "fold-------------------------------4" << endl;
	cout << "random-----------------------------5" << endl;
	cout << "choose the hash function: ";
	cin >> _choice;
	if(_choice == '4')
		fcin.open("key2.txt");
	else
		fcin.open("key1.txt");
	do
	{
		cout << "insert the data-----------1" << endl;
		cout << "delete--------------------2" << endl;
		cout << "search--------------------3" << endl;
		cout << "print table---------------4" << endl;
		cout << "quit----------------------0" << endl;
		cout << "choose the operation: ";
		cin >> choice;
		switch(choice)
		{
			case '1':
				cout << "n = ";
				cin >> n;
				for(int i = 0; i < n; i++)
				{
					fcin >> key;
					k = my_hash_table.insert_key(key, _choice);
				}
				//cout << k << endl;
				count = count + n;
				cout << "A = ";
				cout << (float)count / k << endl;
				//fcin.close();
				break;
			case '2':
				cout << "the key: ";
				cin >> key;
				my_hash_table.delete_key(key, _choice);
				break;
			case '3':
				cout << "the key: ";
				cin >> key;
				address  = my_hash_table.search_key(key, _choice);
				cout << key << " is in " << "F[" << address << "]" << endl;
				break;
			case '4':
				cout << "-------------------------------------------------------" << endl;
				my_hash_table.print_table();
				cout << "-------------------------------------------------------" << endl;
				break;
			default:
				break;
		}
	}while(choice != '0'); 

	return 0;
}