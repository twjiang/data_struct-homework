#ifndef tripleMatrix_H_INCLUDED
#define tripleMatrix_H_INCLUDED
#define MaxSize 10000
#include <iostream>

using namespace std;

template <typename ElemType>
class tripleMatrix
{
private:
	struct triple
	{
		int i, j;
		ElemType v;
	};
	triple data[MaxSize + 1];
	triple trpodata[MaxSize + 1];
	int mu, nu, tu;
public:
	tripleMatrix()
	{
		mu = 0;
		nu = 0;
		tu = 0;
	}
	void createMatrix(int m, int n, int t)
	{
		mu = m;
		nu = n;
		tu = t;
		cout << "please input the triples:" << endl;
		for(int c = 0; c < tu; c++)
		{
			cin >> data[c].i >> data[c].j >> data[c].v;
		}
		cout << endl;
	}
	void transpose()
	{
		int q,col,p;
		int m = nu; 
		int n = mu; 
		int t = tu;
		if(tu)
		{
			q = 0;
			for(col = 0; col < m; col++)
			{
				for(p = 0; p < t; p++)
				{
				    if(data[p].j == col)
				    {
					   trpodata[q].i = data[p].j;
					   trpodata[q].j = data[p].i;
					   trpodata[q].v = data[p].v;
					   q++;
				    }
				}   
			}	
		}
		cout << "after transpose:" << endl;
		for(int s = 0; s < t; s++)
		{
			cout << trpodata[s].i << " " <<
				trpodata[s].j << " " << trpodata[s].v << endl;
		}
	}
	
};



#endif 