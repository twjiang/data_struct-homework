#include <iostream>
#include <string>

#include "undirectedGraph.h"
#include "directedGraph.h"

void directed_graph();
void undirected_graph();

int main()
{
	char choice = '3';
	cout << "            ----------welcome to the world of graph----------            " <<endl;
	
	while(choice != '0')
	{
		cout << "using directed graph-----------1" << endl;
		cout << "using undirected graph---------2" << endl;
		cout << "quit---------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				directed_graph();
				break;
			case '2':
				undirected_graph();
				break;
			default:
				break;			
		}
	}
	return 0;
}

void directed_graph()
{
	directedGraph<string> graph;
	graph.create_graph();

	char choice = '9';
	while(choice != '0')
	{
		cout << "print the graph with adjacency matrix---------1" << endl;
		cout << "print the graph with adjacency list-----------2" << endl;
		cout << "shortest path(Dijkstra)-----------------------3" << endl;
		cout << "shortest path(Floyd)--------------------------4" << endl;
		cout << "quit------------------------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				graph.print_adjacency_matrix();
				break;
			case '2':
				graph.print_adjacency_list();
				break;
			case '3':
				graph.sp_dijkstra();
				break;
			case '4':
				graph.sp_floyd();
				break;
			default:
				break;			
		}
	}
	return;
}

void undirected_graph()
{
	undirectedGraph<string> graph;
	graph.create_graph();

	char choice = 'A';
	while(choice != '0')
	{
		cout << "print the graph with adjacency matrix---------1" << endl;
		cout << "print the graph with adjacency list-----------2" << endl;
		cout << "minimum spanning tree(Prim)-------------------3" << endl;
		cout << "minimum spanning tree(Kruskal)----------------4" << endl;
		cout << "quit------------------------------------------0" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				graph.print_adjacency_matrix();
				break;
			case '2':
				graph.print_adjacency_list();
				break;
			case '3':
				cout << "--------minimum spanning tree---------" << endl;
				graph.mst_prim();
				cout << "--------------------------------------" << endl;
				break;
			case '4':
				cout << "--------minimum spanning tree---------" << endl;
				graph.mst_kruskal();
				cout << "--------------------------------------" << endl;
				break;
			default:
				break;			
		}
	}
}