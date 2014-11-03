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
		int col_num[MaxSize];
		int position[MaxSize];
		int temp;
		/*if(tu)
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
		}*/
		if(tu)
        {
            for(int i = 0; i < tu; i++)    //原矩阵每列元素个数
            {
                col_num[data[i].j]++;
            }
            /*计算转置后每列首个元素所在位置*/
            position[0]=0;
            for(int i = 1; i < nu; i++)
            {
                position[i] = position[i-1] + col_num[i-1];
            }
            for(int i = 0; i < tu; i++)               //转置
            {
                temp = position[data[i].j];
                trpodata[temp].j = data[i].i;
                trpodata[temp].i = data[i].j;
                trpodata[temp].v = data[i].v;
                position[data[i].j]++;
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