#ifndef DIRECTEDGRAPH_H_INCLUDED
#define DIRECTEDGRAPH_H_INCLUDED

#define max 100
#include <iostream>
#include <string>
#include <fstream>
#include "linkedStack.h"

using namespace std;

template<typename VertexData>
class directedGraph
{
public:
	directedGraph()
	{
		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < max; j++)
			{
				edge[i][j] = infinity;
			}
			edge[i][i] = 0;
		}
		n = 0;
		e = 0;
		fcin.open("directed_graph.txt");
	}
	~directedGraph()
	{

	}

	int location(string x) 
	{  
		int k;
		for(k = 0; vertex[k]!= x; k++);  
	  	return k;  
	}
	void create_graph()
	{
		cout << "reading from directed graph file... ..." << endl;

		fcin >> n >> e;
		
		for(int i = 1; i <= n; i++)
		{
			fcin >> vertex[i];
			verlist[i].vertex = vertex[i];
			verlist[i].firstedge = NULL;
		}
	
		for(int j = 1; j <= e; j++)
		{
			VertexData v1, v2;
			int weight, m, n;
			fcin >> v1 >> v2 >> weight;
			m = location(v1);
			n = location(v2);
			edge[m][n] = weight;
			EdgeNode *p = new EdgeNode;
			p->adjvex = location(v2);
			p->cost = weight;
			p->next = verlist[location(v1)].firstedge;
			verlist[location(v1)].firstedge = p;
		}
		cout << "successful." << endl;
	}
	void print_adjacency_matrix()
	{
		cout << "----------------------------------" << endl;
		cout << "adjacency matrix" << endl;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cout << edge[i][j] << " ";
			}
			cout << endl;
		}
		cout << "----------------------------------" << endl;
	}
	void print_adjacency_list()
	{
		cout << "----------------------------------" << endl;
		cout << "adjacency list" << endl;
		for(int i = 1; i <= n; i++)
		{
			cout << verlist[i].vertex << " ";
			EdgeNode *p = verlist[i].firstedge;
			while(p != NULL)
			{
				cout << verlist[p->adjvex].vertex << " ";
				p = p->next;
			}
			cout << endl;
		}
		cout << "----------------------------------" << endl;
	}
	void sp_dijkstra()
	{
		int D[max];     //v1 to vi current shortest path length
		int P[max];
		int count = 0;
		int w;
		bool S[max];
		for(int i = 2; i <= n; i++)   
		{
			D[i] = edge[1][i];
			P[i] = 1;
			S[i] = false;
		}
		S[1] = true;
		for(int i = 1; i <n; i++)
		{
			w = dijkstra_min_cost(D, S);
			S[w] = true;
			for(int j = 2; j <= n; j++)
			{
				if(S[j] != true)
				{
					int sum = D[w] + edge[w][j];
					if(sum < D[j])
					{
						D[j] = sum;
						P[j] = w;
					}
				}
			}
		}
		linkedStack<int> my_stack;
		cout << "----------------shortest path (Dijkstra)------------------" << endl;
		for(int i = 2; i <= n; i++)
		{
			cout << vertex[1] << "-->" << vertex[i] << "(" << D[i] << ")" << ": ";
			int t = P[i];
			while(t != 1)
			{
				my_stack.push(t);
				t = P[t];
			}
			cout << vertex[1] << "->";
			while(!my_stack.empty())
			{
				cout << vertex[my_stack.getTop()] << "->";
				my_stack.pop();
			}
			cout << vertex[i] << endl;
		}
		cout << "----------------------------------------------------------" << endl;
	}
	void sp_floyd()
	{
		int D[max][max], P[max][max];
		for (int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				D[i][j] = edge[i][j];
				P[i][j] = -1;
			}
		}
		for(int k = 1; k <= n; k++)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					if(D[i][k] + D[k][j] < D[i][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						P[i][j] = k;
					}
				}
			}
		}
		cout << "-----------------shortest path (Floyd)------------------" << endl;
		for (int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i != j )
				{
					if(D[i][j] != infinity)
					{
						cout << vertex[i] << "-->" << vertex[j] << "(" << D[i][j] << ")" << ": ";
						floyd_print(P, D, i, j);
						cout << endl;
					}
				}
			}
		}
		cout << "-----------------------------------------------------------" << endl;
	}
private:
	ifstream fcin;

	VertexData vertex[max];
	int edge[max][max];
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

	bool visited[max]; 
	int dfn[max]; 
	int count;

	int dijkstra_min_cost(int D[], bool S[])
	{
		int temp = infinity;
		int w = 2;
		for (int i = 2; i <= n; i++)
		{
			if(!S[i] && D[i] < temp)
			{
				temp = D[i];
				w = i;
			}
		}
		return w;
	}

	void floyd_print(int P[][max], int D[][max], int i, int j)
	{
		if(P[i][j] == -1 && D[i][j] != infinity)
			cout << vertex[i] << "->" << vertex[j] << "(" << D[i][j] << ")" << " ";
		else
		{
			floyd_print(P, D, i, P[i][j]);
			floyd_print(P, D, P[i][j], j);
		}
		
	}
};

#endif