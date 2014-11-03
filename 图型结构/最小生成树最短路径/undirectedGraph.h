#ifndef UNDIRECTEDGRAPH_H_INCLUDED
#define UNDIRECTEDGRAPH_H_INCLUDED

#define max 100
#define infinity 111
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<typename VertexData>
class undirectedGraph
{
public:
	undirectedGraph()
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
		fcin.open("undirected_graph.txt");
	}
	~undirectedGraph()
	{

	}

    int location(VertexData x) 
	{	
		int k;
		for(k = 1; vertex[k]!= x; k++);  
	  	return k;  
	}
	void create_graph()
	{
		cout << "reading from undirected graph file... ..." << endl;

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

			edges[j].weight = weight;
			edges[j].begin = m;
			edges[j].end = n;

			edge[m][n] = weight;
			edge[n][m] = edge[m][n];

			EdgeNode *p = new EdgeNode;
			EdgeNode *q = new EdgeNode;
			p->adjvex = location(v2);
			p->cost = weight;
			p->next = verlist[location(v1)].firstedge;
			verlist[location(v1)].firstedge = p;
			q->adjvex = location(v1);
			q->cost = weight;
			q->next = verlist[location(v2)].firstedge;
			verlist[location(v2)].firstedge = q;
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
	void mst_prim()
	{
		int lowcost[max], closset[max], flag[max];
		int i, j, k, min;
		flag[1] = 1;
		for(i = 2; i <= n; i++)
		{ 
			lowcost[i] = edge[1][i]; 
			closset[i] = 1; 
			flag[i] = 0;
		}
		for(i = 2; i <= n; i++)
		{ 
			min = lowcost[i];
			k = i;
			for( j = 2; j <= n; j++ )
			{
				if (lowcost[j] < min )
				{
					min = lowcost[j]; 
					k = j; 
				}
			}	
			cout << "(" << vertex[closset[k]] << "," << vertex[k] << "," << edge[closset[k]][k] << ")" << endl;
			flag[k] = 1;
			lowcost[k] = infinity;
			for ( j = 2; j <= n;  j++ )
			{
				if(flag[j] == 0)
				{
					if (edge[k][j] < lowcost[j])
					{ 
						lowcost[j]=edge[k][j]; 
						closset[j]=k; 
					}
				}
			}
		}
	}
	void mst_kruskal()
	{
		int parents[max];
		quick_sort(edges, 1, e);
		int bnf, edf;
		/*for(int i = 1; i <= e; i++)
		{
			cout << edges[i].begin << " " << edges[i].weight << " " << edges[i].end << endl;
		}*/
		for(int i = 1; i <= n; i++)
		{
			parents[i] = 0;
		}
		for(int i = 1; i <= e; i++)
		{
			bnf = find(edges[i].begin, parents);
			edf = find(edges[i].end, parents);
			if(bnf != edf)
			{
				parents[edf] = bnf;
				cout << "(" << vertex[edges[i].begin] << ",";
				cout << vertex[edges[i].end] << "," << edges[i].weight << ")";
				cout << endl;
			}
		}
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

	//mst_kruskal
	struct EdgesInformation         //record the information of edges
	{
		int weight;
		int begin;
		int end;
	};
	EdgesInformation edges[max];
	int partition(EdgesInformation A[], int p, int r)
	{
		int x = A[r].weight;
		int i = p - 1;
		for(int j = p; j <= r-1; j++)
		{
			if(A[j].weight <= x)
			{
				i = i + 1;
				EdgesInformation temp1 = A[i];
				A[i] = A[j];
				A[j] = temp1;
			}
		}
		EdgesInformation temp2 = A[i+1];
		A[i+1] = A[r];
		A[r] = temp2;
		return (i + 1);
	}
	void quick_sort(EdgesInformation A[], int p, int r)
	{
		if(p < r)
		{
			int q = partition(A, p, r);
			quick_sort(A, p, q-1);
			quick_sort(A, q+1, r);
		}
	}
	int find(int positon, int parents[])
	{
		while(parents[positon] != 0)
		{
			positon = parents[positon];
		}
		return positon;
	}
	
};

#endif