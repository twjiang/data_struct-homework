#ifndef memory_H_INCLUDED
#define memory_H_INCLUDED

#include <iostream>
#define MAXSIZE 20

using namespace std;

template <typename ElemType>
class memory
{
private:
	struct Node
	{
		int next;
		ElemType data;
	};
	Node _storage_poll[MAXSIZE];   // simulation of memory
	int free;             // to record the location of free storagePoll
	int _list_head[MAXSIZE];    // to record the location of each list
	int count;
	
public:
	memory()
	{
		free = 1;
		count = 1;
		for(int i = 1; i < MAXSIZE; i++)
			_list_head[i] = 0;
		for(int i = 1; i < MAXSIZE - 1; i++)
			_storage_poll[i].next = i + 1;
		_storage_poll[MAXSIZE-1].next = -1;
	}
	
	void checkUsage()
	{
		int p = free, i = 1, q = 0;
		cout << "the available memory: " << endl;
		while(_storage_poll[p].next != -1)
		{
			cout << p << " ";
			p = _storage_poll[p].next;
		}
		cout << p << endl;
		
		cout << "occupied memory: " << endl;
		while(_list_head[i])
		{
			q = _list_head[i];
			cout << "list" << i << ": ";
			while(_storage_poll[q].next != -1)
			{
				cout << q << " ";
				q = _storage_poll[q].next;
			}
			cout << q << endl;
			
			i++;
		}
		cout << endl;
	}
	
	void createList()
	{
		_list_head[count] = free;
		free = _storage_poll[free].next;
		_storage_poll[_list_head[count]].next = -1;
		
		cout << "list" << count << " has been established." << endl;
		count++;
	}
	
	void operateList(int p)
	{
		if(_list_head[p] != 0)
		{
			operation(_list_head[p]);
		}
		
		else
			cout << "the list has not yet been established." << endl;
	}
	
	void operation(int head)
	{
		char choice = '9';
		ElemType data;
		cout << "basic operations : " << endl;
		cout << "insert(default)--------------1" << endl;
		cout << "delete-----------------------2" << endl;
		cout << "print list-------------------3" << endl;
		cout << "quit-------------------------0" << endl;
		do
		{
			cout << "choose the basic operations: ";
			cin >> choice;
			switch(choice)
			{
				case '1':
					cout << "the data you want inserted: ";
					cin >> data;
					_list_insert(head, data);
					break;
				case '2':
					cout << "the data you want deleted: " ;
					cin >> data;
					_list_delete(head, data);
					break;
				case '3':
					cout << "the list: ";
					_list_print(head);
					break;
				default:
					break;
			}
		}while(choice != '0');
	}
	
	void _list_insert(int head, int data)
	{
		int p = head, temp;
		while(_storage_poll[p].next != -1)
			p = _storage_poll[p].next;
			
		_storage_poll[free].data = data;
		_storage_poll[p].next = free;
		temp = free;
		free = _storage_poll[free].next;
		_storage_poll[temp].next = -1;
	}
	
	void _list_delete(int head, ElemType data)
	{
		int p = _storage_poll[head].next;
		if(p == -1)
		{
			cout << "the list is empty." << endl;
			return;
		}
		else
		{
			while(p != -1 && _storage_poll[p].data != data)
			{
				p = _storage_poll[p].next;
			}
			if( p == -1)
			{
				cout << "the data is not found." << endl;
				return;
			}
			else
			{
				int q = head;
				while(_storage_poll[q].next != p)
					q = _storage_poll[q].next;
				_storage_poll[q].next = _storage_poll[p].next;
				_storage_poll[p].next = free;
				free = p;
			}
		}
	}
	
	void _list_print(int head)
	{
		int p = head, temp;
		while(_storage_poll[p].next != -1)
		{
			if(p != head)
				cout << _storage_poll[p].data << " ";
			p = _storage_poll[p].next;
		}
		if(p != head)
			cout << _storage_poll[p].data << endl;
		else
			cout << "the list is empty." << endl;
	}
	
};

#endif