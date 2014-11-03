#ifndef hash_table_H_INCLUDED
#define hash_table_H_INCLUDED
#define B 100000
#include <iostream>
#include <string>  
#include <sstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int h_direct_addressing(string key);
int h_prime_divide(string key);
int h_square_middle(string key, int m);
int h_fold(string key, int m);
int h_random(string key);

class hash_table
{
private:
	struct Node
	{
		string data;
		Node *next;
	};
	Node *F[B];
	int m;
public:
	hash_table()
	{
		for(int i = 0; i < B; i++)
			F[i] = NULL;
	}	
	~hash_table()
	{

	}

	Node *search_key(string key, char choice)
	{
		Node *bptr;
		int locate;
		switch(choice)
		{
			case '1':
				locate = h_direct_addressing(key);
				break;
			case '2':
				locate = h_prime_divide(key);
				break;
			case '3':
				locate = h_square_middle(key, 5);
				break;
			case '4':
				locate = h_fold(key, 4);
				break;
			case '5':
				locate = h_random(key);
				break;
			default:
				break;
		}
		bptr = F[locate];
		return bptr;
	}
	int insert_key(string key, char choice)
	{
		int bucket, k;
		Node *old_header;
		if(search_key(key, choice) == NULL)
		{
			switch(choice)
			{
				case '1':
					bucket = h_direct_addressing(key);
					break;
				case '2':
					bucket = h_prime_divide(key);
					break;
				case '3':
					bucket = h_square_middle(key, 5);
					break;
				case '4':
					bucket = h_fold(key, 4);
					break;
				case '5':
					bucket = h_random(key);
					break;
				default:
					break;
			}
			old_header = F[bucket];
			F[bucket] = new Node;
			F[bucket]->data = key;
			F[bucket]->next = old_header;
		}
		else
		{
			switch(choice)
			{
				case '1':
					bucket = h_direct_addressing(key);
					break;
				case '2':
					bucket = h_prime_divide(key);
					break;
				case '3':
					bucket = h_square_middle(key, 5);
					break;
				case '4':
					bucket = h_fold(key, 4);
					break;
				case '5':
					bucket = h_random(key);
					break;
				default:
					break;
			}
			Node *p = new Node;
			p->data = key;
			p->next = F[bucket]->next;
			F[bucket]->next = p;
		}
		for (int i = 0; i < B; i++)
		{
			if(F[i] != NULL)
				k = i + 1;
		}
		return k;
	}
	void delete_key(string key, char choice)
	{
		int bucket;
		switch(choice)
		{
			case '1':
				bucket = h_direct_addressing(key);
				break;
			case '2':
				bucket = h_prime_divide(key);
				break;
			case '3':
				bucket = h_square_middle(key, 5);
				break;
			case '4':
				bucket = h_fold(key, 4);
				break;
			case '5':
				bucket = h_random(key);
				break;
			default:
				break;
		}
		Node *bptr, *p;
		if(F[bucket] != NULL)
		{
			if(F[bucket]->data == key)
			{
				bptr = F[bucket];
				F[bucket] = F[bucket]->next;
				free(bptr);
			}
			else
			{
				bptr = F[bucket];
				while(bptr->next != NULL)
				{
					if(bptr->next->data == key)
					{
						p = bptr->next;
						bptr->next = p->next;
						free(p);
					}
					else
						bptr = bptr->next;
				}
			}
		}
	}
	void print_table()
	{
		Node *p;
		for(int i = 0; i < B; i++)
		{
			if(F[i] != NULL)
			{
				cout << "F[" << i << "]: ";
				p = F[i];
				while(p != NULL)
				{
					cout << p->data << "\t";
					p = p->next;
				}
				cout << endl;
			}
		}
	}
	void print_list(Node *p)
	{
		for(int i = 0; i < B; i++)
		{
			if(p == F[i])
			{
				cout << "F[" << i << "]: ";
				while(p != NULL)
				{
					cout << p->data << "\t";
					p = p->next;
				}
				cout << endl;
				return;
			}
		}
	}
};

int h_direct_addressing(string key)
{
	int temp_key = atoi(key.c_str());
	int address = temp_key / 10;
	return address;
}

int h_prime_divide(string key)
{
	int temp_key = atoi(key.c_str());
	int address = temp_key % 11;
	return address;
}

int h_square_middle(string key, int m)
{
	int temp_key = atoi(key.c_str());
	if(temp_key >= 46340)
	{
		cout << "sorry, the integer is too big." << endl;
		return -1;
	}
	int int_temp;
	string string_temp1;
	string string_temp2;
	stringstream str_stream;
	int_temp = temp_key * temp_key;
    
    str_stream << int_temp;
    string_temp1 = str_stream.str();

    //cout << int_temp << endl;
    //cout << string_temp1 << endl;
    int n = 2 * m - string_temp1.size();
    while(n--)
    	string_temp1.insert(0, 1, '0');
    //cout << string_temp1 << endl;

    string_temp2.append(string_temp1, m / 2, m);  
    //cout << string_temp2 << endl; 

    int address = atoi(string_temp2.c_str());
    //cout << address << endl; 
    return address;                
}

int h_fold(string key, int m)
{
	int A[100], i, sum = 0;
	string temp;
	int n = key.size() / m;
	for(i = 1; i <= n; i++)
	{
		temp.append(key, key.size() - i * m, m);
		//cout << temp << endl;
		A[i] = atoi(temp.c_str());
		//cout << A[i] << endl;
		temp.clear();
	}
	int num = i - 1;
	if(key.size() % m)
	{
		temp.append(key, 0, key.size() - n * m);
		//cout << temp << endl;
		A[i] = atoi(temp.c_str());
		num = i;
		//cout << A[i] << endl;
	}
	for(int j = 1; j <= num; j++)
	{
		sum = sum + A[j];
	}	
	//cout << sum << endl;

	int index = 1;
	for(int k = 1; k <= m; k++)
		index *= 10;
	int address = sum % index;
	//cout << address << endl;

	return address;
}

int h_random(string key)
{
	//srand((unsigned)time(0));
	int address = rand() % (B-1);
	return address;
}

#endif