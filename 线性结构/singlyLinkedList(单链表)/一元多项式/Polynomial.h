#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#include <iostream>

using namespace std;

struct polynode
{
	int coef;
	int exp;
	polynode *link;
};
typedef polynode *polypointer;

class Polynomial
{
public:
	Polynomial()
	{
		pt = new polynode;
	}

	polypointer End()
	{
		polypointer p;
		p = pt;
		while(p->link != NULL)
			p = p->link;
		return p;
	}

	void Insert(int c, int e)
	{
		polypointer p;
		p = new polynode;
		End()->link = p;
		p->coef = c;
		p->exp = e;
		p->link = NULL;
	}

	polypointer Attach(int c, int e, polypointer d)
	{
		polypointer x;
		x = new polynode;
		x->coef = c;
		x->exp = e;
		d->link = x;
		return x;
	}

	void PolyAdd(Polynomial &poly)
	{
		polypointer p, q, d, c;
		int y;
		p = pt->link;
		q = poly.pt->link;
		c = new polynode;
		d = c;
		while((p != NULL) && (q != NULL))
		{
			switch(Compare(p->exp, q->exp))
			{
				case '=':
					y = p->coef + q->coef;
					if(y)
						d = Attach(y, p->exp, d);
					p = p->link;
					q = q->link;
					break;
				case '>':
					d = Attach(p->coef, p->exp, d);
					p = p->link;
					break;
				case '<':
					d = Attach(q->coef, q->exp, d);
					q = q->link;
					break;
			}
		}
		while(p != NULL)
		{
			d = Attach(p->coef, p->exp, d);
			p = p->link;
		}
		while(q != NULL)
		{
			d = Attach(q->coef, q->exp, d);
			q = q->link;			
		}
		d->link = NULL;
		pt = c;
	}	

	char Compare(int a, int b)
	{
		if(a == b)
			return '=';
		if(a > b)
			return '>';
		if(a < b)
			return '<';
	}

	void Print()
	{
		polypointer q;
		q = pt->link;
		while(q != NULL)
		{
			cout << q->coef << "x^" << q->exp << " ";
			q = q->link;			
		}
		cout << endl;
	}

private:
	polypointer pt;
};

#endif