#ifndef UNDIRECTEDGRAPH_H_INCLUDED
#define UNDIRECTEDGRAPH_H_INCLUDED

#define max 100
#include <iostream>
#include <string>
#include <fstream>
#include "queue.h"

using namespace std;

template<typename VertexData>
class undirectedGraph
{
public:
	struct TreeNode
	{
	    VertexData data;
	    TreeNode *lchild,*rbrother;
	};

	undirectedGraph()
	{
		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < max; j++)
			{
				edge[i][j] = 0;
			}
		}
		n = 0;
		e = 0;
		fcin.open("graph.txt");
	}
	~undirectedGraph()
	{

	}

    int location(VertexData x) 
	{	
		int k;
		for(k = 0; vertex[k]!= x; k++);  
	  	return k;  
	}
	void initial()
	{
		for(int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		for(int i = 0; i < n; i++)
		{
			dfn[i] = 0;
		}
		count = 1;
	}
	void createGraph()
	{
		cout << "图由同目录下的graph.txt文件输入……" << endl;
		//cout << "请输入图的顶点数和边数：";
		fcin >> n >> e;
		//cout << "请输入各个顶点的名称：";
		for(int i = 0; i < n; i++)
		{
			fcin >> vertex[i];
			verlist[i].vertex = vertex[i];
			verlist[i].firstedge = NULL;
		}
		//cout << "请输入各边以及其权值：";
		for(int j = 0; j < e; j++)
		{
			VertexData v1, v2;
			int weight, m, n;
			fcin >> v1 >> v2 >> weight;
			m = location(v1);
			n = location(v2);
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
		printAdjacencyMatrix();
		printAdjacencyList();
	}
	void printAdjacencyMatrix()
	{
		cout << "----------------------------------" << endl;
		cout << "该无向图的邻接矩阵为：" << endl;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << edge[i][j] << " ";
			}
			cout << endl;
		}
		cout << "----------------------------------" << endl;
	}
	void printAdjacencyList()
	{
		cout << "----------------------------------" << endl;
		cout << "该无向图的邻接表为：" << endl;
		for(int i = 0; i < n; i++)
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
	void traversal()
	{
		DFSTraverse();
		BFSTraverse();
	}
	void DFSTraverse()
	{
		cout << "----------------------------------" << endl;
		cout << "深度优先搜索遍历结果为：" << endl;
		initial();
		cout << "用邻接矩阵遍历：";
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				DFS1(i);
			}
		}
		cout << endl;
		cout << "用邻接矩阵遍历的各顶点编号：";
		for(int i = 0; i < n; i++)
		{
			cout << dfn[i] << " ";
		}
		cout << endl;
		initial();
		cout << "用邻接表遍历：  ";
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				DFS2(i);
			}
		}
		cout << endl;
		cout << "用邻接表遍历的各顶点编号：";
		for(int i = 0; i < n; i++)
		{
			cout << dfn[i] << " ";
		}
		cout << endl;
		cout << "----------------------------------" << endl;
	}
	void DFS2(int i)
	{
		EdgeNode *p;
		cout << verlist[i].vertex << " "; 
		visited[i] = true;
		dfn[i] = count++;
		p = verlist[i].firstedge;
		while(p)
		{
			if(!visited[p->adjvex])
			{
				DFS2(p->adjvex);
			}
			p = p->next;
		}
	}
	void DFS1(int i)
	{
		cout << vertex[i] << " ";
		visited[i] = true;
		dfn[i] = count++;
		for(int j = 0; j < n; j++)
		{
			if(edge[i][j] != 0 && (!visited[i]))
			{
				DFS1(j);
			}
		}
	}
	void BFSTraverse()
	{
		cout << "----------------------------------" << endl;
		cout << "广度优先搜索遍历结果为：" << endl;
		initial();
		cout << "用邻接矩阵遍历：";
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				BFS1(i);
			}
		}
		cout << endl;
		cout << "用邻接矩阵遍历的各顶点编号：";
		for(int i = 0; i < n; i++)
		{
			cout << dfn[i] << " ";
		}
		cout << endl;
		initial();
		cout << "用邻接表遍历：  ";
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				BFS2(i);
			}
		}
		cout << endl;
		cout << "用邻接表遍历的各顶点编号：";
		for(int i = 0; i < n; i++)
		{
			cout << dfn[i] << " ";
		}
		cout << endl;
		cout << "----------------------------------" << endl;
	}
	void BFS2(int i)
	{
		EdgeNode *p;
		queue<int> Q;
		cout << verlist[i].vertex << " ";
		visited[i] = true;
		dfn[i] = count++;
		Q.EnQueue(i);
		while(!Q.Empty())
		{
			i = Q.Front();
			Q.OutQueue();
			p = verlist[i].firstedge;
			while(p)
			{
				if(!visited[p->adjvex])
				{
					cout << verlist[p->adjvex].vertex << " ";
					visited[p->adjvex] = true;
					dfn[p->adjvex] = count++;
					Q.EnQueue(p->adjvex);
				}
				p = p->next;
			}
		}
	}
	void BFS1(int i)
	{
		queue<int> Q;
		cout << verlist[i].vertex << " ";
		visited[i] = true;
		dfn[i] = count++;
		Q.EnQueue(i);
		while(!Q.Empty())
		{
			i = Q.Front();
			Q.OutQueue();
			for(int j = 0; j < n; j++)
			{
				if(edge[i][j] != 0 && (!visited[j]))
				{
					cout << verlist[j].vertex << " ";
					visited[j] = true;
					dfn[j] = count++;
					Q.EnQueue(j);
				}
			}
		}
	}


	void DFStree(int i, TreeNode *T)
	{
		bool first = true;
		visited[i] = true;
		TreeNode *p = new TreeNode;
		TreeNode *q = new TreeNode;
		EdgeNode *w = new EdgeNode;
		for(w = verlist[i].firstedge; w != NULL; p = p->next)
		{
			if(!visited[w->adjvex])
			{
				p->data = verlist[w->adjvex].vertex;
				p->lchild = NULL;
				p->rbrother = NULL;
				if(first)
				{
					T->lchild = p;
					first = false;
				}
				else
				{
					q->rbrother = p;
				}
				q = p;
				DFStree(w->adjvex, q);
			}
		}
	}
	void DFSforest(TreeNode *T)
	{
		TreeNode *p = new TreeNode;
		TreeNode *q = new TreeNode;
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				p->data = verlist[i].vertex;
				p->lchild = NULL;
				p->rbrother = NULL;
				if(!T)
				{
					T = p;
				}
				else
				{
					q->rbrother = p;
				}
				q = p;
				DFStree(i, p);
			}
		}
	}


private:
	//文件操作
	ifstream fcin;

	//使用邻接表存储时所需的变量
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

	//遍历时所需的变量
	bool visited[max]; 
	int dfn[max]; 
	int count;
};

#endif