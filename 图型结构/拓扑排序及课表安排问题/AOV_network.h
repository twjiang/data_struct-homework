#ifndef AOV_network_H_INCLUDED
#define AOV_network_H_INCLUDED

#define max 100
#include <iostream>
#include <string>
#include <fstream>
#include "linkedQueue.h"

using namespace std;

template<typename ElemType>
class AOV_network
{
public:
	AOV_network()
	{
		for(int i = 1; i <= max; i++)
		{
			in_node_number[i] = 0; 
		}
		n = 0;
		e = 0;
		fcin.open("course_AOV.txt");
	}
	~AOV_network()
	{

	}

	int location(string x) 
	{  
		int k;
		for(k = 0; vertex[k]!= x; k++);  
	  	return k;  
	}
	void create_AOV_network()
	{
		cout << "reading from AOV network file... ..." << endl;

		fcin >> n >> e;
		
		for(int i = 1; i <= n; i++)
		{
			fcin >> vertex[i];
			verlist[i].vertex = vertex[i];
			verlist[i].firstedge = NULL;
		}
	
		for(int j = 1; j <= e; j++)
		{
			int No1, No2;
			fcin >> No1 >> No2;
			
			in_node_number[No2]++;
			EdgeNode *p = new EdgeNode;
			p->adjvex = No2;
			p->next = NULL;
			if(verlist[No1].firstedge == NULL)
				verlist[No1].firstedge = p;
			else
			{
				EdgeNode *q = verlist[No1].firstedge;
				while(q->next != NULL)
					q = q->next;
				q->next = p;
			}
		}
		cout << "successful." << endl;
	}
	void topological_sort()
	{
		linkedQueue<int> no_in_node;
		int count = 0;
		for(int i = 1; i <= n; i++)
		{
			if(in_node_number[i] == 0)
			{
				no_in_node.enQueue(i);
			}
		}
		cout << "--------the result of topological_sort----------" << endl;
		while(!no_in_node.isEmpty())
		{
			int k = no_in_node.getFront();
			no_in_node.outQueue();
			cout << k << ". " << vertex[k] << endl;
			count++;

			EdgeNode *p = new EdgeNode;
			p = verlist[k].firstedge;
			while(p != NULL)
			{
				in_node_number[p->adjvex]--;
				if(in_node_number[p->adjvex] == 0)
					no_in_node.enQueue(p->adjvex);
				p = p->next;
			}
		}
		if(count < n)
		{
			cout << "there are circul path!" << endl;
		}
		cout << "------------------------------------------------" << endl;
		return;
	}
	void print_AOV_network()
	{
		cout << "-----------------the AOV network-----------------" << endl;
		for(int i = 1; i <= n; i++)
		{
			cout << i << ". " << vertex[i] << endl;
		}
		cout << endl;
		for(int i = 1; i <= n; i++)
		{
			if(verlist[i].firstedge != NULL)
			{
				cout << i << "->";
				EdgeNode *p = verlist[i].firstedge;
				while(p->next != NULL)
				{
					cout << p->adjvex << ", ";
					p = p->next;
				}
				cout << p->adjvex << endl;
			}
			else
			{
				cout << i << endl;
			}
		}
		cout << "--------------------------------------------------" << endl;
	}
private:
	ifstream fcin;

	ElemType vertex[max];
	int n, e;
	struct EdgeNode
	{
		int adjvex;
		ElemType vertex;
		EdgeNode *next;
	};
	struct VertexNode
	{
		ElemType vertex;
		EdgeNode *firstedge;
	};
	VertexNode verlist[max];
	int in_node_number[max];
};

#endif