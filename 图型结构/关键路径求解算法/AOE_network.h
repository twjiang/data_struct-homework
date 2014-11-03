#ifndef AOE_network_H_INCLUDED
#define AOE_network_H_INCLUDED

#include <iostream>
#include <fstream>
#include "linkedQueue.h"
#define infinity 111
#define max 100

using namespace std;

template <typename VertexData>
class AOE_network
{
public:
	AOE_network()
	{
		for(int i = 1; i <= max; i++)
		{
			in_node_number[i] = 0; 
		}
		/*for(int i = 1; i <= max; i++)
		{
			for(int j = 1; j <= max; j++)
			{
				ACT[i][j] = infinity;
			}
		}*/
		n = 0;
		e = 0;
		fcin.open("AOE_graph.txt");
	}
	~AOE_network()
	{

	}
	int location(VertexData x) 
	{  
		int k;
		for(k = 0; vertex[k]!= x; k++);  
	  	return k;  
	}
	void create_AOE_network()
	{
		cout << "reading from AOE graph file... ..." << endl;

		fcin >> n >> e;
		
		for(int i = 1; i <= n; i++)
		{
			fcin >> vertex[i];
			verlist[i].vertex = vertex[i];
			verlist[i].firstedge = NULL;

			in_verlist[i].vertex = vertex[i];
			in_verlist[i].firstedge = NULL;
		}
	
		for(int j = 1; j <= e; j++)
		{
			VertexData v1, v2;
			int weight, No1, No2;
			fcin >> v1 >> v2 >> weight;
			No1 = location(v1);
			No2 = location(v2);
			in_node_number[No2]++;

			a[j].begin = No1;
			a[j].end = No2;
			a[j].cost = weight;
			
			EdgeNode *p = new EdgeNode;
			p->adjvex = No2;
			p->cost = weight;
			p->next = NULL;
			if(verlist[No1].firstedge == NULL)
				verlist[No1].firstedge = p;
			else
			{
				EdgeNode *q = verlist[No1].firstedge;
				while(q->next != NULL)
					q = q->next;
				q->next = p;
			};

			EdgeNode *r = new EdgeNode;
			r->adjvex = No1;
			r->cost = weight;
			r->next = NULL;
			if(in_verlist[No2].firstedge == NULL)
				in_verlist[No2].firstedge = r;
			else
			{
				EdgeNode *s = in_verlist[No2].firstedge;
				while(s->next != NULL)
					s = s->next;
				s->next = r;
			};
		}
		cout << "successful." << endl;
	}

	void print_AOE_network()
	{
		cout << "-----------------the AOE network(out)-----------------" << endl;
		for(int i = 1; i <= n; i++)
		{
			if(verlist[i].firstedge != NULL)
			{
				cout << vertex[i] << "->";
				EdgeNode *p = verlist[i].firstedge;
				while(p->next != NULL)
				{
					cout << vertex[p->adjvex] << ", ";
					p = p->next;
				}
				cout << vertex[p->adjvex] << endl;
			}
			else
			{
				cout << vertex[i] << endl;
			}
		}
		cout << "--------------------------------------------------" << endl;
		cout << "-----------------the AOE network(in)-----------------" << endl;
		for(int i = 1; i <= n; i++)
		{
			if(in_verlist[i].firstedge != NULL)
			{
				cout << vertex[i] << "<-";
				EdgeNode *p = in_verlist[i].firstedge;
				while(p->next != NULL)
				{
					cout << vertex[p->adjvex] << ", ";
					p = p->next;
				}
				cout << vertex[p->adjvex] << endl;
			}
			else
			{
				cout << vertex[i] << endl;
			}
		}
		cout << "--------------------------------------------------" << endl;
	}
	void critical_path()
	{
		topological_sort();
		VE[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			int k = topological_array[i];
			VE[k] = find_max(k);
		}
		VL[n] = VE[n];
		for(int i = n-1; i >= 1; i--)
		{
			int j = topological_array[i];
			VL[j] = find_min(j);
		}
		cout << "-------------------------------------------------------------" << endl;
		cout << "event  " << "earliest   " << "latest     " << endl;
		for(int i = 1; i <= n; i++)
		{
			cout << vertex[i] << "       " << VE[i] << "       " << VL[i] << endl;
		}
		cout << "-------------------------------------------------------------" << endl;
		for(int i = 1; i <= e; i++)
		{
			a[i].early = VE[a[i].begin];
			a[i].late = VL[a[i].end] - a[i].cost;
		}

		cout << "activity  " << "earliest   " << "latest    " << endl;
		for(int i = 1; i <= e; i++)
		{
			cout << "a"  << i << "            " << a[i].early << "        " << a[i].late << endl;
		}
		cout << "-------------------------------------------------------------" << endl;

		cout << "the critical activity: " << endl;
		for (int i = 1; i <= e; i++)
		{
			if(a[i].early == a[i].late)
				cout << "a"  << i << " ";
		}
		cout << endl;

		cout << "the critical path: " << endl;
		for (int i = 1; i <= e; i++)
		{
			if(a[i].early == a[i].late)
				cout << vertex[a[i].begin] << "->" << vertex[a[i].end] << " ";
		}
		cout << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
private:
	ifstream fcin;

	VertexData vertex[max];
	//int ACT[max][max];
	int n, e;
	struct EdgeNode
	{
		int adjvex;
		int cost;
		EdgeNode *next;
	};
	struct VertexNode
	{
		VertexData vertex;
		EdgeNode *firstedge;
	};
	VertexNode verlist[max];
	VertexNode in_verlist[max];
	int in_node_number[max];
	int topological_array[max];

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
		//cout << "--------the result of topological_sort----------" << endl;
		while(!no_in_node.isEmpty())
		{
			int k = no_in_node.getFront();
			no_in_node.outQueue();
			//cout << k << ". " << vertex[k] << endl;
			topological_array[count+1] = k;
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
		//cout << "------------------------------------------------" << endl;
		return;
	}

	int VE[max];

	int find_max(int k)
	{
		EdgeNode *p = in_verlist[k].firstedge;
		int _max = 0;
		while(p != NULL)
		{
			if(VE[p->adjvex] + p->cost > _max)
				_max = VE[p->adjvex] + p->cost;
			p = p->next;
		}
		return _max;
	}

	int VL[max];

	int find_min(int j)
	{
		EdgeNode *p = verlist[j].firstedge;
		int _min = infinity;
		while(p != NULL)
		{
			if(VL[p->adjvex] - p->cost < _min)
				_min = VL[p->adjvex] - p->cost;
			p = p->next;
		}
		return _min;
	}

	struct activity
	{
		int begin;
		int cost;
		int end;
		int early;
		int late;
	};

	activity a[max];
};

#endif