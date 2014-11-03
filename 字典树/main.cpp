#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "trie_tree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	trie_tree my_trie_tree;
	ifstream fcin;
	string word;
	char choice = '9';
	fcin.open("news.txt");

	cout << "----------------------------------------------------------------------" << endl;
	cout << "-------------------English articles analysis system-------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "reading a article into system................" << endl;
	while(fcin >> word)
		my_trie_tree.insert_word(word);
	fcin.close();
	while(choice != '0')
	{
		cout << "search word frequency----------------------------1" << endl;
		cout << "statistic word frequency-------------------------2" << endl;
		cout << "sort the words exsistedt-------------------------3" << endl;
		cout << "quit---------------------------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				cout << "the word: ";
				cin >> word;
				cout << "times: " << my_trie_tree.search_word(word) << endl;
				cout << "frequency: " << (float)my_trie_tree.search_word(word) / my_trie_tree.num_of_words() << endl;
				break;	
			case '2':
				my_trie_tree.statistics();
				break;
			case '3':
				my_trie_tree.sort();
				break;	
			default:
				break;			
		}
	}
	return 0;
}