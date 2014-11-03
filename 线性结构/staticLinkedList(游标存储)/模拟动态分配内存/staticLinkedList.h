#ifndef staticLinkedList_H_INCLUDED
#define staticLinkedList_H_INCLUDED

#include <iostream>
#define maxsize 20

using namespace std;

typedef int position;

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
	position head;
	
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
	position getHeadNode()   // p = new Node;
	{
		if(storagePoll[avail].next == -1)
			head = -1;
		else
		{
			head = storagePoll[avail].next;
			storagePoll[avail].next = storagePoll[head].next;
			storagePoll[head].next = -1;
		}
		return head;
	} 
	
	position getNode()   // p = new Node;
	{
		position p;
		if(storagePoll[avail].next == -1)
			p = -1;
		else
		{
			p = storagePoll[avail].next;
			storagePoll[avail].next = storagePoll[p].next;
		}
		return p;
	} 

	void freeNode(position p)  // delete p;
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
	
	void insertWithPosition(Elemtype x, position p)   
	{
		position s, q, r = head;
		s = p-1;
		q = getNode();
		storagePoll[q].data = x;
		while(s--)
			r = storagePoll[r].next;
		storagePoll[q].next = storagePoll[r].next;
		storagePoll[r].next = q;
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
	
	void deleteData(Elemtype _data)
	{
		position p = findPreData(_data);
		deleteNode(p);
	}
	
	position findPreData(Elemtype _data)
	{
		position p = head;
		while(storagePoll[p].next != -1)
		{
			if(storagePoll[storagePoll[p].next].data == _data)
				return p;
			else
				p = storagePoll[p].next;
		}
	}

	void print()
	{
		position p = storagePoll[head].next;
		while(storagePoll[p].next != -1)
		{
			cout << storagePoll[p].data << " ";
			p = storagePoll[p].next;
		}
		cout << storagePoll[p].data << endl;
		cout << endl;
	}
	
	void printMemory()
	{
		for(int i = 0; i < maxsize; i++)
		{
			cout << storagePoll[i].data << " " << storagePoll[i].next << endl;
		}
	}
};

#endif