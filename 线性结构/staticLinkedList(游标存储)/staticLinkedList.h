#ifndef staticLinkedList_H_INCLUDED
#define staticLinkedList_H_INCLUDED

#include <iostream>
#define maxsize 20

using namespace std;

typedef int position, Cursor;

template<typename Elemtype>
class staticLinkedList
{
private:
	struct Node
	{
		Elemtype data;
		int next;
	};
	int avail;
	Node storagePoll[maxsize];
	
public:
	staticLinkedList()
	{
		for(int j = 0; j < maxsize - 1; j++)
		{
			storagePoll[j].next = j + 1;
			storagePoll[j].data = 0;
		}
		storagePoll[maxsize - 1].next = -1;
		avail = 0;
		storagePoll[maxsize - 1].data = 0;
	}
	~staticLinkedList()
	{

	}

	int getAvail()
	{
		return avail;
	}
	Cursor getNode()   // p = new Node;
	{
		Cursor p;
		if(storagePoll[avail].next == -1)
			p = -1;
		else
		{
			p = storagePoll[avail].next;
			storagePoll[avail].next = storagePoll[p].next;
		}
		return p;
	} 

	void freeNode(Cursor p)  // delete p;
	{
		storagePoll[p].next = storagePoll[avail].next;
		storagePoll[avail].next = p;
	}

	int insert(Elemtype x, position p)   
	{
		position q;
		q = getNode();
		storagePoll[q].data = x;
		storagePoll[q].next = storagePoll[p].next;
		storagePoll[p].next = q;
		return q;
	}

	void deleteNode(position p)
	{
		position q;
		if(storagePoll[p].next != -1)
		{
			q = storagePoll[p].next;
			storagePoll[p].next = storagePoll[q].next;
			freeNode(q);
		}
	}

	void print()
	{
		int j;
		for(j = 0; j < maxsize; j++)
		{
			cout << storagePoll[j].data << " " << storagePoll[j].next << endl;
		}
		cout << endl;
	}
};

#endif