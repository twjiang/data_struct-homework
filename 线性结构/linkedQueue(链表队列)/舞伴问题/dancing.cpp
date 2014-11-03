#include <iostream>
#include "linkedQueue.h"

using namespace std;

int main()
{
	linkedQueue<char> men;
	linkedQueue<char> women;
	
	int n1, n2, n3, n, temp1, temp2;
	char _char;
	
	cout << "请输入男舞伴队伍人数：";
	cin >> temp1;
	n1 = temp1;
	cout << "请输入男舞伴队伍（大写字母表示）：";
	while(temp1--)
	{
		cin >> _char;
		men.enQueue(_char);
	}
	cout << "请输入女舞伴队伍人数：";
	cin >> temp2;
	n2 = temp2;
	cout << "请输入女舞伴队伍（小写字母表示）：";
	while(temp2--)
	{
		cin >> _char;
		women.enQueue(_char);
	}
	cout << "请输入舞曲数量：";
	cin >> n3;
	
	if(n1 <= n2)
		n = n1 * n3;
	else
		n = n2 * n3;
	while(n--)
	{
		cout << men.getFront();
		cout << women.getFront();
		cout << " ";
		men.enQueue(men.getFront());
		women.enQueue(women.getFront());
		men.outQueue();
		women.outQueue();
	}
}