#include <iostream>
#include <string>

#include "undirectedGraph.h"
#include "directedGraph.h"

void graph1();
void graph2();

int main()
{
	char choice = '3';
	cout << "            ----------欢迎来的到图的世界----------            " <<endl;
	
	while(choice != '0')
	{
		cout << "使用无向图请按：    1" <<endl;
		cout << "使用有向图请按：    2" << endl;
		cout << "退出使用请按：      0" <<endl;
		cout << "注：输入用空格隔开。" << endl;
		cin >> choice;
		switch(choice)
		{
			case '1':
				graph1();
				break;
			case '2':
				graph2();
				break;
			default:
				break;			
		}
	}
	return 0;
}

void graph1()
{
	undirectedGraph<string> graph;
	graph.createGraph();
	graph.traversal();
}

void graph2()
{
	directedGraph<string> graph;
	graph.createGraph();
	graph.traversal();
}